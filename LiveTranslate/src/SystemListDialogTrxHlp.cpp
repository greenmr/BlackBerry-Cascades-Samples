/*
 * SystemListDialogTranslateHelper.cpp
 *
 *  Created on: June 3rd, 2016
 *      Author: Martin R. Green
 */

#include "SystemListDialogTrxHlp.hpp"

SystemListDialogTrxHlp::SystemListDialogTrxHlp( SystemListDialog* dialog ) :
        QObject( dialog ) {
    this->_dialog = dialog;
}

void SystemListDialogTrxHlp::setTitle( const QString& title ) {
    this->_dialog->setTitle( title );
}

#ifndef _BUILDFOR_10_0_
void SystemListDialogTrxHlp::setRememberMeText( const QString& text ) {
	// ---This function didn't exist in API 10.0
    this->_dialog->setRememberMeText( text );
}
#endif
