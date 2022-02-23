/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file point3dt.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "point3dt.h"


/*!
 * \brief Default constructor.
 */
Point3DT::Point3DT()
{
    t = 0.0;
}


/*!
 * \brief Construct the 3DT point from given coordinates.
 * \param x Point x-coordinate.
 * \param y Point y-coordinate.
 * \param z Point z-coordinate.
 * \param z Point t-coordinate.
 */
Point3DT::Point3DT(double x, double y, double z, double t) : Point3D(x, y, z)
{
    this->t = t;
}


/*!
 * \brief Copy constructor.
 * \param point Reference to a source point.
 */
Point3DT::Point3DT(const Point3DT &point)
{
    set(point.x, point.y, point.z, point.t);
}


/*!
 * \brief Virtual destructor.
 */
Point3DT::~Point3DT()
{
}


/*!
 * \brief Assignment operator.
 * \param point Reference to a source point.
 * \return Reference to the point.
 */
Point3DT &Point3DT::operator=(const Point3DT &point)
{
    set(point.x, point.y, point.z, point.t);
    return *this;
}


/*!
 * \brief Sets the coordinates of the point.
 * \param x New x-coordinate.
 * \param y New y-coordinate.
 * \param z New z-coordinate.
 * \param z New t-coordinate.
 */
void Point3DT::set(double x, double y, double z, double t)
{
    Point3D::set(x, y, z);
    this->t = t;
}


/*!
 * \brief Converts the 3DT point to a Json object.
 * \return Json object.
 */
QJsonObject Point3DT::toJson()
{
    QJsonObject qobj;

    qobj.insert("type", static_cast<QString>("Point3DT"));
    qobj.insert("x", static_cast<double>(x));
    qobj.insert("y", static_cast<double>(y));
    qobj.insert("z", static_cast<double>(z));
    qobj.insert("t", static_cast<double>(t));

    return qobj;
}


/*!
 * \brief Setups the 3DT point from a Json object.
 * \param jsonVal Json value object.
 * \return True, if the 3DT point was sucessufully loaded.
 */
bool Point3DT::fromJson(QJsonValue jsonVal)
{
    if (Point3D::fromJson(jsonVal))
    {
        t = jsonVal["t"].toDouble();
        return true;
    }
    return false;
}
