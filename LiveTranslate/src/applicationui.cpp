/*
 * Copyright (c) 2011-2015 BlackBerry Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>
#include <bb/cascades/Page>
#include <bb/cascades/Container>
#include <bb/cascades/Label>
#include <bb/cascades/SystemDefaults>
#include <bb/cascades/DockLayout>
#include <bb/cascades/Button>
#include <bb/system/SystemDialog>

#include "LiveTranslator.hpp"
#include "SystemDialogTrxHlp.hpp"

using namespace bb::cascades;

ApplicationUI::ApplicationUI() :
        QObject() {
    // prepare the localization
    m_pTranslator = new QTranslator( this );
    m_pLocaleHandler = new LocaleHandler( this );

    bool res = QObject::connect( m_pLocaleHandler, SIGNAL( systemLanguageChanged() ), this, SLOT( onSystemLanguageChanged() ) );
    // This is only available in Debug builds
    Q_ASSERT( res );
    // Since the variable is not used in the app, this is added to avoid a
    // compiler warning
    Q_UNUSED( res );

    // initial load
    onSystemLanguageChanged();

    // ---No QML, only C++
    Label* label = Label::create().text( tr( "Hello" ) ).horizontal( HorizontalAlignment::Center ).textStyle( SystemDefaults::TextStyles::bigText() );
    Button* button = Button::create().text( tr( "Click" ) ).horizontal( HorizontalAlignment::Center ).vertical( VerticalAlignment::Center ).onClicked( this, SLOT( onButtonClicked() ) );
    Page* rootPage = Page::create().content( Container::create().layout( new DockLayout() ).add( label ).add( button ) );

    // ---Add live translation
    LiveTranslator::setLocaleHandler( m_pLocaleHandler );
    new LiveTranslator( "ApplicationUI", "Hello", label, SLOT( setText(const QString&) ) );
    new LiveTranslator( "ApplicationUI", "Click", button, SLOT( setText(const QString&) ) );

    // Set created root object as the application scene
    Application::instance()->setScene( rootPage );
}

void ApplicationUI::onSystemLanguageChanged() {
    QCoreApplication::instance()->removeTranslator( m_pTranslator );
    // Initiate, load and install the application translation files.
    QString locale_string = QLocale().name();
    QString file_name = QString( "LiveTranslate_%1" ).arg( locale_string );
    if ( m_pTranslator->load( file_name, "app/native/qm" ) ) {
        QCoreApplication::instance()->installTranslator( m_pTranslator );
    }
}

void ApplicationUI::onButtonClicked() {
    bool success;
    Q_UNUSED( success )

    // ---No need to use tr() or setup LiveTranslator for the confirm button since Cascades live translates "Confirm" natively
    SystemDialog* dialog = new SystemDialog( "Confirm" );
    dialog->setTitle( tr( "Testing" ) );
    dialog->setBody( tr( "Hello" ) );

    // ---Enable live translation for the dialog
    new LiveTranslator( "ApplicationUI", "Testing", new SystemDialogTrxHlp( dialog ), SLOT( setTitle(const QString&) ) );
    new LiveTranslator( "ApplicationUI", "Hello", new SystemDialogTrxHlp( dialog ), SLOT( setBody(const QString&) ) );

    // ---This only works for API 10.2 and higher!!!
    success = QObject::connect( LiveTranslator::localeHandler(), SIGNAL( localeOrLanguageChanged() ), dialog, SLOT( update() ) );
    Q_ASSERT( success );

    // ---Let the dialog destroy itself when the button is clicked, we don't care about the result
    success = QObject::connect( dialog, SIGNAL( finished(bb::system::SystemUiResult::Type) ), SLOT( dialogFinishedHandler(bb::system::SystemUiResult::Type) ) );
    Q_ASSERT( success );

    dialog->show();
}

void ApplicationUI::dialogFinishedHandler( bb::system::SystemUiResult::Type value ) {
    Q_UNUSED( value );
    sender()->deleteLater();
}
