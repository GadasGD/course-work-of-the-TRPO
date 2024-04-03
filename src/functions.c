#include "functions.h"

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

    printf("Введите содержание заметки: ");
    scanf("%s", description);

    printf("Введите дату создания заметки: ");
    scanf("%s", date);

    printf("Введите крайний срок выполнения заметки: ");
    scanf("%s", deadline);

    int choice = 0;
    do
    {
        printf("Введите статус: 1 - Срочно, 2 - Важно\n");
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
                sscanf(line, "Name: %s;", name);
                sscanf(line, "Teg: %s;", teg);
                sscanf(line, "Date created: %s;", date);
                sscanf(line, "Deadline: %s;", deadline);
                sscanf(line, "Dayly: %s;", dayly);
                sscanf(line, "Description: %s;", description);
                count++;
            }
            printf("-----------------------------------\n");
            printf("Название заметки: %s\n", name);
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
            printf("Содержание: %s\n", description);
            printf("-----------------------------------\n");
            scanf("%d", &id);
            break;
        }
    } 
    fclose(file);
}