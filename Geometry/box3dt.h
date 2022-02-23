#ifndef BOX3DT_H
#define BOX3DT_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file box3dt.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"
#include "point3dt.h"


class G3DTCORE_EXPORT Box3DT
{
public:
    Point3DT p0; //!< lower-left point
    Point3DT p1; //!< upper-right point

public:
    Box3DT();

    void destroy();
    void empty();
    bool isEmpty();

    QJsonObject toJson();
    bool fromJson(QJsonValue jsonVal);

    void set(Point3DT *point);
    void set(Box3DT *box);
    void set(double x0, double y0, double z0, double t0, double x1, double y1, double z1, double t1);
    void set(double centerX, double centerY, double centerZ, double centerT, double halfSize);

    double getLengthX();
    double getLengthY();
    double getLengthZ();
    double getLengthT();

    Point3DT getCenter();

    void setCenter(double x, double y, double z, double t);
    void setCenter(Point3DT *center);

    void scale(double scale);

    void extend(double dx, double dy);
    void extend(double dx, double dy, double dz);
    void extend(double dx, double dy, double dz, double dt);

    bool contains(double x, double y);
    bool contains(double x, double y, double z);
    bool contains(double x, double y, double z, double t);
    bool contains(Point3DT *point);
    bool contains(Box3DT *box);

    bool overlaps(Box3DT *box);
    bool overlaps2D(Box3DT *box);
    bool overlaps3D(Box3DT *box);

    Box3DT intersection(Box3DT *box);

    void include(double x, double y);
    void include(double x, double y, double z);
    void include(double x, double y, double z, double t);
    void include(Point3D *point);
    void include(Point3DT *point);
    void include(Box3DT *box);

    double getMaxLength3D();
    double getMaxLength();
    double getMinLength3D();
    double getMinLength();

    void translate(double tx, double ty, double tz);
};

#endif // BOX3DT_H
