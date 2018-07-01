include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
#CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=     \
    herocontroller_test.h \
    levelmanager_test.h \
    ../app/herocontroller.h \
    ../app/levelmanager.h

SOURCES +=     main.cpp \
    ../app/levelmanager.cpp \
    ../app/herocontroller.cpp

INCLUDEPATH += ../app

SUBDIRS += \
    ../app/app.pro
