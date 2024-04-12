#include "functions.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

void create_task()
{
    FILE *Task_file = fopen("task.txt", "r+b");
    if (Task_file == NULL)
    {
        printf("Не удалось открыть файл для чтения.\n");
        exit(1);
    }
    char name[100] = "";
    char description[1000] = "";
    time_t date = time(NULL);
    struct tm *now = localtime(&date);
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
    getchar();
    printf("Введите название заметки: ");
    fgets(name, sizeof(name), stdin);

    printf("Введите содержание заметки: ");
    fgets(description, sizeof(description), stdin);

    printf("Введите крайний срок выполнения заметки: ");
    scanf("%s", deadline);
    getchar();
    int choice;
    do
    {
        printf("Введите статус: 1 - Срочно, 2 - Важно, 3 - Другое\n");
        choice = getchar();
        if (choice == '\n')
        {
            choice = getchar();
        }
        switch (choice)
        {
        case '1':
            strcpy(teg, "Срочно");
            break;
        case '2':
            strcpy(teg, "Важно");
            break;
        case '3':
            strcpy(teg, "Другое");
            break;
        default:
            printf("Неверный выбор, попробуите снова\n");
            break;
        }
    } while (choice != '1' && choice != '2' && choice != '3');
    fprintf(Task_file, "Task {\nId: %d;\nName: %s;\nTeg: %s;\nDate created: %d.%d.%d;\nDeadline: %s;\nDayly: false;\nDescription: %s;\n}\n ", id, name, teg, now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, deadline, description);
    fclose(Task_file);
}
void print_list()
{
    FILE *file = fopen("task.txt", "r");
    printf("-----------------------------------\nЗадачи:\nСрочное:\n");
    int id = 0;
    int max_id = 0;
    char teg[100] = "";
    char line[100] = "";
    char name[100] = "";
    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", &max_id);
    }
    fseek(file, 0, SEEK_SET);
    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", &id);
        if(sscanf(line, "Name: %s", name))
        {   
            strcpy(name, "");
            fseek(file, -strlen(line), SEEK_CUR);
            fgets(name, sizeof(line), file);
        }
        sscanf(line, "Teg: %s;", teg);
        if (strcmp(teg, "Срочно;") == 0)
        {
            printf("%d - ", id);
            for (size_t i = 0; i < strlen(name); i++)
            {   
                if (i > 5)
                {
                    printf("%c", name[i]);
                }
            }
            strcpy(teg, "");
        }
    }
    fseek(file, 0, SEEK_SET);
    printf("Важно:\n");
    id = 1;
    strcpy(teg, "");
    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", &id);
        if(sscanf(line, "Name: %s", name))
        {   
            strcpy(name, "");
            fseek(file, -strlen(line), SEEK_CUR);
            fgets(name, sizeof(line), file);
        }
        sscanf(line, "Teg: %s;", teg);
        if (strcmp(teg, "Важно;") == 0)
        {
            printf("%d - ", id);
            for (size_t i = 0; i < strlen(name); i++)
            {   
                if (i > 5)
                {
                    printf("%c", name[i]);
                }
            }
            strcpy(teg, "");
        }
    }
    fseek(file, 0, SEEK_SET);
    printf("Другое:\n");
    id = 1;
    strcpy(teg, "");
    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", &id);
        if(sscanf(line, "Name: %s", name))
        {   
            strcpy(name, "");
            fseek(file, -strlen(line), SEEK_CUR);
            fgets(name, sizeof(line), file);
        }
        sscanf(line, "Teg: %s;", teg);
        if (strcmp(teg, "Другое;") == 0)
        {
            printf("%d - ", id);
            for (size_t i = 0; i < strlen(name); i++)
            {   
                if (i > 5)
                {
                    printf("%c", name[i]);
                }
            }
            strcpy(teg, "");
        }
    }
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
    fclose(file);
}

void check_task()
{
    printf("Pass\n");
}

void print_task()
{
    int id_task;
    int id = 0;
    int max_id = 0;
    char name[100] = "";
    char description[1000] = "";
    char date[100] = "";
    char deadline[100] = "";
    char teg[100] = "";
    char line[100] = "";
    char dayly[100] = "";
    FILE *file = fopen("task.txt", "r");
    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", &max_id);
    }
    fseek(file, 0, SEEK_SET);

    printf("Введите номер нужной заметки: ");
    scanf("%d", &id_task);
    if(id_task > max_id && id_task < 1)
    {
        printf("Заметка не найдена");
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", &id);
        if (id == id_task)
        {
            int count = 0;
            while ((fgets(line, sizeof(line), file) != NULL) && count < 7)
            {
                if(sscanf(line, "Name: %s", name))
                {   
                    strcpy(name, "");
                    fseek(file, -strlen(line), SEEK_CUR);
                    fgets(name, sizeof(line), file);
                }
                sscanf(line, "Teg: %s;", teg);
                sscanf(line, "Date created: %s;", date);
                sscanf(line, "Deadline: %s;", deadline);
                sscanf(line, "Dayly: %s;", dayly);
                if(sscanf(line, "Description: %s;", description))
                {   
                    strcpy(description, "");
                    fseek(file, -strlen(line), SEEK_CUR);
                    fgets(description, sizeof(line), file);
                }
                count++;
            }
            printf("-----------------------------------\n");
            printf("Название заметки: ");
            for (size_t i = 0; i < strlen(name); i++)
            {   
                if (i > 5)
                {
                    printf("%c", name[i]);
                }
            }
            printf("Тег: %s\n", teg);
            printf("Дата создания: %s\n", date);
            if (deadline != 0)
            {
                    printf("Крайний срок выполнения: %s\n", deadline);
            }
            if (strcmp(dayly, "true;") == 0)
            {
                    printf("Ежедневно");
            }
            printf("Содержание: ");
            for (size_t i = 0; i < strlen(description); i++)
            {   
                if (i > 12)
                {
                    printf("%c", description[i]);
                }
            }
            printf("\n");
            printf("-----------------------------------\n");
            getchar();
            getchar();
            fclose(file);
            break;
        }
    } 
}