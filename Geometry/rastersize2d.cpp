/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file rastersize2d.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "rastersize2d.h"


/*!
 * \brief Default constructor.
 */
RasterSize2D::RasterSize2D()
{
    set(0, 0, 0);
}

/*!
 * \brief Constructs the object.
 * \param nCols Number of columns.
 * \param nRows Number of rows.
 * \param nBands Number of bands.
 */
RasterSize2D::RasterSize2D(qint64 nCols, qint64 nRows, qint64 nBands)
{
    set(nCols, nRows, nBands);
}


/*!
 * \brief Copy constructor.
 * \param size Reference to a source 2D raster size.
 */
RasterSize2D::RasterSize2D(const RasterSize2D &size)
{
    set(size.nCols, size.nRows, size.nBands);
}


/*!
 * \brief Virtual destructor.
 */
RasterSize2D::~RasterSize2D()
{
}


/*!
 * \brief Assignment operator.
 * \param size Reference to a source size.
 * \return Reference to the object.
 */
RasterSize2D &RasterSize2D::operator=(const RasterSize2D &size)
{
    set(size.nCols, size.nRows, size.nBands);
    return *this;
}


/*!
 * \brief Setup the 2D raster size.
 * \param nCols Number of columns.
 * \param nRows Number of rows.
 * \param nBands Number of bands.
 */
void RasterSize2D::set(qint64 nCols, qint64 nRows, qint64 nBands)
{
    this->nCols = nCols;
    this->nRows = nRows;
    this->nBands = nBands;
}


/*!
 * \return Layer size in cells.
 */
inline qint64 RasterSize2D::getNumberOfCells2D()
{
    return this->nCols * this->nRows * this->nBands;
}


/*!
 * \return Total number of cells in raster.
 */
inline qint64 RasterSize2D::getNumberOfCells()
{
    return getNumberOfCells2D();
}


/*!
 * \brief Converts the 2D raster size to a Json object.
 * \return Json object.
 */
QJsonObject RasterSize2D::toJson()
{
    QJsonObject qobj;

    qobj.insert("type", static_cast<QString>("RasterSize2D"));
    qobj.insert("nCols", static_cast<double>(nCols));
    qobj.insert("nRows", static_cast<double>(nRows));
    qobj.insert("nBands", static_cast<double>(nBands));

    return qobj;
}


/*!
 * \brief Setups the 2D raster size from a Json object.
 * \param jsonVal Json value object.
 * \return True, if the 2D raster size was sucessufully loaded.
 */
bool RasterSize2D::fromJson(QJsonValue jsonVal)
{
    nCols = qint64(jsonVal["nCols"].toDouble());
    nRows = qint64(jsonVal["nRows"].toDouble());
    nBands = qint64(jsonVal["nBands"].toDouble());
    return true;
}
