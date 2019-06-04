/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1)
    {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0)
	{
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0)
	{
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0)
	{
            show(txt, 0);
            continue;
        }
	
        /* Выводим текст с нумерацие строк */
        if (strcmp(cmd, "shownum") == 0)
	{
            show(txt, 1);
            continue;
        }
	
	/* Сохраняем текст в файл */
	if (strcmp(cmd, "save") == 0)
	{
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }        

        /* Перемещаем курсор на новую позицию */
        if (strcmp(cmd, "m") == 0) {
            char *arg1, *arg2;

            if ((arg1 = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: Not enough arguments \n");
		return;
            }

            if ((arg2 = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: Not enough arguments \n");
		return;
            } else
                m(txt, atoi(arg1), atoi(arg2));

            continue;
        }

	/* Выводим текст строки до курсора */
	if(strcmp(cmd, "plb") == 0)
	{
	    plb(txt);
	    continue;
	}

        /* Удаляем первую строку текста */
	if(strcmp(cmd, "rh") == 0)
	{
	    rh(txt);
	    continue;
	}

	/* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
