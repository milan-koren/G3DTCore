#ifndef POINT2D_H
#define POINT2D_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file point2d.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"


class G3DTCORE_EXPORT Point2D
{
public:
    double x;
    double y;

public:
    Point2D();
    Point2D(double x, double y);
    Point2D(const Point2D &point);
    virtual ~Point2D();
    Point2D &operator=(const Point2D &point);

    void set(double x, double y);

    virtual QJsonObject toJson();
    virtual bool fromJson(QJsonValue jsonVal);
};

#endif // POINT2D_H
