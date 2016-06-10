/*
 * SystemUIButtonTrxHlp.hpp
 *
 *  Created on: June 3rd, 2016
 *      Author: Martin R. Green
 */

#ifndef SYSTEMUIBUTTONTRXHLP_HPP_
#define SYSTEMUIBUTTONTRXHLP_HPP_

#include <bb/system/SystemUiButton>

using namespace bb::system;

class SystemUiButtonTrxHlp: public QObject {
    Q_OBJECT

    SystemUiButton* _button;
public:
    SystemUiButtonTrxHlp( SystemUiButton* button );

public slots:
    void setLabel( const QString& label );
};

#endif /* SYSTEMUIBUTTONTRXHLP_HPP_ */
