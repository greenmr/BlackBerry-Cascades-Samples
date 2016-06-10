/*
 * SystemDialogTrxHlp.cpp
 *
 *  Created on: June 3rd, 2016
 *      Author: Martin R. Green
 */

#include "SystemDialogTrxHlp.hpp"

SystemDialogTrxHlp::SystemDialogTrxHlp( SystemDialog* dialog ) :
        QObject( dialog ) {
    this->_dialog = dialog;
}

void SystemDialogTrxHlp::setBody( const QString& title ) {
    this->_dialog->setBody( title );
}

void SystemDialogTrxHlp::setRememberMeText( const QString& text ) {
    this->_dialog->setRememberMeText( text );
}

void SystemDialogTrxHlp::setTitle( const QString& title ) {
    this->_dialog->setTitle( title );
}
