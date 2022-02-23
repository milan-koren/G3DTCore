#ifndef INDEX3DT_H
#define INDEX3DT_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file index3dt.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"
#include "index3d.h"

class G3DTCORE_EXPORT Index3DT : public Index3D
{
public:
    qint64 tick;

public:
    Index3DT();
    Index3DT(const Index3DT &index);
    Index3DT(qint64 col, qint64 row, qint64 lay, qint64 band, qint64 tick);
    ~Index3DT() override;
    Index3DT &operator=(const Index3DT index);

    void invalidate() override;
    bool isValid() override;
    void set(qint64 col, qint64 row, qint64 lay, qint64 band, qint64 tick);

    QJsonObject toJson() override;
    bool fromJson(QJsonValue jsonVal) override;
};

#endif // INDEX3DT_H
