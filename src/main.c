#include "functions.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
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
                // default:
                //     printf("Неверный выбор операции. Попробуйте снова.\n\n");
            }
        } while (choice != 6);

        return 0;
    }

    if ((strcmp(argv[1], "--help")) == 0 || (strcmp(argv[1], "-h")) == 0)
    {
        printf("Приложение для записи заметок.\nКонсольные аргументы:\n--help или -h для вывода информации\n--create или -c для создания заметки\n--delete или -d для удаления заметки\n--complete или -cmp для отметки задачи\n--task или -t для вывода заметки\n");
        return 0;
    }
