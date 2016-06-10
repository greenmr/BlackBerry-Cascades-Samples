/*
 * Translator.hpp
 *
 *  Created on: June 3rd, 2016
 *      Author: Martin R. Green
 */

#ifndef LIVETRANSLATOR_HPP_
#define LIVETRANSLATOR_HPP_

#include <bb/cascades/LocaleHandler>

using namespace bb::cascades;

class LiveTranslator: public QObject {
    Q_OBJECT

    QString _key;
    QString _context;

    static LocaleHandler* _localeHandler;

public:
    LiveTranslator( const QString& context, const QString& key, QObject* target, const char* slot );
    static void setLocaleHandler( LocaleHandler* localeHandler );
    static LocaleHandler* localeHandler();

private slots:
    void localeOrLanguageChangedHandler();

signals:
    void translate( const QString& string );
};

#endif /* LIVETRANSLATOR_HPP_ */
