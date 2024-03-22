#include "functions.h"



int main()
{
    do
    {   
        int choice;
        print_list();
        printf("-----------------------------------\n1 - создать новую задачу\n2 - посмотреть задачу\n3 - отметить как выполненное\n4 - удалить задачу\n5 - выйти\n-----------------------------------\n");
        printf("Введите номер действия: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_task();
            break;
        case 2:
            delete_task();
            break; 
        case 3:
            check_task();
            break;
        case 4:
            delete_task();
        case 5:
            exit(0);
        }
    } while (true);
    
    return 0;
}

