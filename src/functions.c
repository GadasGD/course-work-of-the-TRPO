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
    int id = 0;

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
    
    fprintf(Task_file, "Task {\nId: %d\nName: %s;\nTeg: %s;\nDate created: %s;\nDeadline: %s;\nDayly: false;\nDescription: %s;\n}\n ", id, name, teg, date, deadline, description);
    
}
void print_list()
{ 
    FILE *file = fopen("task.txt", "r"); 
    printf("-----------------------------------\nЗадачи:\nСрочное:\n"); 
    int count_id = 1; //количество id заметок(количество заметок) 
    char teg[100];
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
    FILE *file = fopen("task.txt", "wr");
    if (file == NULL) {
        printf("Не удалось открыть файл для чтения.\n");
        exit(1);
    }
    char line[100];
    int num_line = 1;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if(strcmp(line, "Task {") == 0) {
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
