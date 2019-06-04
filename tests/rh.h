#ifndef RH_H
#define RH_H

#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}

TEST(rh1, t1)
{
    text txt = create_text();
    FILE *f;
    char buf[MAXLINE + 1];
    char filepath[] = "build-qmake-gtest-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/app/tuda";

    load(txt, filepath);

    /* Вызов тестируемой функции */
    rh(txt);

    node *current = txt->begin;
    int index = 0, count = 0;

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen("build-qmake-gtest-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/app/tuda", "r")) == NULL) {
        FAIL();
    }

    /* Считываем содержимое строка за строкой и проверяем */
    while (fgets(buf, MAXLINE, f)) {
        if (current && index > 0){
                /* Проверка, что 1ая строка удалилась, а остальные сместились на 1 вверх */
                ASSERT_STREQ(buf, current->contents);

                count++;

                /* Продвигаемся к следующему элементу */
                current = current->next;
            }
        index++;
    }

    /* Проверка, что количество строк стало меньше на 1 */
    EXPECT_EQ(count, 4);

    fclose(f);

    SUCCEED();
}

#endif // RH_H
