#ifndef M_H
#define M_H

#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}

TEST(m1, t1)
{
    text txt = create_text();
    char filepath[] = "build-qmake-gtest-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/app/tuda";

    load(txt, filepath);

    /* Вызов тестируемой функции */
    m(txt, 3, 6);

    node *current = txt->begin;
    int index = 0;

    /* Проход по элементам списка в поисках нужной строки и проверка, на правильность выполнения функции */
    while(current) {
        if (index == 2) {
            if (txt->cursor->position == 5) {
                SUCCEED();
            }   else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    SUCCEED();
}

TEST(m2, t2)
{
    text txt = create_text();
    char filepath[] = "build-qmake-gtest-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/app/tuda";

    load(txt, filepath);

    /* Вызов тестируемой функции */
    m(txt, 2, 4);
    m(txt, 3, 7);
    m(txt, 1, 8);

    node *current = txt->begin;
    int index = 0;

    /* Проход по элементам списка в поисках нужной строки и проверка, на правильность выполнения функции */
    while(current) {
        if (index == 0) {
            if (txt->cursor->position == 7) {
                SUCCEED();
            }   else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    SUCCEED();
}

TEST(m3, t3)
{
    text txt = create_text();
    char filepath[] = "build-qmake-gtest-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/app/tuda";

    load(txt, filepath);

    /* Вызов тестируемых функций */
    m(txt, 1, 8);
    rh(txt);

    node *current = txt->begin;
    int index = 0;

    /* Проход по элементам списка в поисках нужной строки и проверка, на правильность выполнения функции */
    while(current) {
        if (index == 0) {
            if (txt->cursor->position == 0) {
                SUCCEED();
            }   else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    SUCCEED();
}

TEST(m4, t4)
{
    text txt = create_text();
    char filepath[] = "build-qmake-gtest-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/app/tuda";

    load(txt, filepath);

    /* Вызов тестируемой функций */
    m(txt, 5, 4);

    node *current = txt->begin;
    int index = 0;
    char *tost;

    /* Проход по элементам списка в поисках нужной строки и проверка, на правильность выполнения функции */
    while(current) {
        if (index == 4) {
            if (txt->cursor->position == 3) {
                tost = txt->cursor->line->contents;
            }   else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    /* Повторный вызов тестируемой функций */
    m(txt, 5, 4);

    /* Проход по элементам списка в поисках нужной строки и проверка,
     * на отсутствие изменения строки с курсором после
     * повторного применения функции в то же место
     */
    while(current) {
        if (index == 4) {
            if (txt->cursor->position == 3) {
                EXPECT_EQ(txt->cursor->line->contents, tost);
                SUCCEED();
            }   else
                FAIL();
            break;
        }
        current = current->next;
        index++;
    }

    SUCCEED();
}

#endif // M_H
