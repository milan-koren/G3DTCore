#ifndef BOX2D_H
#define BOX2D_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file box2d.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"
#include "point2d.h"


class G3DTCORE_EXPORT Box2D
{
public:
    Point2D p0; //!< lower-left point
    Point2D p1; //!< upper-right point

public:
    Box2D();

    void destroy();
    void empty();
    bool isEmpty();

    void set(Point2D *point);
    void set(Box2D *box);

    double getLengthX();
    double getLengthY();

    Point2D getCenter();
    void setCenter(double x, double y);
    void setCenter(Point2D *center);

    void scale(double scale);
    void extend(double dx, double dy);

    bool contains(double x, double y);
    bool contains(Point2D *point);
    bool contains(Box2D *box);

    bool overlaps(Box2D *box);
    Box2D intersection(Box2D *box);

    void include(double x, double y);
    void include(Point2D *point);
    void include(Box2D *box);
    void includeCircle(double radius);

    QJsonObject toJson();
    bool fromJson(QJsonValue jsonVal);
};

#endif // BOX2D_H
