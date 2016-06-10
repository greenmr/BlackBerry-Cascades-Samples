/*
 * SystemDialogTrxHlp.hpp
 *
 *  Created on: June 3rd, 2016
 *      Author: Martin R. Green
 */

#ifndef SYSTEMDIALOGTRXHLP_HPP_
#define SYSTEMDIALOGTRXHLP_HPP_

#include <bb/system/SystemDialog>

using namespace bb::system;

class SystemDialogTrxHlp : public QObject {
    Q_OBJECT

    SystemDialog* _dialog;

public:
    SystemDialogTrxHlp( SystemDialog* dialog );

public slots:
    void setBody( const QString& text );
    void setRememberMeText( const QString& text );
    void setTitle( const QString& title );
};

#endif /* SYSTEMDIALOGTRXHLP_HPP_ */
