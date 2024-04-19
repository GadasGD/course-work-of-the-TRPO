#include "functions.h"

int main()
{
    int choice;
    do
    {
        print_list();
        print_menu();

        choice = get_variant(6);
        switch (choice)
        {
        case 1:
            create_task();
            break;
        case 2:
            print_task();
            break;
        case 3:
            complete_task();
            break;
        case 4:
            delete_task();
            break;
        case 5:
            print_complete_tasklist();
            break;
        case 6:
            exit(0);
        default:
            printf("Неверный выбор операции. Попробуйте снова.\n\n");
        }
    } while (choice != 6);

    return 0;
}