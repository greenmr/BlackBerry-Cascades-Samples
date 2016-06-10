/*
 * SystemProgressDialogTrxHlp.hpp
 *
 *  Created on: June 3rd, 2016
 *      Author: Martin R. Green
 */

#ifndef SYSTEMPROGRESSDIALOGTRXHLP_HPP_
#define SYSTEMPROGRESSDIALOGTRXHLP_HPP_

#include <bb/system/SystemProgressDialog>

using namespace bb::system;

class SystemProgressDialogTrxHlp : public QObject {
    Q_OBJECT

    SystemProgressDialog* _dialog;

public:
    SystemProgressDialogTrxHlp( SystemProgressDialog* dialog );

public slots:
    void setBody( const QString& text );
    void setRememberMeText( const QString& text );
    void setTitle( const QString& title );
};

#endif /* SYSTEMPROGRESSDIALOGTRXHLP_HPP_ */
