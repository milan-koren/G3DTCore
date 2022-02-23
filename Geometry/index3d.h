#ifndef INDEX3D_H
#define INDEX3D_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file index3d.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"
#include "index2d.h"


class G3DTCORE_EXPORT Index3D : public Index2D
{
public:
    qint64 lay;

public:
    Index3D();
    Index3D(const Index3D &index);
    Index3D(qint64 col, qint64 row, qint64 lay, qint64 band);
    ~Index3D() override;
    Index3D &operator=(const Index3D &index);

    void invalidate() override;
    bool isValid() override;
    void set(qint64 col, qint64 row, qint64 lay, qint64 band);

    QJsonObject toJson() override;
    bool fromJson(QJsonValue jsonVal) override;
};

#endif // INDEX3D_H
