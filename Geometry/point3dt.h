#ifndef POINT3DT_H
#define POINT3DT_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file point3dt.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"
#include "point3d.h"


class G3DTCORE_EXPORT Point3DT : public Point3D
{
public:
    double t;

public:
    Point3DT();
    Point3DT(double x, double y, double z, double t);
    Point3DT(const Point3DT &point);
    ~Point3DT() override;
    Point3DT &operator=(const Point3DT &point);

    void set(double x, double y, double z, double t);

    QJsonObject toJson() override;
    bool fromJson(QJsonValue jsonVal) override;
};

#endif // POINT3DT_H
