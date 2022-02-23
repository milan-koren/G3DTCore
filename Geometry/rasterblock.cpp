/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file rasterblock.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "rasterblock.h"


/*!
 * \brief Default constructor.
 */
RasterBlock::RasterBlock()
{
    empty();
}


/*!
 * \brief Invalidates the raster block.
 */
void RasterBlock::empty()
{
    col0 = row0 = lay0 = INT64_MAX;
    col1 = row1 = lay1 = INT64_MIN;
    band0 = tick0 = 0;
    band1 = tick1 = 0;
    numberOfNotNullCells = 0;
}


/*!
 * \brief Sets the boundaries of the raster block.
 * \param col0 Minimum column index.
 * \param row0 Minimum row index.
 * \param lay0 Minimum layer index.
 * \param band0 Minimum band index.
 * \param tick0 Minimum tick index.
 * \param col1 Maximum column index.
 * \param row1 Maximum row index.
 * \param lay1 Maximum layer index.
 * \param band1 Maximum band index.
 * \param tick1 Maximum tick index.
 */
void RasterBlock::set(qint64 col0, qint64 row0, qint64 lay0, qint64 band0, qint64 tick0, qint64 col1, qint64 row1, qint64 lay1, qint64 band1, qint64 tick1)
{
    this->col0 = col0;
    this->row0 = row0;
    this->lay0 = lay0;
    this->band0 = band0;
    this->tick0 = tick0;
    this->col1 = col1;
    this->row1 = row1;
    this->lay1 = lay1;
    this->band1 = band1;
    this->tick1 = tick1;
}


/*!
 * \brief Enlarges the raster block to include a given cell.
 * \param col Column index.
 * \param row Row index.
 * \param lay Layer index.
 * \param band Band index.
 * \param tick Tick index.
 */
void RasterBlock::include(qint64 col, qint64 row, qint64 lay, qint64 band, qint64 tick)
{
    if (col < col0) col0 = col;
    if (col1 < col) col1 = col;
    if (row < row0) row0 = row;
    if (row1 < row) row1 = row;
    if (lay < lay0) lay0 = lay;
    if (lay1 < lay) lay1 = lay;
    if (band < band0) band0 = band;
    if (band1 < band) band1 = band;
    if (tick < tick0) tick0 = tick;
    if (tick1 < tick) tick1 = tick;
}


/*!
 * \brief Checks the size of the raster block.
 * \return True, if raster block is valid.
 */
bool RasterBlock::isValid()
{
    return (col1 < col0) || (row1 < row0) || (lay1 < lay0) || (band1 < band0) || (tick1 < tick0);
}


/*!
 * \brief Calculates the total number of raster block cells.
 * \return Number of raster block cells.
 */
qint64 RasterBlock::getNumberOfCells()
{
    qint64 n;
    n = (col1 - col0 + 1) * (row1 - row0 + 1) * (lay1 - lay0 + 1) * (band1 - band0 + 1) * (tick1 - tick0 + 1);
    if (n < 0) return 0;
    return n;
}


/*!
 * \brief Calculates the percentage of not null cells in the raster block.
 * \return Percentage of not null cells in the raster block.
 */
double RasterBlock::getPercentageOfNotNullCells()
{
    qint64 nCells;

    nCells = getNumberOfCells();
    if (0 < nCells)
        return 100.0 * double(numberOfNotNullCells) / double(nCells);
    return 0.0;
}


/*!
 * \return Returns the number of raster block columns.
 */
qint64 RasterBlock::getNumberOfColumns()
{
    if (col1 < col0) return 0;
    return col1 - col0 + 1;
}


/*!
 * \return Returns the number of raster block rows.
 */
qint64 RasterBlock::getNumberOfRows()
{
    if (row1 < row0) return 0;
    return row1 - row0 + 1;
}


/*!
 * \return Returns the number of raster block layers.
 */
qint64 RasterBlock::getNumberOfLayers()
{
    if (lay1 < lay0) return 0;
    return lay1 - lay0 + 1;
}


/*!
 * \return Returns the number of raster block bands.
 */
qint64 RasterBlock::getNumberOfBands()
{
    if (band1 < band0) return 0;
    return band1 - band0 + 1;
}


/*!
 * \return Returns the number of raster block ticks.
 */
qint64 RasterBlock::getNumberOfTicks()
{
    if (tick1 < tick0) return 0;
    return tick1 - tick0 + 1;
}


/*!
 * \brief Tests whether the raster block conatins a 2D cell with given indexes.
 * \param iCol Column index.
 * \param iRow Row index.
 */
inline bool RasterBlock::contains(qint64 iCol, qint64 iRow)
{
    return (col0 <= iCol) && (iCol <= col1) && (row0 <= iRow) && (iRow <= row1);
}


/*!
 * \brief Tests whether the raster block conatins a 3D cell with given indexes.
 * \param iCol Column index.
 * \param iRow Row index.
 * \param iLay Layer index.
 */
inline bool RasterBlock::contains(qint64 iCol, qint64 iRow, qint64 iLay)
{
    return (col0 <= iCol) && (iCol <= col1) && (row0 <= iRow) && (iRow <= row1) && (lay0 <= iLay) && (iLay <= lay1);
}
