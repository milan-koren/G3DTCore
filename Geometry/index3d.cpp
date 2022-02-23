/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file index3d.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "index3d.h"


/*!
 * \brief Default constructor. Creates empty invalid index.
 */
Index3D::Index3D()
{
    this->lay = -1;
}


/*!
 * \brief Default copy constructor.
 * \param index Reference to a source 3D index.
 */
Index3D::Index3D(const Index3D &index)
{
    set(index.col, index.row, index.lay, index.band);
}


/*!
 * \brief Constructor from given explicit indexes.
 * \param col Column index.
 * \param row Row index.
 * \param lay Layer index.
 * \param band Band index.
 */
Index3D::Index3D(qint64 col, qint64 row, qint64 lay, qint64 band) : Index2D(col, row, band)
{
    this->lay = lay;
}


/*!
 * \brief Virtual destructor.
 */
Index3D::~Index3D()
{
}


/*!
 * \brief Assignment operator.
 * \param index Reference to a source 3D index.
 * \return
 */
Index3D &Index3D::operator=(const Index3D &index)
{
    set(index.col, index.row, index.lay, index.band);
    return *this;
}


/*!
 * \brief Invalidates the 3D index. Sets all indexes to -1.
 */
void Index3D::invalidate()
{
    Index2D::invalidate();
    this->lay = -1;
}


/*!
 * \brief Checks the index status.
 * \return Returns true if and only if the column, row, layer, and band index are valid.
 */
inline bool Index3D::isValid()
{
    return Index2D::isValid() && (0 <= this->lay);
}


/*!
 * \brief Sets the index to given indexes.
 * \param col Column index.
 * \param row Row index.
 * \param lay Layer index.
 * \param band Band index.
 */
void Index3D::set(qint64 col, qint64 row, qint64 lay, qint64 band)
{
    Index2D::set(col, row, band);
    this->lay = lay;
}


/*!
 * \brief Converts the 3D index to a Json object.
 * \return Json object.
 */
QJsonObject Index3D::toJson()
{
    QJsonObject qobj;

    qobj.insert("type", static_cast<QString>("Index3D"));
    qobj.insert("col", static_cast<double>(this->col));
    qobj.insert("row", static_cast<double>(this->row));
    qobj.insert("lay", static_cast<double>(this->lay));
    qobj.insert("band", static_cast<double>(this->band));

    return qobj;
}


/*!
 * \brief Setups the 3D index from a Json object.
 * \param jsonVal Json value object.
 * \return True, if the 3D index was sucessufully loaded.
 */
bool Index3D::fromJson(QJsonValue jsonVal)
{
    if (Index2D::fromJson(jsonVal))
    {
        this->lay = qint64(jsonVal["lay"].toDouble());
        return true;
    }
    return false;
}
