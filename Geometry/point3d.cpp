/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file point3d.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "point3d.h"


/*!
 * \brief Default constructor.
 */
Point3D::Point3D()
{
    z = 0.0;
}


/*!
 * \brief Construct the 3D point from given coordinates.
 * \param x Point x-coordinate.
 * \param y Point y-coordinate.
 * \param z Point z-coordinate.
 */
Point3D::Point3D(double x, double y, double z) : Point2D(x, y)
{
    this->z = z;
}


/*!
 * \brief Copy constructor.
 * \param point Reference to a source point.
 */
Point3D::Point3D(const Point3D &point)
{
    set(point.x, point.y, point.z);
}


/*!
 * \brief Virtual destructor.
 */
Point3D::~Point3D()
{
}


/*!
 * \brief Assignment operator.
 * \param point Reference to a source point.
 * \return Reference to the point.
 */
Point3D &Point3D::operator=(const Point3D &point)
{
    set(point.x, point.y, point.z);
    return *this;
}


/*!
 * \brief Sets the coordinates of the point.
 * \param x New x-coordinate.
 * \param y New y-coordinate.
 * \param z New z-coordinate.
 */
inline void Point3D::set(double x, double y, double z)
{
    Point2D::set(x, y);
    this->z = z;
}


/*!
 * \brief Converts the 3D point to a Json object.
 * \return Json object.
 */
QJsonObject Point3D::toJson()
{
    QJsonObject qobj;

    qobj.insert("type", static_cast<QString>("Point3D"));
    qobj.insert("x", static_cast<double>(x));
    qobj.insert("y", static_cast<double>(y));
    qobj.insert("z", static_cast<double>(z));

    return qobj;
}


/*!
 * \brief Setups the 3D point from a Json object.
 * \param jsonVal Json value object.
 * \return True, if the 3D point was sucessufully loaded.
 */
bool Point3D::fromJson(QJsonValue jsonVal)
{
    if (Point2D::fromJson(jsonVal))
    {
        z = jsonVal["z"].toDouble();
        return true;
    }
    return false;
}
