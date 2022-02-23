/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file g3dtworker.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtworker.h"


G3DTWorker::G3DTWorker(QObject *parent) : QThread(parent)
{
    this->dtStarted = QDateTime::currentDateTime();
    this->dtFinished = QDateTime::currentDateTime();
}

QString G3DTWorker::processingTimeToString()
{
    qint64 ms;
    qint64 h, m;
    double s;

    if (this->isRunning())
    {
        ms = QDateTime::currentMSecsSinceEpoch() - this->dtStarted.toMSecsSinceEpoch();
    }
    else
    {
        ms = this->dtFinished.toMSecsSinceEpoch() - this->dtStarted.toMSecsSinceEpoch();
    }

    h = ms / (60 * 60 * 1000);
    ms = ms % (60 * 60 * 1000);
    m = ms / (60 * 1000);
    ms = ms % (60 * 1000);
    s = double(ms) / 1000.0;

    return QString("%0:%1:%2").arg(h).arg(m, 2, 10, QLatin1Char('0')).arg(s, 4, 'f', 1, QLatin1Char('0'));
}

double G3DTWorker::processingTimeInSeconds()
{
    if (this->isRunning())
    {
        return double(QDateTime::currentMSecsSinceEpoch() - this->dtStarted.toMSecsSinceEpoch())/1000.0;
    }
    else
    {
        return double(this->dtFinished.toMSecsSinceEpoch() - this->dtStarted.toMSecsSinceEpoch())/1000.0;
    }
}

double G3DTWorker::processingTimeInMinutes()
{
    if (this->isRunning())
    {
        return double(QDateTime::currentSecsSinceEpoch() - this->dtStarted.toSecsSinceEpoch())/60.0;
    }
    else
    {
        return double(this->dtFinished.toSecsSinceEpoch() - this->dtStarted.toSecsSinceEpoch())/60.0;
    }
}

void G3DTWorker::run()
{
    this->dtStarted = QDateTime::currentDateTime();
    doWork();
    this->dtFinished = QDateTime::currentDateTime();
}

void G3DTWorker::doWork()
{
}
