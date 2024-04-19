#include "functions.h"

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
            printf("Неверный выбор операции. Попробуйте снова.\n\n");
        }
    } while (choice != 5);

    return 0;
}
