#include "functions.h"

void create_task()
{   
    FILE *Task_file = fopen("task.txt", "w");
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
    FILE *file = fopen("task.txt", "r"); 
    printf("-----------------------------------\nЗадачи:\nСрочное:\n"); 
    int count_id = 1; //количество id заметок(количество заметок) 
    char teg[100];
    char teg_sroch[100] = "Срочное;";
    char teg_vagno[100] = "Важное;";
    char line[100];
    char name[100];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        sscanf(line, "Name: %s;", name);
        sscanf(line, "Teg: %s;", teg);
    }
    if (strcmp(teg, "Срочное;") == 0)
    { 
        for(int id = 1; id <= count_id; id++) 
        { 
            printf("%d - %s\n", id, name); 
        } 
    } 
    printf("Важное:\n"); 
    if (strcmp(teg, "Важное;") == 0)
    { 
        for(int id = 1; id <= count_id; id++) 
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
    printf("Pass\n");
}

void check_task()
{
    printf("Pass\n");
}
