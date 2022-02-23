/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file box2d.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "box2d.h"


/*!
 * \brief Default constructor.
 */
Box2D::Box2D()
{
    empty();
}


/*!
 * \brief Destructor. Releases allocated resources.
 */
void Box2D::destroy()
{
    empty();
}


/*!
 * \brief Sets default boundary points.
 */
void Box2D::empty()
{
    p0.set(DBL_MAX, DBL_MAX);
    p1.set(-DBL_MAX, -DBL_MAX);
}


/*!
 * \brief Tests the lengths of the box.
 * \return True, if each edge length of the box is greater or equal to zero.
 */
bool Box2D::isEmpty()
{
    return (p1.x < p0.x) || (p1.y < p0.y);
}


/*!
 * \brief Sets the box boundaries to a given point.
 * \param point Pointer to a source point.
 */
void Box2D::set(Point2D *point)
{
    p0.x = p1.x = point->x;
    p0.y = p1.y = point->y;
}


/*!
 * \brief Sets the box boundaries from a given box.
 * \param box Pointer to a source box.
 */
void Box2D::set(Box2D *box)
{
    p0 = box->p0;
    p1 = box->p1;
}


/*!
 * \brief Returns the length of of x-edge (width).
 * \return Length of x-edge.
 */
double Box2D::getLengthX()
{
    return abs(p1.x - p0.x);
}


/*!
 * \brief Returns the length of of y-edge (depth).
 * \return Length of y-edge.
 */
double Box2D::getLengthY()
{
    return abs(p1.y - p0.y);
}


/*!
 * \brief Returns the center of a box.
 * \return Point representing the box center.
 */
Point2D Box2D::getCenter()
{
    Point2D center;

    center.set((p0.x + p1.x) / 2.0, (p0.y + p1.y) / 2.0);

    return center;
}


/*!
 * \brief Moves the box center to a given point.
 * \param x New x-coordinate of the box center.
 * \param x New y-coordinate of the box center.
 */
void Box2D::setCenter(double x, double y)
{
    double dx = getLengthX() / 2.0;
    double dy = getLengthY() / 2.0;
    p0.set(x - dx, y - dy);
    p1.set(x + dx, y + dy);
}


/*!
 * \brief Moves the box to a given point.
 * \param center Pointer to a new center of the box.
 */
void Box2D::setCenter(Point2D *center)
{
    setCenter(center->x, center->y);
}


/*!
 * \brief Scales the box size by a given factor.
 * \param scale Scale factor.
 */
void Box2D::scale(double scale)
{
    Point2D center;

    center = getCenter();
    double dx = scale*(getLengthX() / 2.0);
    double dy = scale*(getLengthY() / 2.0);

    p0.set(center.x - dx, center.y - dy);
    p1.set(center.x + dx, center.y + dy);
}


/*!
 * \brief Moves the box boundaries in each direction by given shifts.
 * \param dx Shift of x-boundaries.
 * \param dy Shift of y-boundaries.
 */
void Box2D::extend(double dx, double dy)
{
    p0.x -= dx;
    p0.y -= dy;
    p1.x += dx;
    p1.y += dy;
}


/*!
 * \brief Tests whether a given point is inside the box.
 * \param x x-coordinate of a point.
 * \param y y-coordinate of a point.
 * \return True, if the box contains a given point.
 */
bool Box2D::contains(double x, double y)
{
    return ((p0.x <= x) & (x <= p1.x) & (p0.y <= y) & (y <= p1.y));
}


/*!
 * \brief Tests whether a given point is inside the box.
 * \param point Point object.
 * \return True, if the box contains a given point.
 */
bool Box2D::contains(Point2D *point)
{
    return contains(point->x, point->y);
}


/*!
 * \brief Tests whether the box contains another box.
 * \param box Pointer to a box object.
 * \return True, if the box contains a given box.
 */
bool Box2D::contains(Box2D *box)
{
    return contains(&box->p0) && contains(&box->p1);
}


/*!
 * \brief Tests whether boxes overlaps (there is non empty intersection).
 * \param box Pointer to a box object.
 * \return True, if boxes overlaps.
 */
bool Box2D::overlaps(Box2D *box)
{
    return ((p0.x <= box->p1.x) & (box->p0.x <= p1.x) & (p0.y <= box->p1.y) & (box->p0. y<= p1.y));
}


/*!
 * \brief Calculates the intersection of boxes.
 * \param box Pointer to a box object.
 * \return Box representing intersection of the box with a given box.
 */
Box2D Box2D::intersection(Box2D *box)
{
    Box2D ovr;

    ovr.p0.x = (p0.x < box->p0.x) ? box->p0.x : p0.x;
    ovr.p0.y = (p0.y < box->p0.y) ? box->p0.y : p0.y;
    ovr.p1.x = (p1.x < box->p1.x) ? p1.x : box->p1.x;
    ovr.p1.y = (p1.y < box->p1.y) ? p1.y : box->p1.y;

    return ovr;
}


/*!
 * \brief Enlarges the box to include a point with given coordinates.
 * \param x Input point x-coordinate.
 * \param x Input point y-coordinate.
 */
void Box2D::include(double x, double y)
{
    if (x < p0.x) p0.x = x;
    if (y < p0.y) p0.y = y;
    if (x > p1.x) p1.x = x;
    if (y > p1.y) p1.y = y;
}


/*!
 * \brief Enlarges the box to include a given point.
 * \param box Input point object.
 */
void Box2D::include(Point2D *point)
{
    include(point->x, point->y);
}


/*!
 * \brief Enlarges a box to include a gicven box.
 * \param box Input box object.
 */
void Box2D::include(Box2D *box)
{
    include(&box->p0);
    include(&box->p1);
}


/*!
 * \brief Enlarges a box to includes the circle of a given radius.
 * \param radius Circle radius.
 */
void Box2D::includeCircle(double radius)
{
    Point2D center;

    if (0.0 < radius)
    {
        center = getCenter();
        include(center.x - radius, center.y - radius);
        include(center.y + radius, center.y + radius);
    }
}


/*!
 * \brief Converts the box to a Json object.
 * \return Json object.
 */
QJsonObject Box2D::toJson()
{
    QJsonObject qobj;

    qobj.insert("type", static_cast<QString>("Box2D"));
    qobj.insert("p0", p0.toJson());
    qobj.insert("p1", p1.toJson());

    return qobj;
}


/*!
 * \brief Setups the 2D box from a Json object.
 * \param jsonVal Json value object.
 * \return True, if box was sucessufully loaded.
 */
bool Box2D::fromJson(QJsonValue jsonVal)
{
    p0.fromJson(jsonVal["p0"]);
    p1.fromJson(jsonVal["p1"]);
    return true;
}
