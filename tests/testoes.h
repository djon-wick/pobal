#ifndef TESTOES_H
#define TESTOES_H

#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}

/**
 * Тестирование функции load
 * Не знаю, зачем я это сделал?
 */
TEST(load1, t1)
{
    text txt = create_text();
    FILE *f;
    char buf[MAXLINE + 1];
    char filepath[] = "tests/tuda";

    /* Вызов тестируемой функции */
    load(txt, filepath);

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen("tests/tuda", "r")) == NULL) {
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

    fclose(f);

    SUCCEED();
}

#endif // TESTOES_H
