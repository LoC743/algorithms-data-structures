// Morozov Alexey

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char char_choice[3];
	int int_choice = 0;
    int exit_code = -1;

	do {
		printf("\n\033[0;37mМеню: \n");
        printf("-1. Выход\n");
		printf("1. Сравнение обычной и оптимизированной реализации пузырьковой сортировки\n");
		printf("2. Шейкерная сортировка\n");
		printf("3. Бинарный алгоритм поиска\n");

        printf("Ваш выбор: ");
		scanf("%s", char_choice);
		int_choice = atoi(char_choice);

		switch (int_choice)
		{
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
			default:
                if (int_choice != exit_code) {
                    printf("\n\033[1;31m[ОШИБКА!] Неверный ввод! Попробуйте еще раз.\n");
                }
                break;
		}
	} while(int_choice != exit_code);

    return 0;
}