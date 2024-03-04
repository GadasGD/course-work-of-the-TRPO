#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


void printlist();
void submit_task();
void delete_task();
void check_task();

int main()
{
    do
    {   
        int choice;
        printlist();
        printf("-----------------------------------\n1 - внести новую задачу\n2 - удалить задачу\n3 - отметить как выполненное\n4 - выход\n-----------------------------------\n");
        printf("Введите номер действия: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            submit_task();
            break;
        case 2:
            delete_task();
            break; 
        case 3:
            check_task();
            break;
        case 4:
            exit(0);
        }
    } while (true);
    
    return 0;
}

void printlist()
{
    printf("Pass\n");
}

void submit_task()
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