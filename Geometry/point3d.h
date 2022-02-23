#ifndef POINT3D_H
#define POINT3D_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file point3d.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"
#include "point2d.h"


class G3DTCORE_EXPORT Point3D : public Point2D
{
public:
    double z;

public:
    Point3D();
    Point3D(double x, double y, double z);
    Point3D(const Point3D &point);
    ~Point3D() override;
    Point3D &operator=(const Point3D &point);

    void set(double x, double y, double z);

    QJsonObject toJson() override;
    bool fromJson(QJsonValue jsonVal) override;
};

#endif // POINT3D_H
