TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vector3d.cpp \
    simpletriangle.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    vector3d.h \
    simpletriangle.h

