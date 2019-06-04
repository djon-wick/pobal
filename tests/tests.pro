include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=     testoes.h \
               ../app/text/_text.h \
                ../app/text/text.h \
            ../app/common.h \
            testoes_save.h \
            m.h \
            rh.h \
    plb.h \
    shownum.h

SOURCES +=     main.cpp \
    ../app/load.c \
    ../app/save.c \
        ../app/text/process_forward.c \
        ../app/text/create_text.c \
        ../app/text/remove_all.c \
        ../app/show.c \
        ../app/rh.c \
        ../app/plb.c \
        ../app/m.c \
        ../app/text/append_line.c \
# Функции для тестирования

INCLUDEPATH += ../app
