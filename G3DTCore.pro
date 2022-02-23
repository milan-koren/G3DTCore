QT -= gui

TEMPLATE = lib
DEFINES += G3DTCORE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Geometry/box2d.cpp \
    Geometry/box3dt.cpp \
    Geometry/index2d.cpp \
    Geometry/index3d.cpp \
    Geometry/index3dt.cpp \
    Geometry/point2d.cpp \
    Geometry/point3d.cpp \
    Geometry/point3dt.cpp \
    Geometry/rasterblock.cpp \
    Geometry/rastersize2d.cpp \
    Geometry/rastersize3d.cpp \
    Geometry/rastersize3dt.cpp \
    g3dtworker.cpp

HEADERS += \
    Geometry/box2d.h \
    Geometry/box3dt.h \
    Geometry/geometry.h \
    Geometry/index2d.h \
    Geometry/index3d.h \
    Geometry/index3dt.h \
    Geometry/point2d.h \
    Geometry/point3d.h \
    Geometry/point3dt.h \
    Geometry/rasterblock.h \
    Geometry/rastersize2d.h \
    Geometry/rastersize3d.h \
    Geometry/rastersize3dt.h \
    g3dtcore.h \
    g3dtcore_global.h \
    g3dtworker.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    licence.txt
