// Morozov Alexey

#include <stdio.h>
#include <stdlib.h>

void task1();
void task2();

int main() {
    char char_choice[3];
	int int_choice = 0;
    int exit_code = -1;

	do {
		printf("\n\033[0;37mМеню: \n");
        printf("-1. Выход\n");
		printf("1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.\n");
		printf("2. Реализовать функцию возведения числа a в степень b\n");
		printf("3. Исполнитель Калькулятор преобразует целое число, записанное на экране.\n");

        printf("Ваш выбор: ");
		scanf("%s", char_choice);
		int_choice = atoi(char_choice);

		switch (int_choice)
		{
            case 1:
                task1();
                break;
            case 2:
                task2();
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

// 1. Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию.
int dec_to_bin(int number, int result, int order) {
    int reminder = number % 2;
    int answ = reminder * order;
    order *= 10;

    if (number >= 2) {
        answ += dec_to_bin(number/2, answ, order);
    }

    return answ;
}

void task1() {
    int number = 0;

    printf("\nВведите число в десятичной системе счисления: ");
    scanf("%d", &number);

    int result = dec_to_bin(number, 0, 1);
    printf("\nResult = %d\n", result);
}

// 2. Реализовать функцию возведения числа a в степень b:
// a. без рекурсии;
// b. рекурсивно;
// c. *рекурсивно, используя свойство четности степени.
int pow_it(int number, int power) {
    int result = 1;
    for (int i = 0; i < power; ++i) {
        result *= number;
    }
    
    return result;
}

void task2A() {
    int number = 0;
    int power = 0;

    printf("\nВведите число: ");
    scanf("%d", &number);
    printf("\nВведите степень: ");
    scanf("%d", &power);

    int result = pow_it(number, power);
    printf("Результат: %d\n", result);
}

void task2B() {}

void task2C() {}

void task2() {
char char_choice[3];
	int int_choice = 0;
    int exit_code = -1;

	do {
		printf("\n\033[0;37m2. Реализовать функцию возведения числа a в степень b: \n");
        printf("-1. Назад\n");
		printf("1. без рекурсии;\n");
		printf("2. рекурсивно;\n");
		printf("3. *рекурсивно, используя свойство четности степени.\n");

        printf("Ваш выбор: ");
		scanf("%s", char_choice);
		int_choice = atoi(char_choice);

		switch (int_choice)
		{
            case 1:
                task2A();
                break;
            case 2:
                task2B();
                break;
            case 3:
                task2C();
                break;
			default:
                if (int_choice != exit_code) {
                    printf("\n\033[1;31m[ОШИБКА!] Неверный ввод! Попробуйте еще раз.\n");
                }
                break;
		}
	} while(int_choice != exit_code);
}