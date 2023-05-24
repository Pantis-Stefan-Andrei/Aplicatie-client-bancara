QT       += core gui
QT += network
LIBS += -lws2_32
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    conectare.cpp \
    fereastraadaugabani.cpp \
    fereastraadmin.cpp \
    fereastraamenzi.cpp \
    fereastrabani.cpp \
    fereastrainregistrare.cpp \
    fereastralogin.cpp \
    fereastrastergeamenzi.cpp \
    fereastrastergecarduri.cpp \
    fereastrastergedepozit.cpp \
    fereastrastergereclient.cpp \
    fereastrastergetranzactie.cpp \
    fereastratranzactie.cpp \
    fereastravizualizarecarduri.cpp \
    fereastravizualizareiban0uri.cpp \
    fereastravizualizaretranzactii.cpp \
    fereastrestergereiban.cpp \
    main.cpp \
    mainwindow.cpp \
    utilizator.cpp

HEADERS += \
    conectare.h \
    fereastraadaugabani.h \
    fereastraadmin.h \
    fereastraamenzi.h \
    fereastrabani.h \
    fereastrainregistrare.h \
    fereastralogin.h \
    fereastrastergeamenzi.h \
    fereastrastergecarduri.h \
    fereastrastergedepozit.h \
    fereastrastergereclient.h \
    fereastrastergetranzactie.h \
    fereastratranzactie.h \
    fereastravizualizarecarduri.h \
    fereastravizualizareiban0uri.h \
    fereastravizualizaretranzactii.h \
    fereastrestergereiban.h \
    mainwindow.h \
    utilizator.h

FORMS += \
    fereastraadaugabani.ui \
    fereastraadmin.ui \
    fereastraamenzi.ui \
    fereastrabani.ui \
    fereastrainregistrare.ui \
    fereastralogin.ui \
    fereastrastergeamenzi.ui \
    fereastrastergecarduri.ui \
    fereastrastergedepozit.ui \
    fereastrastergereclient.ui \
    fereastrastergetranzactie.ui \
    fereastratranzactie.ui \
    fereastravizualizarecarduri.ui \
    fereastravizualizareiban0uri.ui \
    fereastravizualizaretranzactii.ui \
    fereastrestergereiban.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resurse.qrc
