/**
 * save.c -- реализует команду сохранения текста в указанный файл
 *
 * Copyright (c) 2017, Abramov Egor <abramov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void save_line(text txt, int index, char *contents, int cursor, void *data);

/**
 * Сохраняет содержимое файла в указанный файл
 */
void save(text txt, char *filename)
{
    FILE *fp;
    
    /* Открываем файл для записи, контролируя ошибки */
    if ((fp = fopen(filename, "w")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }

    /* Применяем функцию save_line к каждой строке текста */
    process_forward(txt, save_line, fp);
    fclose(fp);
}

/**
 * Сохраняет содержимое файла в указанный файл построчно
 */
static void save_line(text txt, int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(txt);
    
    /* Выводим строку в файл */
    fprintf((FILE*)data, "%s", contents);
}
