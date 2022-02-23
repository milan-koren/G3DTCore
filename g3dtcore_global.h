#ifndef G3DTCORE_GLOBAL_H
#define G3DTCORE_GLOBAL_H

/*!
 * *****************************************************************
 *                             G3DTCore
 * *****************************************************************
 * \file g3dtcore_global.h
 *
 * \author M. Koren, milan.koren3@gmail.com
 * Source: https://github.com/milan-koren/G3DTCore
 * Licence: EUPL v. 1.2
 * https://joinup.ec.europa.eu/collection/eupl
 * *****************************************************************
 */

#include <QtCore/qglobal.h>
#include <QJsonObject>

#if defined(G3DTCORE_LIBRARY)
#  define G3DTCORE_EXPORT Q_DECL_EXPORT
#else
#  define G3DTCORE_EXPORT Q_DECL_IMPORT
#endif

#endif // G3DTCORE_GLOBAL_H
