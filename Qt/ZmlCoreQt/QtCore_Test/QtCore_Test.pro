QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = QtCore_Test

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG(debug,release|debug){
    DESTDIR = $$PWD/../../../Output_Exe/Debug/
    OBJECTS_DIR = $$PWD/../../../Output/Debug/obj/$${TARGET}/
}
CONFIG(release,release|debug){
    DESTDIR = $$PWD/../../../Output_Exe/Release/
    OBJECTS_DIR =  $$PWD/../../../Output/Release/obj/$${TARGET}/
}

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Sdk/lib/ -lLanuch
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Sdk/lib/ -lLanuchd

INCLUDEPATH += $$PWD/../../../Sdk/include
DEPENDPATH += $$PWD/../../../Sdk/include

SOURCES += \
    main.cpp \
    window.cpp

HEADERS += \
    window.h

FORMS += \
    window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
