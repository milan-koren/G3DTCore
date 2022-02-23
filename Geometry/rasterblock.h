#ifndef RASTERBLOCK_H
#define RASTERBLOCK_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file rasterblock.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "g3dtcore_global.h"


/*!
 * \brief The RasterBlock represents a block of cells inside a raster.
 *         The block of cell is defined by minimum and maximum cell indexes (boundaries).
 */
class G3DTCORE_EXPORT RasterBlock
{
public:
    qint64 col0, col1; //!< minimum and maximum column index of the block
    qint64 row0, row1; //!< minimum and maximum row index of the block
    qint64 lay0, lay1; //!< minimum and maximum layer index of the block
    qint64 band0, band1; //!< minimum and maximum band index of the block
    qint64 tick0, tick1; //!< minimum and maximum tick index of the block
    qint64 numberOfNotNullCells; //!< number of not null cells in the block

public:
    RasterBlock();

    void empty();
    void set(qint64 col0, qint64 row0, qint64 lay0, qint64 band0, qint64 tick0, qint64 col1, qint64 row1, qint64 lay1, qint64 band1, qint64 tick1);
    void include(qint64 col, qint64 row, qint64 lay, qint64 band, qint64 tick);
    bool isValid();
    qint64 getNumberOfCells();
    double getPercentageOfNotNullCells();
    qint64 getNumberOfColumns();
    qint64 getNumberOfRows();
    qint64 getNumberOfLayers();
    qint64 getNumberOfBands();
    qint64 getNumberOfTicks();
    bool contains(qint64 iCol, qint64 iRow);
    bool contains(qint64 iCol, qint64 iRow, qint64 iLay);
};

#endif // RASTERBLOCK_H
