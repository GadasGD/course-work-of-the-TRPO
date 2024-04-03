#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_list();

void print_menu();
int get_variant(int count);
void create_task()
{   
    FILE *Task_file = fopen("task.txt", "r+b");
    if (Task_file == NULL) {
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
    
    if(fgets(line, sizeof(line), Task_file) == NULL)
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
    do{
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
    }while(choice != 1 && choice != 2);
    fprintf(Task_file, "Task {\nId: %d;\nName: %s;\nTeg: %s;\nDate created: %s;\nDeadline: %s;\nDayly: false;\nDescription: %s;\n}\n ", id, name, teg, date, deadline, description);
    
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



int main()
{
    int choice;
    do
    {
        print_list();
        print_menu();

        choice = get_variant(5);
        switch (choice)
        {
        case 1:
            create_task();
            break;
        case 2:
            create_task();
            break;
        case 3:
            create_task();
            break;
        case 4:
            create_task();
            break;
        case 5:
            exit(0);
        default:
            printf("Неверный выбор операции. Попробуйте снова.\n");
            printf("\n");
        }
    } while (choice != 5);

    return 0;
}

void print_menu()
{
    printf("\n-----------------------------------\n1 - создать новую задачу\n2 "
               "- посмотреть задачу\n3 - отметить как выполненное\n4 - удалить "
               "задачу\n5 - выйти\n-----------------------------------\n");
    printf("Введите номер действия: ");  
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
            for (int i = 0; i < strlen(name); i++)
            {   
                if (i > 5)
                {
                    printf("%c", name[i]);
                }
            }
            printf("\n");
            strcpy(teg, "");
        }
    }
    fseek(file, 0, SEEK_SET);
    printf("Важно:\n");
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
        if (strcmp(teg, "Важно;") == 0)
        {
            printf("%d - ", id);
            for (int i = 0; i < strlen(name); i++)
            {   
                if (i > 5)
                {
                    printf("%c", name[i]);
                }
            }
            //printf("\n");
            strcpy(teg, "");
        }
    }
    
    printf("Другое:\n");
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