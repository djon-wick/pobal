#ifndef TESTOES_SAVE_H
#define TESTOES_SAVE_H

#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}

TEST(save1, t1)
{
    text txt = create_text();
    FILE *f;
    char buf[MAXLINE + 1];
    char filepath[] = "build-qmake-gtest-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/app/tuda";
    char kaput[] = "kaput";

    load(txt, filepath);

    /* Вызов тестируемой функции */
    save(txt, kaput);

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen("build-qmake-gtest-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/tests/kaput", "r")) == NULL) {
        FAIL();
    }

    /* Стартуем с первого элемента списка */
    node *current = txt->begin;

    /* Считываем содержимое строка за строкой и проверяем */
    while (fgets(buf, MAXLINE, f)) {
        if (current){
                ASSERT_STREQ(buf, current->contents);

                /* Продвигаемся к следующему элементу */
                current = current->next;
            }
    }

    SUCCEED();
}

#endif // TESTOES_SAVE_H
