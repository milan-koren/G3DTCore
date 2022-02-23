/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file index2d.cpp
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include "index2d.h"


/*!
 * \brief Default constructor. Creates empty invalid index.
 */
Index2D::Index2D()
{
    this->set(-1, -1, -1);
}


/*!
 * \brief Default copy constructor.
 * \param index Reference to a source 2D index.
 */
Index2D::Index2D(const Index2D &index)
{
    set(index.col, index.row, index.band);
}


/*!
 * \brief Constructor from explicit indexes.
 * \param col Column index.
 * \param row Row index.
 * \param band Band index.
 */
Index2D::Index2D(qint64 col, qint64 row, qint64 band)
{
    this->set(col, row, band);
}


/*!
 * \brief Virtual destructor.
 */
Index2D::~Index2D()
{
}


/*!
 * \brief Assignment operator.
 * \param index Reference to source 2D index.
 * \return
 */
Index2D &Index2D::operator=(const Index2D &index)
{
    set(index.col, index.row, index.band);
    return *this;
}


/*!
 * \brief Invalidates the 2D index. Sets all indexes to -1.
 */
void Index2D::invalidate()
{
    this->set(-1, -1, -1);
}


/*!
 * \brief Validates index status.
 * \return Returns true if and only if the column, row, and band index are valid.
 */
inline bool Index2D::isValid()
{
    return (0 <= this->col) && (0 <= this->row) && (0 <= this->band);
}


/*!
 * \brief Sets the index to given indexes.
 * \param col Column index.
 * \param row Row index.
 * \param band Band index.
 */
void Index2D::set(qint64 col, qint64 row, qint64 band)
{
    this->col = col;
    this->row = row;
    this->band = band;
}


/*!
 * \brief Converts the 2D index to a Json object.
 * \return Json object.
 */
QJsonObject Index2D::toJson()
{
    QJsonObject qobj;

    qobj.insert("type", static_cast<QString>("Index2D"));
    qobj.insert("col", static_cast<double>(this->col));
    qobj.insert("row", static_cast<double>(this->row));
    qobj.insert("band", static_cast<double>(this->band));

    return qobj;
}


/*!
 * \brief Setups the 2D index from a Json object.
 * \param jsonVal Json value object.
 * \return True, if 2D index was sucessufully loaded.
 */
bool Index2D::fromJson(QJsonValue jsonVal)
{
    this->col = qint64(jsonVal["col"].toDouble());
    this->row = qint64(jsonVal["row"].toDouble());
    this->band = qint64(jsonVal["band"].toDouble());
    return true;
}

