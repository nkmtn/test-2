TEMPLATE = app
CONFIG -= app_bundle

QT += quick
CONFIG += c++11

SOURCES += \
    herocontroller.cpp \
    levelmanager.cpp \
    main.cpp

HEADERS += \
    herocontroller.h \
    levelmanager.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

RESOURCES += qml.qrc
