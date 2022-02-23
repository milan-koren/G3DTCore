#ifndef RASTERSIZE3DT_H
#define RASTERSIZE3DT_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file rastersize3dt.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"
#include "rastersize3d.h"


class G3DTCORE_EXPORT RasterSize3DT : public RasterSize3D
{
public:
    qint64 nTicks;

public:
    RasterSize3DT();
    RasterSize3DT(qint64 nCols, qint64 nRows, qint64 nLays, qint64 nBands, qint64 nTicks);
    RasterSize3DT(const RasterSize3DT &size);
    ~RasterSize3DT() override;
    RasterSize3DT &operator=(const RasterSize3DT &size);

    void set(qint64 nCols, qint64 nRows, qint64 nLays, qint64 nBands, qint64 nTicks);
    qint64 getNumberOfCells4D();
    qint64 getNumberOfCells() override;

    QJsonObject toJson() override;
    bool fromJson(QJsonValue jsonVal) override;
};

#endif // RASTERSIZE3DT_H
