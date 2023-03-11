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
    datamodel/models/user.cpp \
    marblevirtualglobe.cpp

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
    marblevirtualglobe.h \
    utilities.h

FORMS += \
    mainwindow.ui

MSVC_PATH  = "C:\Qt\Qt5.14\5.14.1\mingw73_64"
MARBLE_PATH  = "C:\Program Files (x86)\marble"

INCLUDEPATH += $$MARBLE_PATH\include #$$MSVC_PATH/../../Tools/OpenSSL/Win_x64/include

LIBS     += -L$$MARBLE_PATH\lib -lmarblewidget-qt5 #-L$$MSVC_PATH/../../Tools/OpenSSL/Win_x64/lib -lcrypto -lssl

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
