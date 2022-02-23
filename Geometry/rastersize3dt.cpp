/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file rastersize3dt.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "rastersize3dt.h"


/*!
 * \brief Default constructor.
 */
RasterSize3DT::RasterSize3DT()
{
    this->nTicks = 0;
}


/*!
 * \brief Constructs and initializes the 3DT raster size.
 * \param nCols Number of columns.
 * \param nRows Number of rows.
 * \param nLays Number of layers.
 * \param nBands Number of bands.
 * \param nTicks Number of ticks.
 */
RasterSize3DT::RasterSize3DT(qint64 nCols, qint64 nRows, qint64 nLays, qint64 nBands, qint64 nTicks)
               : RasterSize3D(nCols, nRows, nLays, nBands)
{
    this->nTicks = nTicks;
}


/*!
 * \brief Copy constructor.
 * \param size Reference to a source 3D raster size.
 */
RasterSize3DT::RasterSize3DT(const RasterSize3DT &size)
{
    set(size.nCols, size.nRows, size.nLays, size.nBands, size.nTicks);
}


/*!
 * \brief Virtual destructor.
 */
RasterSize3DT::~RasterSize3DT()
{
}


/*!
 * \brief Assignment operator.
 * \param size Reference to a source size.
 * \return Reference to the object.
 */
RasterSize3DT &RasterSize3DT::operator=(const RasterSize3DT &size)
{
    set(size.nCols, size.nRows, size.nLays, size.nBands, size.nTicks);
    return *this;
}


/*!
 * \brief Setup the 3DT raster size.
 * \param nCols Number of columns.
 * \param nRows Number of rows.
 * \param nLays Number of layers.
 * \param nBands Number of bands.
 * \param nTicks Number of ticks.
 */
void RasterSize3DT::set(qint64 nCols, qint64 nRows, qint64 nLays, qint64 nBands, qint64 nTicks)
{
    RasterSize3D::set(nCols, nRows, nLays, nBands);
    this->nTicks = nTicks;
}


/*!
 * \return Number of cells in 4D raster.
 */
inline qint64 RasterSize3DT::getNumberOfCells4D()
{
    return this->nCols * this->nRows * this->nLays * this->nBands * this->nTicks;
}


/*!
 * \return Total number of cells in raster.
 */
inline qint64 RasterSize3DT::getNumberOfCells()
{
    return getNumberOfCells4D();
}


/*!
 * \brief Converts the 3DT raster size to a Json object.
 * \return Json object.
 */
QJsonObject RasterSize3DT::toJson()
{
    QJsonObject qobj;

    qobj.insert("type", static_cast<QString>("RasterSize3DT"));
    qobj.insert("nCols", static_cast<double>(nCols));
    qobj.insert("nRows", static_cast<double>(nRows));
    qobj.insert("nLays", static_cast<double>(nLays));
    qobj.insert("nBands", static_cast<double>(nBands));
    qobj.insert("nTicks", static_cast<double>(nTicks));

    return qobj;
}


/*!
 * \brief Setups the 3DT raster size from a Json object.
 * \param jsonVal Json value object.
 * \return True, if the 3DT raster size was sucessufully loaded.
 */
bool RasterSize3DT::fromJson(QJsonValue jsonVal)
{
    if (RasterSize3D::fromJson(jsonVal))
    {
        nTicks = qint64(jsonVal["nTicks"].toDouble());
        return true;
    }
    return false;
}
