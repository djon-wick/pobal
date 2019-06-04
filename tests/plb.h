#ifndef PLB_H
#define PLB_H

#include <gtest/gtest.h>

extern "C" {
#include "common.h"
#include "text/_text.h"
}

TEST(plb1, t1)
{
    text txt = create_text();
    FILE *f;
    char buf[MAXLINE + 1];
    char filepath[] = "build-qmake-gtest-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/app/tuda";

    load(txt, filepath);

    /* Вызов тестируемой функции */
    plb(txt);

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen("plb_test", "r")) == NULL) {
        FAIL();
    } else
        fgets(buf, MAXLINE, f);

    ASSERT_STREQ(buf, "--->>>>se s,g,s____<<<<<-----\n");

    fclose(f);

    SUCCEED();
}

TEST(plb2, t1)
{
    text txt = create_text();
    FILE *f;
    char buf[MAXLINE + 1];
    char filepath[] = "build-qmake-gtest-Desktop_Qt_5_12_0_MinGW_64_bit-Debug/app/tuda";

    load(txt, filepath);

    /* Вызов тестируемой функции с после вызова функции перемещения курсора */
    m(txt, 3, 8);
    plb(txt);

    /* Открываем файл для чтения, контролируя ошибки */
    if ((f = fopen("plb_test", "r")) == NULL) {
        FAIL();
    } else
        fgets(buf, MAXLINE, f);

    ASSERT_STREQ(buf, "tak pol\n");

    fclose(f);

    SUCCEED();
}

#endif // PLB_H
