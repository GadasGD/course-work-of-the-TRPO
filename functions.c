#include "functions.h"

void create_task()
{   
    FILE *Task_file = fopen("task.txt", "w");
    char line[100];
    if (Task_file == NULL) {
        printf("Не удалось открыть файл для чтения.\n");
        exit(1);
    }

    char name[100];
    char description[1000];
    char date[100];
    char deadline[100];
    char teg[100];
    //int id;

    printf("Введите название заметки: ");
    scanf("%s", name);

    printf("Введите описание заметки: ");
    scanf("%s", description);

    printf("Введите дату: ");
    scanf("%s", date);

    printf("Введите дэдлайн заметки: ");
    scanf("%s", deadline);

    printf("Введите статус: ");
    scanf("%s", teg);

    fprintf(Task_file, "Task {\nName: %s;\nTeg: %s;\nDate created: %s;\nDeadline: %s;\nDayly: false;\nDescription: %s;\n}\n ", name, teg, date, deadline, description);
    
}
void print_list()
{
    printf("Pass\n");
}

void delete_task()
{
    printf("Pass\n");
}

void check_task()
{
    printf("Pass\n");
}
