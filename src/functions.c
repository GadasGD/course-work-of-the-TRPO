#include "functions.h"

void create_task()
{
    FILE *Task_file = fopen("task.txt", "r+b");
    if (Task_file == NULL)
    {
        printf("Не удалось открыть файл для чтения.\n");
        exit(1);
    }
    char name[100] = {0};
    char description[1000] = "";
    char date[100] = "";
    char deadline[100] = "";
    char teg[100] = "";
    char line[100] = "";
    int id = 1;

    while (fgets(line, sizeof(line), Task_file) != NULL)
    {
        sscanf(line, "Id: %d;", &id);
    }
    id++;

    if (fgets(line, sizeof(line), Task_file) == NULL)
    {
        fprintf(Task_file, "\n");
    }

    printf("Введите название заметки: ");
    scanf("%s", name);

    printf("Введите описание заметки: ");
    scanf("%s", description);

    printf("Введите дату: ");
    scanf("%s", date);

    printf("Введите дэдлайн заметки: ");
    scanf("%s", deadline);

    int choice = 0;
    do
    {
        printf("Введите статус: 1 - Срочно, 2 - важно\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            strcpy(teg, "Срочно");
            break;
        case 2:
            strcpy(teg, "Важно");
            break;
        default:
            printf("Неверный выбор, попробуите снова\n");
        }
    } while (choice != 1 && choice != 2);
    fprintf(Task_file, "Task {\nId: %d;\nName: %s;\nTeg: %s;\nDate created: %s;\nDeadline: %s;\nDayly: false;\nDescription: %s;\n}\n ", id, name, teg, date, deadline, description);
}
void print_list()
{
    FILE *file = fopen("task.txt", "r");
    printf("-----------------------------------\nЗадачи:\nСрочное:\n");
    int id;
    int count_id = 0;
    char teg[100];
    char line[100];
    char name[100];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", id);
        sscanf(line, "Name: %s;", name);
        sscanf(line, "Teg: %s;", teg);
        count_id++;
    }

    for (; id <= count_id; id++)
    {
        if (teg == "Срочно;")
        {
            printf("%d - %s\n", id, name);
        }
    }
    printf("Важно:\n");
    if (strcmp(teg, "Важно;") == 0)
    {
        for (int id = 1; id <= count_id; id++)
        {
            printf("%d - %s\n", id, name);
        }
    }
    printf("Ежедневные дела:\n");
    // if(teg == "Ежедневные дела")
    // {
    //     for(int id = 1; id <= count_id; id++)
    //     {
    //         printf("%d - %s\n", id, name);
    //     }
    // }
    printf("-----------------------------------\n");
    fclose(file);
}

void delete_task()
{
    FILE *file = fopen("task.txt", "wr");
    if (file == NULL)
    {
        printf("Не удалось открыть файл для чтения.\n");
        exit(1);
    }
    char line[100];
    int num_line = 1;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strcmp(line, "Task {") == 0)
        {
            if (num_line < 8)
            {
                fputs("\n", file);
                num_line++;
            }
        }
    }

    printf("Pass\n");
}

void check_task()
{
    printf("Pass\n");
}

void print_task()
{
    int id_task;
    int id;
    char line[100];
    char name[100] = {0};
    char description[1000];
    char date[100];
    char deadline[100];
    char teg[100];
    char dayly[100];
    printf("Введите номер нужной заметки: ");
    scanf("%d", id_task);
    FILE *file = fopen("task.txt", "r");
    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", id);
        if (id == id_task)
        {
            while (fgets(line, sizeof(line), file) != NULL)
            {
                sscanf(line, "Name: %s;", name);
                sscanf(line, "Teg: %s;", teg);
                sscanf(line, "Date create: %s;", date);
                sscanf(line, "Deadline: %s;", deadline);
                sscanf(line, "Dayly: %s;", dayly);
                sscanf(line, "Description: %s;", description);
            }
            printf("-----------------------------------\n");
            printf("Название заметки: %s\n", name);
            printf("Тег: %s\n", teg);
            printf("Дата создания: %s\n", date);
            printf("Крайний срок выполнения: %s\n", deadline);
            if (dayly == "true")
            {
                printf("Ежедневность: %s\n", dayly);
            }
            printf("Содержание: %s\n", description);
            printf("-----------------------------------\n");
            break;
        }
    }
}