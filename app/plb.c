/**
 * plb.c -- реализует команду вывода части строки до курсора
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
 * Выводит текст до курсора
 */
void plb(text txt)
{
    FILE *f;
    f = fopen("plb_test", "w");
    node *lt = txt->begin;
    int index = 0;
    int i;
    
    /* Проход по элементам списка в поисках нужной строки и установка курсора */
    while(lt) {
        if (txt->cursor->position >= 0) {
            for(i = 0; i < txt->cursor->position; i++) {
                printf("%c", txt->cursor->line->contents[i]);
                fprintf(f, "%c", txt->cursor->line->contents[i]);
            }

            fprintf(f, "%c", '\n');
            printf("\n");
            break;
        }

        lt = lt->next;
        index++;
    }

    fclose(f);
}


