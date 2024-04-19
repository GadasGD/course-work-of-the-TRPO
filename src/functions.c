#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void print_menu()
{
    printf("\n-----------------------------------\n1 - создать новую задачу\n2 "
               "- посмотреть задачу\n3 - отметить как выполненное\n4 - удалить "
               "задачу\n5 - просмотреть выполненные задачи\n6 - выйти\n-----------------------------------\n");
    printf("Введите номер действия: ");  
}

int get_variant(int count)
{
    int variant;
    char s[100];
    scanf("%s", s);

    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count)
    {
        printf("Неккоретный ввод\n");
        print_list();
        print_menu();
    }
    return variant;
}

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
    fprintf(Task_file, "Task {\nId: %d;\nName: %s", id, name);
    fseek(Task_file, -1, SEEK_CUR);
    fprintf(Task_file, ";\nTeg: %s;\nDate created: %d.%d.%d;\nDeadline: %s;\nDayly: false;\nDescription: %s", teg, now->tm_mday, now->tm_mon + 1, now->tm_year + 1900, deadline, description);
    fseek(Task_file, -1, SEEK_CUR);
    fprintf(Task_file,";\n}\n ");
    fclose(Task_file);
}

void print_list()
{
    FILE *file = fopen("task.txt", "r");
    if (file == NULL)
    {
        printf("Не удалось открыть файл для чтения.\n");
        exit(1);
    }

    int id = 0;
    char teg[100] = "";
    char line[100] = "";
    char name[100] = "";
    

    printf("-----------------------------------\nЗадачи:\nСрочное:\n");
    while (fgets(line, sizeof(line), file) != NULL) // вывод для срочно
    {
        sscanf(line, "Id: %d;", &id);
        if (sscanf(line, "Name: %s", name))
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
    fseek(file, 0, SEEK_SET); // возвращение в начало файла
    strcpy(teg, ""); // обнуление переменной


    printf("Важно:\n");
    while (fgets(line, sizeof(line), file) != NULL) // вывод для важного
    {
        sscanf(line, "Id: %d;", &id);
        if (sscanf(line, "Name: %s", name))
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
    fseek(file, 0, SEEK_SET); // возвращение в начало файла
    strcpy(teg, ""); // обнуление переменной


    printf("Другое:\n");
    while (fgets(line, sizeof(line), file) != NULL) // вывод для другого
    {
        sscanf(line, "Id: %d;", &id);
        if (sscanf(line, "Name: %s", name))
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

void print_task()
{
    int user_id, id = 0, max_id = 0;
    char line[1000] = "";
    char name[100] = "";
    char teg[100] = "";
    char date[100] = "";
    char deadline[100] = "";
    char dayly[100] = "";
    char description[1000] = "";

    FILE *file = fopen("task.txt", "r");
    if (file == NULL)
    {
        printf("Не удалось открыть файл для чтения.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", &max_id);
    }
    fseek(file, 0, SEEK_SET);

    printf("Введите номер нужной заметки: ");
    scanf("%d", &user_id);
    if (user_id > max_id || user_id < 1)
    {
        printf("Заметка не найдена");
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", &id);
        if (id == user_id)
        {
            int count = 0;
            while ((fgets(line, sizeof(line), file) != NULL) && count < 7)
            {
                if (sscanf(line, "Name: %s", name))
                {
                    strcpy(name, "");
                    fseek(file, -strlen(line), SEEK_CUR);
                    fgets(name, sizeof(line), file);
                }
                sscanf(line, "Teg: %s;", teg);
                sscanf(line, "Date created: %s;", date);
                sscanf(line, "Deadline: %s;", deadline);
                sscanf(line, "Dayly: %s;", dayly);
                if (sscanf(line, "Description: %s;", description))
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

void delete_task()
{
    FILE *file = fopen("task.txt", "r+b");
    FILE *swap = fopen("transitory_task.txt", "w+");
    if (file == NULL)
    {
        printf("Не удалось открыть файл для чтения.\n");
        exit(1);
    }

    char line[100];
    int user_id, task_id, new_id = 1, max_id;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", &max_id);
    }
    fseek(file, 0, SEEK_SET);

    printf("Введите номер задачи:");
    scanf("%d", &user_id);
    if (user_id > max_id || user_id < 1)
    {
        printf("Заметка не найдена");
        return;
    }


    while (fgets(line, sizeof(line), file) != NULL) // запись во временный файл
    {
        sscanf(line, "Id: %d;", &task_id);

        if (user_id != task_id)
        {   
            fputs(line, swap);
        }
    }
    fclose(swap);
    fclose(file);


    FILE *task = fopen("task.txt", "w+");
    FILE *swap1 = fopen("transitory_task.txt", "r+b");

    while (fgets(line, sizeof(line), swap1) != NULL) // запись в файл заметок из временного файла
    {
        if (sscanf(line, "Id: %d;", &task_id) == 1) // новый id
        {
            fprintf(task, "Id: %d;\n", new_id);
            new_id++;
        }
        else
        {
            fputs(line, task);
        }

    }
    fclose(swap1);
    fclose(task);
    remove("transitory_task.txt");
}

void complete_task()
{
    FILE *file = fopen("task.txt", "r+b"); // файл хранящий заметки (открывается на чтение без удаления содержимого)
    FILE *swap = fopen("transitory_task.txt", "w+"); // создание временного файла для заметок
    FILE *complete_task_file = fopen("complete_task.txt", "a+"); // файл с выполнеными заметками (открывается на дополнение)
    if (file == NULL)
    {
        printf("Не удалось открыть файл для чтения.\n");
        exit(1);
    }

    char line[1000] = "";
    int user_id, task_id, new_id = 1, complete_task_id = 0, max_id;
    int line_count = 0;
    time_t date = time(NULL);
    struct tm *now = localtime(&date);
    bool flag = true;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", &max_id);
    }
    fseek(file, 0, SEEK_SET);
    
    printf("Введите номер задачи, которую выполнили: ");
    scanf("%d", &user_id);
    if (user_id > max_id || user_id < 1)
    {
        printf("Заметка не найдена");
        return;
    }


    while (fgets(line, sizeof(line), complete_task_file) != NULL) // последний id в файле с выполненными задачами
    {
        sscanf(line, "Id: %d;", &complete_task_id);
    }
    complete_task_id++;

    int count = 0;
    while (fgets(line, sizeof(line), file) != NULL)
    {   
        if(flag)
        {
            if(sscanf(line, "Id: %d;", &task_id))
            {
                count = 0;
                flag = false;
                fseek(file, -strlen(line) - 7, SEEK_CUR);
                continue;
            }
        }
        
        if (user_id != task_id)
        {   
            if (count < 10 && flag == false)
            {
                fputs(line, swap);
                count++;
            }
            if (count > 9)
            {
                flag = true;
            }
        }
        else
        {   
            fseek(file, -strlen(line), SEEK_CUR);
            while ((fgets(line, sizeof(line), file) != NULL) && line_count < 10)
            {
                if (sscanf(line, "Id: %d;", &user_id) == 1)
                {
                    fprintf(complete_task_file, "Id: %d;\n", complete_task_id);
                    if (now->tm_mon + 1 < 10) 
                    {
                        fprintf(complete_task_file, "Date_complete: %d.0%d.%d;\n", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
                    }
                    else
                    {
                        fprintf(complete_task_file, "Date_complete: %d.%d.%d;\n", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
                    }
                }
                else
                {
                    fputs(line, complete_task_file);
                }
                line_count++;
                if (line_count == 10)
                {
                    task_id++;
                    flag = true;
                    //fseek(file, +6, SEEK_CUR);
                }
            }
        }
        strcpy(line, "");
    }
    fclose(swap);
    fclose(file);
    fclose(complete_task_file);

    FILE *task = fopen("task.txt", "w+"); // файл с заметками открывается с удалением содержимого
    FILE *swap1 = fopen("transitory_task.txt", "r+b"); // временный файл открывается на чтение 

    
    while (fgets(line, sizeof(line), swap1) != NULL)
    {
        if (sscanf(line, "Id: %d;", &task_id) == 1)
        {
            fprintf(task, "Id: %d;\n", new_id);
            new_id++;
        }
        else
        {
            fputs(line, task);
        }

    }
    fclose(swap1);
    fclose(task);
    remove("transitory_task.txt"); // удаление временного файла
}

void print_complete_tasklist()
{
    FILE *file = fopen("complete_task.txt", "r");
    int id = 0, max_id;
    int count_task_day = 0;
    char line[100] = "";
    char name[100] = "";
    time_t date = time(NULL);
    struct tm *now = localtime(&date);
    int mday, mon, year;
    bool flag = false;

    while (fgets(line, sizeof(line), file) != NULL) // поиск максимального id
    {
        sscanf(line, "Id: %d;", &max_id);
    }
    fseek(file, 0, SEEK_SET);

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if(sscanf(line, "Date_complete: %d.%d.%d;", &mday, &mon, &year))
        {
            if(mday == now->tm_mday && mon == now->tm_mon + 1 && year == now->tm_year + 1900)
            {
                count_task_day++;
            }
        }
    }
    fseek(file, 0, SEEK_SET);

    printf("-----------------------------------\nВсего выполненно задач: %d, из них сегодня выполненно: %d\n", max_id, count_task_day);
    printf("Задачи: \n");
    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Id: %d;", &id);
        if (sscanf(line, "Name: %s", name))
        {
            strcpy(name, "");
            fseek(file, -strlen(line), SEEK_CUR);
            fgets(name, sizeof(line), file);
        }
        sscanf(line, "Date_complete: %d.%d.%d;", &mday, &mon, &year);
        if(strlen(name) > 1)
        {
            flag = true;
        }

        if (flag == true)
        {
            printf("%d - ", id);
            for (size_t i = 0; i < strlen(name) - 2; i++)
            {
                if (i > 5)
                {
                    printf("%c", name[i]);
                }
            }
            printf(", выполненно: %d.%d.%d;\n", mday, mon, year);
            flag = false;
            strcpy(name, "");
        }
    }
    printf("-----------------------------------\n");
    fclose(file);
    getchar(); // чтобы enter пропустить
    getchar();
}