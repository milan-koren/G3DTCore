/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file index3dt.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "index3dt.h"


/*!
 * \brief Default constructor. Creates empty invalid index.
 */
Index3DT::Index3DT()
{
    this->tick = -1;
}


/*!
 * \brief Default copy constructor.
 * \param index Reference to a source 3DT index.
 */
Index3DT::Index3DT(const Index3DT &index)
{
    set(index.col, index.row, index.lay, index.band, index.tick);
}


/*!
 * \brief Constructor from given indexes.
 * \param col Column index.
 * \param row Row index.
 * \param lay Layer index.
 * \param band Band index.
 * \param tick Tick index.
 */
Index3DT::Index3DT(qint64 col, qint64 row, qint64 lay, qint64 band, qint64 tick) : Index3D(col, row, lay, band)
{
    this->tick = tick;
}


/*!
 * \brief Virtual destructor.
 */
Index3DT::~Index3DT()
{
}


/*!
 * \brief Assignment operator.
 * \param index Reference to a source 3DT index.
 * \return
 */
Index3DT &Index3DT::operator=(const Index3DT index)
{
    set(index.col, index.row, index.lay, index.band, index.tick);
    return *this;
}


/*!
 * \brief Invalidates the 3DT index. Sets all indexes to -1.
 */
void Index3DT::invalidate()
{
    Index3D::invalidate();
    this->tick = -1;
}


/*!
 * \brief Checks the index status.
 * \return Returns true if and only if the column, row, layer, band, and tick index are valid.
 */
inline bool Index3DT::isValid()
{
    return Index3D::isValid() && (0 <= this->tick);
}


/*!
 * \brief Sets the index to given indexes.
 * \param col Column index.
 * \param row Row index.
 * \param lay Layer index.
 * \param band Band index.
 * \param tick Tick index.
 */
void Index3DT::set(qint64 col, qint64 row, qint64 lay, qint64 band, qint64 tick)
{
    Index3D::set(col, row, lay, band);
    this->tick = tick;
}


/*!
 * \brief Converts the 3DT index to a Json object.
 * \return Json object.
 */
QJsonObject Index3DT::toJson()
{
    QJsonObject qobj;

    qobj.insert("type", static_cast<QString>("Index3DT"));
    qobj.insert("col", static_cast<double>(this->col));
    qobj.insert("row", static_cast<double>(this->row));
    qobj.insert("lay", static_cast<double>(this->lay));
    qobj.insert("band", static_cast<double>(this->band));
    qobj.insert("tick", static_cast<double>(this->tick));

    return qobj;
}


/*!
 * \brief Setups the 3DT index from a Json object.
 * \param jsonVal Json value object.
 * \return True, if the 3DT index was sucessufully loaded.
 */
bool Index3DT::fromJson(QJsonValue jsonVal)
{
    if (Index3D::fromJson(jsonVal))
    {
        this->tick = qint64(jsonVal["tick"].toDouble());
        return true;
    }
    return false;
}
