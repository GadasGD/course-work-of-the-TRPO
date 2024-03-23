#include "functions.h"



int main()
{
    int choice;
    do
    {   
        
        print_list();
        printf("-----------------------------------\n1 - создать новую задачу\n2 - посмотреть задачу\n3 - отметить как выполненное\n4 - удалить задачу\n5 - выйти\n-----------------------------------\n");
        printf("Введите номер действия: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_task();
            choice = 999;
            break;
        case 2:
            delete_task();
            choice = 999;
            break; 
        case 3:
            check_task();
            choice = 999;
            break;
        case 4:
            delete_task();
            choice = 999;
            break;
        case 5:
            exit(0);
        // case 999:
        //     printf("-----------------------------------\n1 - создать новую задачу\n2 - посмотреть задачу\n3 - отметить как выполненное\n4 - удалить задачу\n5 - выйти\n-----------------------------------\n");
        //     printf("Введите номер действия: ");            
        //     scanf("%d", &choice);
        //     // printf("\n");
        default:
            printf("Неверный выбор операции. Попробуйте снова.\n");
            printf("\n");
        }
    } while (choice != 5);
    
    return 0;
}

