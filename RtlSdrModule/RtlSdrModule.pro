QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    AudioProcesser.cpp

HEADERS += \
    mainwindow.h \
    AudioProcesser.h

FORMS += \
    mainwindow.ui
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/release/ -lrtlsdr
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/debug/ -lrtlsdr
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/ -lrtlsdr

INCLUDEPATH += $$PWD/../../../../../usr/local/include \
               $$PWD/../../workspace/gqrx.git/src/

DEPENDPATH += $$PWD/../../../../../usr/local/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/x86_64-linux-gnu/release/ -lgnuradio-osmosdr
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/lib/x86_64-linux-gnu/debug/ -lgnuradio-osmosdr
else:unix: LIBS += -L$$PWD/../../../../../usr/local/lib/x86_64-linux-gnu/ -lgnuradio-osmosdr -lgnuradio-blocks -lgnuradio-runtime -lfmt

INCLUDEPATH += $$PWD/../../../../../usr/local/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../../usr/local/lib/x86_64-linux-gnu
