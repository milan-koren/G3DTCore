/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file rastersize3d.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "rastersize3d.h"


/*!
 * \brief Default constructor.
 */
RasterSize3D::RasterSize3D()
{
    this->nLays = 0;
}


/*!
 * \brief Copy constructor.
 * \param size Reference to a source 3D raster size.
 */
RasterSize3D::RasterSize3D(const RasterSize3D &size)
{
    set(size.nCols, size.nRows, size.nLays, size.nBands);
}


/*!
 * \brief Constructs and initializes the 3D raster size.
 * \param nCols Number of columns.
 * \param nRows Number of rows.
 * \param nLays Number of layers.
 * \param nBands Number of bands.
 */
RasterSize3D::RasterSize3D(qint64 nCols, qint64 nRows, qint64 nLays, qint64 nBands) : RasterSize2D(nCols, nRows, nBands)
{
    this->nLays = nLays;
}


/*!
 * \brief Virtual destructor.
 */
RasterSize3D::~RasterSize3D()
{
}


/*!
 * \brief Assignment operator.
 * \param size Reference to a source size.
 * \return Reference to the object.
 */
RasterSize3D &RasterSize3D::operator=(const RasterSize3D &size)
{
    set(size.nCols, size.nRows, size.nLays, size.nBands);
    return *this;
}


/*!
 * \brief Setup the 3D raster size.
 * \param nCols Number of columns.
 * \param nRows Number of rows.
 * \param nLays Number of layers.
 * \param nBands Number of bands.
 */
void RasterSize3D::set(qint64 nCols, qint64 nRows, qint64 nLays, qint64 nBands)
{
    RasterSize2D::set(nCols, nRows, nBands);
    this->nLays = nLays;
}


/*!
 * \return Number of cells in 3D raster.
 */
inline qint64 RasterSize3D::getNumberOfCells3D()
{
    return this->nCols * this->nRows * this->nLays * this->nBands;
}


/*!
 * \return Total number of cells in raster.
 */
inline qint64 RasterSize3D::getNumberOfCells()
{
    return getNumberOfCells3D();
}


/*!
 * \brief Converts the 3D raster size to a Json object.
 * \return Json object.
 */
QJsonObject RasterSize3D::toJson()
{
    QJsonObject qobj;

    qobj.insert("type", static_cast<QString>("RasterSize3D"));
    qobj.insert("nCols", static_cast<double>(nCols));
    qobj.insert("nRows", static_cast<double>(nRows));
    qobj.insert("nLays", static_cast<double>(nLays));
    qobj.insert("nBands", static_cast<double>(nBands));

    return qobj;
}


/*!
 * \brief Setups the 3D raster size from a Json object.
 * \param jsonVal Json value object.
 * \return True, if the 3D raster size was sucessufully loaded.
 */
bool RasterSize3D::fromJson(QJsonValue jsonVal)
{
    if (RasterSize2D::fromJson(jsonVal))
    {
        nLays = qint64(jsonVal["nLays"].toDouble());
        return true;
    }
    return false;
}
