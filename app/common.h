/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Abramov Egor <abramov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран в зависимости от параметра par
 */
void show(text txt, int par);

/**
 * Сохраняет содержимое указанного файла в файл
 */
void save(text txt, char *filename);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Перемещает курсор на новую позицию
 */
void m(text txt, int new_line, int new_pos);

/**
 * Выводит текст строки до курсора
 */
void plb(text txt);

/**
 * Удаляет первую строку
 */
void rh(text txt);


#endif
