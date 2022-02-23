/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file box3dt.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include <math.h>
#include "box3dt.h"


/*!
 * \brief Default constructor.
 */
Box3DT::Box3DT()
{
    empty();
}


/*!
 * \brief Destructor. Releases allocated resources.
 */
void Box3DT::destroy()
{
    empty();
}


/*!
 * \brief Sets default boundary points.
 */
void Box3DT::empty()
{
    p0.set(DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX);
    p1.set(-DBL_MAX, -DBL_MAX, -DBL_MAX, -DBL_MAX);
}


/*!
 * \brief Tests the lengths of the box.
 * \return True, if each edge length of the box is greater or equal to zero.
 */
bool Box3DT::isEmpty()
{
    return (p1.x < p0.x) || (p1.y < p0.y) || (p1.z < p0.z) || (p1.t < p0.t);
}


/*!
 * \brief Sets the box boundaries to a given point.
 * \param point Pointer to a source point.
 */
void Box3DT::set(Point3DT *point)
{
    p0.x = p1.x = point->x;
    p0.y = p1.y = point->y;
    p0.z = p1.z = point->z;
    p0.t = p1.t = point->t;
}


/*!
 * \brief Sets the box boundaries from a given box.
 * \param box Pointer to a source box.
 */
void Box3DT::set(Box3DT *box)
{
    p0 = box->p0;
    p1 = box->p1;
}


/*!
 * \brief Sets the box boundaries to a given box.
 * \param x0 Minimum x-coordinate.
 * \param y0 Minimum y-coordinate.
 * \param z0 Minimum z-coordinate.
 * \param t0 Minimum t-coordinate.
 * \param x1 Maximum x-coordinate.
 * \param y1 Maximum y-coordinate.
 * \param z1 Maximum z-coordinate.
 * \param t1 Maximum t-coordinate.
 */
void Box3DT::set(double x0, double y0, double z0, double t0, double x1, double y1, double z1, double t1)
{
    p0.set(x0, y0, z0, t0);
    p1.set(x1, y1, z1, t1);
}


/*!
 * \brief Sets the box by its center coordinates and half-edge length.
 * \param centerX x-coordinate of the box center.
 * \param centerY y-coordinate of the box center.
 * \param centerZ z-coordinate of the box center.
 * \param centerT t-coordinate of the box center.
 * \param halfSize 1/2 length of box edges.
 */
void Box3DT::set(double centerX, double centerY, double centerZ, double centerT, double halfSize)
{
    p0.set(centerX - halfSize, centerY - halfSize, centerZ - halfSize, centerT - halfSize);
    p1.set(centerX + halfSize, centerY + halfSize, centerZ + halfSize, centerT + halfSize);
}


/*!
 * \brief Returns the length of of x-edge (width).
 * \return Length of x-edge.
 */
double Box3DT::getLengthX()
{
    return abs(p1.x - p0.x);
}


/*!
 * \brief Returns the length of of y-edge (depth).
 * \return Length of y-edge.
 */
double Box3DT::getLengthY()
{
    return abs(p1.y - p0.y);
}


/*!
 * \brief Returns the length of of z-edge (height).
 * \return Length of y-edge.
 */
double Box3DT::getLengthZ()
{
    return abs(p1.z - p0.z);
}


/*!
 * \brief Returns the length of of t-edge.
 * \return Length of y-edge.
 */
double Box3DT::getLengthT()
{
    return abs(p1.t - p0.t);
}


/*!
 * \brief Calculates and returns the box center.
 * \return Point object representing the box center.
 */
Point3DT Box3DT::getCenter()
{
    Point3DT c;
    c.set((p0.x + p1.x) / 2.0, (p0.y + p1.y) / 2.0, (p0.z + p1.z) / 2.0, (p0.t + p1.t) / 2.0);
    return c;
}


/*!
 * \brief Moves the box center to a given point.
 * \param x x-coordinate of a new box center.
 * \param y y-coordinate of a new box center.
 * \param z z-coordinate of a new box center.
 * \param t t-coordinate of a new box center.
 */
void Box3DT::setCenter(double x, double y, double z, double t)
{
    double dx = getLengthX() / 2.0;
    double dy = getLengthY() / 2.0;
    double dz = getLengthZ() / 2.0;
    double dt = abs(p1.t - p0.t) / 2.0;
    p0.set(x - dx, y - dy, z - dz, t - dt);
    p1.set(x + dx, y + dy, z + dz, t + dt);
}


/*!
 * \brief Moves the box center to a given point.
 * \param center Pointer to a new center of the box.
 */
void Box3DT::setCenter(Point3DT *center)
{
    setCenter(center->x, center->y, center->z, center->t);
}


/*!
 * \brief Scales the size of the box by a given factor.
 * \param scale Scale factor.
 */
void Box3DT::scale(double scale)
{
    Point3DT c;

    c = getCenter();
    double dx = scale*(getLengthX() / 2.0);
    double dy = scale*(getLengthY() / 2.0);
    double dz = scale*(getLengthZ() / 2.0);
    double dt = scale*(getLengthT() / 2.0);
    p0.set(c.x - dx, c.y - dy, c.z - dz, c.t - dt);
    p1.set(c.x + dx, c.y + dy, c.z + dz, c.t + dt);
}


/*!
 * \brief Moves the x and y boundaries in each direction by given shifts.
 * \param dx Shift of x-boundaries.
 * \param dy Shift of y-boundaries.
 */
void Box3DT::extend(double dx, double dy)
{
    p0.x -= dx;
    p0.y -= dy;
    p1.x += dx;
    p1.y += dy;
}


/*!
 * \brief Moves the x, y, and z boundaries in each direction by given shifts.
 * \param dx Shift of x-boundaries.
 * \param dy Shift of y-boundaries.
 * \param dz Shift of z-boundaries.
 */
void Box3DT::extend(double dx, double dy, double dz)
{
    extend(dx, dy);
    p0.z -= dz;
    p1.z += dz;
}


/*!
 * \brief Moves the box boundaries in each direction by given shifts.
 * \param dx Shift of x-boundaries.
 * \param dy Shift of y-boundaries.
 * \param dz Shift of z-boundaries.
 * \param dt Shift of t-boundaries.
 */
void Box3DT::extend(double dx, double dy, double dz, double dt)
{
    extend(dx, dy, dz);
    p0.t -= dt;
    p1.t += dt;
}


/*!
 * \brief Tests whether a given 2D point is inside the box.
 * \param x x-coordinate of a point.
 * \param y y-coordinate of a point.
 * \return True, if the box contains a given 2D point.
 */
bool Box3DT::contains(double x, double y)
{
    return ((p0.x <= x) && (x <= p1.x) && (p0.y <= y) && (y <= p1.y));
}


/*!
 * \brief Tests whether a given 3D point is inside the box.
 * \param x x-coordinate of a point.
 * \param y y-coordinate of a point.
 * \param z z-coordinate of a point.
 * \return True, if the box contains a given 3D point.
 */
bool Box3DT::contains(double x, double y, double z)
{
    return ((p0.x <= x) && (x <= p1.x) && (p0.y <= y) && (y <= p1.y) && (p0.z <= z) && (z <= p1.z));
}


/*!
 * \brief Tests whether a given 3DT point is inside the box.
 * \param x x-coordinate of a point.
 * \param y y-coordinate of a point.
 * \param z z-coordinate of a point.
 * \param t t-coordinate of a point.
 * \return True, if the box contains a given 3DT point.
 */
bool Box3DT::contains(double x, double y, double z, double t)
{
    return ((p0.x <= x) && (x <= p1.x) && (p0.y <= y) && (y <= p1.y) && (p0.z <= z) && (z <= p1.z) && (p0.t <= t) && (t <= p1.t));
}


/*!
 * \brief Tests whether a given 3DT point is inside the box.
 * \param point Pointer to a 3DT point.
 * \return True, if the box contains a given 3DT point.
 */
bool Box3DT::contains(Point3DT *point)
{
    return contains(point->x, point->y, point->z, point->t);
}


/*!
 * \brief Tests whether the box contains another box.
 * \param point Pointer to a box object.
 * \return True, if the box contains a given box.
 */
bool Box3DT::contains(Box3DT *box)
{
    return contains(&box->p0) && contains(&box->p1);
}


/*!
 * \brief Tests whether boxes overlaps (there is non-empty intersection).
 * \param box Pointer to a box object.
 * \return True, if boxes overlaps.
 */
bool Box3DT::overlaps(Box3DT *box)
{
    return ((p0.x <= box->p1.x) && (box->p0.x <= p1.x) && (p0.y <= box->p1.y) && (box->p0.y <= p1.y) && (p0.z <= box->p1.z) && (box->p0.z <= p1.z) && (p0.t <= box->p1.t) && (box->p0.t <= p1.t));
}


/*!
 * \brief Tests whether boxes overlaps in 3D (there is non-empty 3D intersection).
 * \param box Pointer to a box object.
 * \return True, if boxes overlaps.
 */
bool Box3DT::overlaps3D(Box3DT *box)
{
    return ((p0.x <= box->p1.x) && (box->p0.x <= p1.x) && (p0.y <= box->p1.y) && (box->p0.y <= p1.y) && (p0.z <= box->p1.z) && (box->p0.z <= p1.z));
}


/*!
 * \brief Tests whether boxes overlaps in 2D (there is non-empty 2D intersection).
 * \param box Pointer to a box object.
 * \return True, if boxes overlaps.
 */
bool Box3DT::overlaps2D(Box3DT *box)
{
    return ((p0.x <= box->p1.x) && (box->p0.x <= p1.x) && (p0.y <= box->p1.y) && (box->p0.y <= p1.y));
}


/*!
 * \brief Calculates and returns the full 3DT intersection of boxes.
 * \param box Pointer to a box object.
 * \return Box representing intersection of the box with a given box.
 */
Box3DT Box3DT::intersection(Box3DT *box)
{
    Box3DT ovr;

    ovr.p0.x = (p0.x < box->p0.x) ? box->p0.x : p0.x;
    ovr.p0.y = (p0.y < box->p0.y) ? box->p0.y : p0.y;
    ovr.p0.z = (p0.z < box->p0.z) ? box->p0.z : p0.z;
    ovr.p0.t = (p0.t < box->p0.t) ? box->p0.t : p0.t;
    ovr.p1.x = (p1.x < box->p1.x) ? p1.x : box->p1.x;
    ovr.p1.y = (p1.y < box->p1.y) ? p1.y : box->p1.y;
    ovr.p1.z = (p1.z < box->p1.z) ? p1.z : box->p1.z;
    ovr.p1.t = (p1.t < box->p1.t) ? p1.t : box->p1.t;
    return ovr;
}


/*!
 * \brief Enlarges the box to include a 2D point.
 * \param x Input point x-coordinate.
 * \param x Input point y-coordinate.
 */
void Box3DT::include(double x, double y)
{
    if (x < p0.x) p0.x = x;
    if (y < p0.y) p0.y = y;
    if (x > p1.x) p1.x = x;
    if (y > p1.y) p1.y = y;
}


/*!
 * \brief Enlarges the box to include a 3D point.
 * \param x Input point x-coordinate.
 * \param x Input point y-coordinate.
 * \param z Input point z-coordinate.
 */
void Box3DT::include(double x, double y, double z)
{
    include(x, y);
    if (z < p0.z) p0.z = z;
    if (z > p1.z) p1.z = z;
}


/*!
 * \brief Enlarges the box to include a 3DT point.
 * \param x Input point x-coordinate.
 * \param x Input point y-coordinate.
 * \param z Input point z-coordinate.
 * \param t Input point t-coordinate.
 */
void Box3DT::include(double x, double y, double z, double t)
{
    include(x, y, z);
    if ( t < p0.t ) p0.t = t;
    if ( t > p1.t ) p1.t = t;
}


/*!
 * \brief Enlarges the box to include a 3D point.
 * \param point Pointer to 3D point.
 */
void Box3DT::include(Point3D *point)
{
    include(point->x, point->y, point->z);
}


/*!
 * \brief Enlarges the box to include a 3DT point.
 * \param point Pointer to 3DT point.
 */
void Box3DT::include(Point3DT *point)
{
    include(point->x, point->y, point->z, point->t);
}


/*!
 * \brief Enlarges the box to include a 3DT box.
 * \param point Pointer to 3DT box.
 */
void Box3DT::include(Box3DT *box)
{
    include(&box->p0);
    include(&box->p1);
}


/*!
 * \brief Calculates maximal edge length in 3D.
 * \return Maximal edge length in 3D.
 */
double Box3DT::getMaxLength3D()
{
    double dx, dy, dz;

    dx = abs(p1.x - p0.x);
    dy = abs(p1.y - p0.y);
    dz = abs(p1.z - p0.z);
    if (dx < dy) dx = dy;
    if (dx < dz) dx = dz;

    return dx;
}


/*!
 * \brief Calculates maximal edge length (in 3DT).
 * \return Maximal edge length (in 3DT).
 */
double Box3DT::getMaxLength()
{
    double d, dt;

    d = getMaxLength3D();
    dt = abs(p1.t - p0.t);
    if ( d < dt ) d = dt;

    return d;
}


/*!
 * \brief Calculates minimal edge length in 3D.
 * \return Minimal edge length in 3D.
 */
double Box3DT::getMinLength3D()
{
    double dx, dy, dz;

    dx = abs(p1.x - p0.x);
    dy = abs(p1.y - p0.y);
    dz = abs(p1.z - p0.z);
    if (dy < dx) dx = dy;
    if (dz < dx) dx = dz;

    return dx;
}


/*!
 * \brief Calculates minimal edge length (in 3DT).
 * \return Minimal edge length (in 3DT).
 */
double Box3DT::getMinLength()
{
    double d, dt;

    d = getMinLength3D();
    dt = abs(p1.t - p0.t);
    if (dt < d) d = dt;
    return d;
}


/*!
 * \brief Moves the box by a given vector.
 * \param tx Shift in the x-direction.
 * \param ty Shift in the y-direction.
 * \param tz Shift in the z-direction.
 */
void Box3DT::translate(double tx, double ty, double tz)
{
    p0.x += tx;
    p0.y += ty;
    p0.z += tz;
    p1.x += tx;
    p1.y += ty;
    p1.z += tz;
}


/*!
 * \brief Converts the box to a Json object.
 * \return Json object.
 */
QJsonObject Box3DT::toJson()
{
    QJsonObject qobj;

    qobj.insert("type", static_cast<QString>("Box3DT"));
    qobj.insert("p0", p0.toJson());
    qobj.insert("p1", p1.toJson());

    return qobj;
}


/*!
 * \brief Setups the 3DT box from a Json object.
 * \param jsonVal Json value object.
 * \return True, if box was sucessufully loaded.
 */
bool Box3DT::fromJson(QJsonValue jsonVal)
{
    p0.fromJson(jsonVal["p0"]);
    p1.fromJson(jsonVal["p1"]);
    return true;
}
