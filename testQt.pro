QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logger.cpp \
    datamodel/models/boat.cpp \
    datamodel/factories/boatfactory.cpp \
    datamodel/factories/carfactory.cpp \
    datamodel/models/game.cpp \
    controller/gamelauncher.cpp \
    datamodel/models/motorbike.cpp \
    datamodel/factories/motorbikefactory.cpp \
    datamodel/models/plane.cpp \
    datamodel/factories/planefactory.cpp \
    datamodel/models/vehicle.cpp \
    datamodel/factories/vehiclefactory.cpp \
    datamodel/models/vehicletablemodel.cpp \
    datamodel/models\car.cpp \
    main.cpp \
    mainwindow.cpp \
    datamodel/models/user.cpp

HEADERS += \
    logger.h \
    datamodel/models/boat.h \
    datamodel/factories/boatfactory.h \
    datamodel/factories/carfactory.h \
    datamodel/models/game.h \
    controller/gamelauncher.h \
    datamodel/models/motorbike.h \
    datamodel/factories/motorbikefactory.h \
    datamodel/models/plane.h \
    datamodel/factories/planefactory.h \
    datamodel/models/vehicle.h \
    datamodel/factories/vehiclefactory.h \
    datamodel/models/vehicletablemodel.h \
    datamodel/models\car.h \
    mainwindow.h \
    datamodel/models/user.h \
    utilities.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
