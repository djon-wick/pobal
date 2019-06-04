/**
 * m.c -- реализует команду перемещения курсора в заданную позицию
 *
 * Copyright (c) 2017, Abramov Egor <abramov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include "text/_text.h"

/**
 * Перемещает курсор в заданную позицию
 */
void m(text txt, int new_line, int new_pos)
{
    node *lt = txt->begin;
    int index = 0;   

    /* Проход по элементам списка в поисках нужной строки и установка курсора */
    while(lt) {
        if (index == new_line - 1 && txt->cursor->position != new_pos - 1) {
            memmove(&txt->cursor->line->contents[new_pos ], &txt->cursor->line->contents[new_pos - 1],  strlen(&txt->cursor->line->contents[new_pos - 1]));
            txt->cursor->position = new_pos - 1;
            txt->cursor->line = lt;
            break;
        }

        lt = lt->next;
        index++;
    }
}
