#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void print_list();
int main(int argc, char const *argv[])
{
    print_list();
    return 0;
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
