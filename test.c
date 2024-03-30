#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_list()
{ 
    FILE *file = fopen("task.txt", "r"); 
    printf("-----------------------------------\nЗадачи:\nСрочное:\n"); 
    int count_id = 1; //количество id заметок(количество заметок) 
    char teg[100];
    char line[100];
    char name[100];
    int id = 0;
    while (fgets(line, sizeof(line), file) != NULL)
    {   
        sscanf(line, "Name: %s;", name);
        sscanf(line, "Teg: %s;", teg);
        if(line == "}\n")
        {
            break;
        }
    }
    if (strcmp(teg, "Срочное;") == 0)
    { 
        for(int id_1 = 1; id_1 <= count_id; id_1++) 
        { 
            printf("%d - %s\n", id, name); 
        } 
    } 
    printf("Важное:\n"); 
    if (strcmp(teg, "Важное;") == 0)
    { 
        for(int id_1 = 1; id_1 <= count_id; id_1++) 
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

int main()
{
    int choice;
    print_list();
    return 0;
}
