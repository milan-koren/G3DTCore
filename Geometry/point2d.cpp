/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file point2d.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "point2d.h"


/*!
 * \brief Default constructor.
 */
Point2D::Point2D()
{
    set(0, 0);
}


/*!
 * \brief Construct the 2D point from given coordinates.
 * \param x Point x-coordinate.
 * \param y Point y-coordinate.
 */
Point2D::Point2D(double x, double y)
{
    set(x, y);
}


/*!
 * \brief Copy constructor.
 * \param point Reference to a source point.
 */
Point2D::Point2D(const Point2D &point)
{
    set(point.x, point.y);
}


/*!
 * \brief Virtual destructor.
 */
Point2D::~Point2D()
{
}


/*!
 * \brief Assignment operator.
 * \param point Reference to a source point.
 * \return
 */
Point2D &Point2D::operator=(const Point2D &point)
{
    set(point.x, point.y);
    return *this;
}


/*!
 * \brief Sets the coordinates of the point.
 * \param x New x-coordinate.
 * \param y New y-coordinate.
 */
inline void Point2D::set(double x, double y)
{
    this->x = x;
    this->y = y;
}


/*!
 * \brief Converts the 2D point to a Json object.
 * \return Json object.
 */
QJsonObject Point2D::toJson()
{
    QJsonObject qobj;

    qobj.insert("type", static_cast<QString>("Point2D"));
    qobj.insert("x", static_cast<double>(x));
    qobj.insert("y", static_cast<double>(y));

    return qobj;
}


/*!
 * \brief Setups the 2D point from a Json object.
 * \param jsonVal Json value object.
 * \return True, if the 2D point was sucessufully loaded.
 */
bool Point2D::fromJson(QJsonValue jsonVal)
{
    x = jsonVal["x"].toDouble();
    y = jsonVal["y"].toDouble();
    return true;
}
