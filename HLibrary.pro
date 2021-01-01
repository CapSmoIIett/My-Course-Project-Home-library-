QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    act.cpp \
    addbwindow.cpp \
    artbooks.cpp \
    books.cpp \
    excep.cpp \
    magazines.cpp \
    main.cpp \
    mwindow.cpp \
    mwindowslots.cpp \
    newspapers.cpp \
    reading.cpp \
    scbooks.cpp \
    tempedition.cpp \
    windowab.cpp \
    windowmag.cpp \
    windownews.cpp \
    windowsb.cpp

HEADERS += \
    act.h \
    addbwindow.h \
    artbooks.h \
    books.h \
    conditions.inl \
    excep.h \
    filestream.h \
    filestream.inl \
    iterator.inl \
    magazines.h \
    mwindow.h \
    newspapers.h \
    reading.h \
    scbooks.h \
    tempedition.h \
    tree.h \
    tree.inl \
    treebalance.inl \
    windowab.h \
    windowmag.h \
    windownews.h \
    windowsb.h

TRANSLATIONS += \
    HLibrary_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
