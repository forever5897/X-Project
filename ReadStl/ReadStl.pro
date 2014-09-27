TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    readstl.cpp \
    ../math/simpletriangle.cpp \
    ../math/vector3d.cpp


include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    readstl.h \
    ../math/simpletriangle.h \
    ../math/vector3d.h



