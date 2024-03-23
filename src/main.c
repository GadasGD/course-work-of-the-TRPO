#include "functions.h"

int get_variant(int count)
{
    int variant;
    char s[100];
    scanf("%s", s);

    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count)
    {
        printf("Неккоретный ввод\n");
        print_list();
        printf("\n-----------------------------------\n1 - создать новую задачу\n2 "
               "- посмотреть задачу\n3 - отметить как выполненное\n4 - удалить "
               "задачу\n5 - выйти\n-----------------------------------\n");
        printf("Введите номер действия: ");
        scanf("%s", s);
    }
    return variant;
}

int main()
{
    int choice;
    do
    {
        print_list();
        printf("\n-----------------------------------\n1 - создать новую задачу\n2 "
               "- посмотреть задачу\n3 - отметить как выполненное\n4 - удалить "
               "задачу\n5 - выйти\n-----------------------------------\n");
        printf("Введите номер действия: ");

        choice = get_variant(5);
        switch (choice)
        {
        case 1:
            create_task();
            break;
        case 2:
            print_task();
            break;
        case 3:
            check_task();
            break;
        case 4:
            delete_task();
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
