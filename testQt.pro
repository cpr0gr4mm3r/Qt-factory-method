QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logger.cpp \
    model/boat.cpp \
    model/boatfactory.cpp \
    model/carfactory.cpp \
    model/game.cpp \
    model/gamelauncher.cpp \
    model/motorbike.cpp \
    model/motorbikefactory.cpp \
    model/plane.cpp \
    model/planefactory.cpp \
    model/vehicle.cpp \
    model/vehiclefactory.cpp \
    model\car.cpp \
    main.cpp \
    mainwindow.cpp \
    model\user.cpp

HEADERS += \
    logger.h \
    model/boat.h \
    model/boatfactory.h \
    model/carfactory.h \
    model/game.h \
    model/gamelauncher.h \
    model/motorbike.h \
    model/motorbikefactory.h \
    model/plane.h \
    model/planefactory.h \
    model/vehicle.h \
    model/vehiclefactory.h \
    model\car.h \
    mainwindow.h \
    model\user.h \
    utilities.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
