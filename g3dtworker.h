#ifndef G3DTWORKER_H
#define G3DTWORKER_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file g3dtworker.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include <QThread>
#include "g3dtcore_global.h"


class G3DTCORE_EXPORT G3DTWorker : public QThread
{
    Q_OBJECT

public:
    QDateTime dtStarted;
    QDateTime dtFinished;

public:
    G3DTWorker(QObject *parent = nullptr);

    double processingTimeInSeconds();
    double processingTimeInMinutes();
    QString processingTimeToString();

    void run() override;
    virtual void doWork();

Q_SIGNALS:
    void showMessage(QString msg);
    void showPercentage(int perc);
};

#endif // G3DTWORKER_H
