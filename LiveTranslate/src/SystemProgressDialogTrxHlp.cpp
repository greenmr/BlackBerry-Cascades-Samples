/*
 * SystemProgressDialogTrxHlp.cpp
 *
 *  Created on: June 3rd, 2016
 *      Author: Martin R. Green
 */

#include "SystemProgressDialogTrxHlp.hpp"

SystemProgressDialogTrxHlp::SystemProgressDialogTrxHlp( SystemProgressDialog* dialog ) :
        QObject( dialog ) {
    this->_dialog = dialog;
}

void SystemProgressDialogTrxHlp::setBody( const QString& title ) {
    this->_dialog->setBody( title );
}

void SystemProgressDialogTrxHlp::setRememberMeText( const QString& text ) {
    this->_dialog->setRememberMeText( text );
}

void SystemProgressDialogTrxHlp::setTitle( const QString& title ) {
    this->_dialog->setTitle( title );
}
