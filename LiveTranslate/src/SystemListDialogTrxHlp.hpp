/*
 * SystemListDialogTrxHelper.hpp
 *
 *  Created on: June 3rd, 2016
 *      Author: Martin R. Green
 */

#ifndef SYSTEMLISTDIALOGTRXHLP_HPP_
#define SYSTEMLISTDIALOGTRXHLP_HPP_

#include <bb/system/SystemListDialog>

// ---Uncomment following line if building for 10.0 API
//#define _BUILDFOR_10_0_

using namespace bb::system;

class SystemListDialogTrxHlp : public QObject {
    Q_OBJECT

    SystemListDialog* _dialog;

public:
    SystemListDialogTrxHlp( SystemListDialog* dialog );

public slots:
    void setTitle( const QString& title );
#ifndef _BUILDFOR_10_0_
    void setRememberMeText( const QString& text );
#endif
};

#endif /* SYSTEMLISTDIALOGTRXHLP_HPP_ */
