#ifndef RASTERSIZE2D_H
#define RASTERSIZE2D_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file rastersize2d.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"


class G3DTCORE_EXPORT RasterSize2D
{
public:
    qint64 nBands;
    qint64 nCols;
    qint64 nRows;

public:
    RasterSize2D();
    RasterSize2D(qint64 nCols, qint64 nRows, qint64 nBands);
    RasterSize2D(const RasterSize2D &size);
    virtual ~RasterSize2D();
    RasterSize2D &operator=(const RasterSize2D &size);

    void set(qint64 nCols, qint64 nRows, qint64 nBands);
    qint64 getNumberOfCells2D();
    virtual qint64 getNumberOfCells();

    virtual QJsonObject toJson();
    virtual bool fromJson(QJsonValue jsonVal);
};

#endif // RASTERSIZE2D_H
