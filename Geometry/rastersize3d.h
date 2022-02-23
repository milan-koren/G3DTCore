#ifndef RASTERSIZE3D_H
#define RASTERSIZE3D_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file rastersize3d.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"
#include "rastersize2d.h"


class G3DTCORE_EXPORT RasterSize3D : public RasterSize2D
{
public:
    qint64 nLays;

public:
    RasterSize3D();
    RasterSize3D(const RasterSize3D &size);
    RasterSize3D(qint64 nCols, qint64 nRows, qint64 nLays, qint64 nBands);
    ~RasterSize3D() override;
    RasterSize3D &operator=(const RasterSize3D &size);

    void set(qint64 nCols, qint64 nRows, qint64 nLays, qint64 nBands);
    qint64 getNumberOfCells3D();
    qint64 getNumberOfCells() override;

    QJsonObject toJson() override;
    bool fromJson(QJsonValue jsonVal) override;
};

#endif // RASTERSIZE3D_H
