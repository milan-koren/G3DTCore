#ifndef INDEX2D_H
#define INDEX2D_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file index2d.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"


class G3DTCORE_EXPORT Index2D
{
public:
    qint64 col;
    qint64 row;
    qint64 band;

public:
    Index2D();
    Index2D(const Index2D &index);
    Index2D(qint64 col, qint64 row, qint64 band);
    virtual ~Index2D();
    Index2D &operator=(const Index2D &index);

    virtual void invalidate();
    virtual bool isValid();
    void set(qint64 col, qint64 row, qint64 band);

    virtual QJsonObject toJson();
    virtual bool fromJson(QJsonValue jsonVal);
};

#endif // INDEX2D_H
