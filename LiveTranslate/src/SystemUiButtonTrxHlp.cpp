/*
 * SystemUiButtonTrxHlp.cpp
 *
 *  Created on: June 3rd, 2016
 *      Author: Martin R. Green
 */

#include "SystemUiButtonTrxHlp.hpp"

SystemUiButtonTrxHlp::SystemUiButtonTrxHlp( SystemUiButton* button ) :
        QObject( button ) {
    this->_button = button;
}

void SystemUiButtonTrxHlp::setLabel( const QString& label ) {
    this->_button->setLabel( label );
}
