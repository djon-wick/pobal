/**
 * rh.c -- реализует команду удаления первой строки
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
 * Удаляет первую строку
 */
void rh(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL) {
        fprintf(stderr, "The text doesn't exist!\n");
        return;
    }

    /* Если список изначально пуст, делать ничего не надо */
    if (txt->length == 0) {
        return;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);

    node *lt = txt->begin;
    int i = 1;

/* Стартуем с первого элемента списка */
    do {
	/*if(txt->cursor->line == lt)
	    m(txt, 1, 1);*/
	if(txt->cursor->position >= 0 && txt->cursor->line == lt)
	{
	    txt->cursor->line = lt->next;
	    txt->cursor->position = 0;
	    memmove(&txt->cursor->line->contents[1], &txt->cursor->line->contents[0],  strlen(&txt->cursor->line->contents[0]));
	} 
        /* Запоминаем адрес следующего элемента */
        node *next = lt->next;
        /* Освобождаем память, выделенную под текущий элемент */
        free(lt);
        /* Продвигаемся к следующему элементу */
        lt = next;
	i--;
    } while (i);

    txt->begin = lt;
}
