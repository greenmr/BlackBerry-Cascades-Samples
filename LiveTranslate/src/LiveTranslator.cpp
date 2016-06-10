/*
 * LiveTranslator.cpp
 *
 *  Created on: June 3rd, 2016
 *      Author: Martin R. Green
 */

#include "LiveTranslator.hpp"

// ---Initialize the locale handler pointer on app startup so we can tell if it has been set properly later
LocaleHandler* LiveTranslator::_localeHandler = 0;

// ---Note that the target control is also used as the parent so the live translator dies when the control does
LiveTranslator::LiveTranslator( const QString& context, const QString& key, QObject* target, const char* slot ) :
        QObject( target ) {

    bool success;
    Q_UNUSED( success );

    // ---Save the context and key string
    this->_key = key;
    this->_context = context;

    // ---Die (during debug) if the locale handler hasn't been set properly before use
    Q_ASSERT( LiveTranslator::_localeHandler );

    // ---Watch for locale or language changes
    success = QObject::connect( LiveTranslator::_localeHandler, SIGNAL( localeOrLanguageChanged() ), SLOT( localeOrLanguageChangedHandler() ) );
    Q_ASSERT( success );

    // ---Trigger specified slot when locale or language changes
    success = QObject::connect( this, SIGNAL( translate( const QString& ) ), target, slot );
    Q_ASSERT( success );
}

void LiveTranslator::localeOrLanguageChangedHandler() {
    // ---Use the specified slot on the target to update the appropriate string attribute with the translated key
    emit translate( QCoreApplication::translate( this->_context.toLocal8Bit().constData(), this->_key.toLocal8Bit().constData() ) );
}

// ---This function MUST be called once with a valid LocaleHandler before any LiveTranslator classes are instantiated
void LiveTranslator::setLocaleHandler( LocaleHandler* localeHandler ) {
    LiveTranslator::_localeHandler = localeHandler;
}

LocaleHandler* LiveTranslator::localeHandler() {
    return LiveTranslator::_localeHandler;
}
