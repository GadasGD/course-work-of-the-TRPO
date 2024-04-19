#ifndef FUNC
#define FUNC
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void create_task(); // создание заметки
void print_list(); // вывод заметок в главном экране
void print_task(); // вывод конкретной заметки
void delete_task(); // удаление заметки
void complete_task(); // отметить задачу как выполненную  и удалить
void print_menu(); // вывод меню
int get_variant(int count); // выбор пункта в меню
void print_complete_tasklist();


#endif