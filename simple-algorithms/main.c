// Morozov Alexey

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();
void task9();
void task10();
void task11();

int main() {
    char char_choice[3];
	int int_choice = 0;
    int exit_code = -1;

	do {
		printf("\n\033[0;37mМеню: \n");
        printf("-1. Выход\n");
		printf("1. Рассчитать и вывести индекс массы тела\n");
		printf("2. Найти максимальное из четырех чисел\n");
		printf("3. Обмен значениями двух целочисленных переменных\n");
		printf("4. Нахождение корней заданного квадратного уравнения\n");
		printf("5. К какому времени года относится номер месяца\n");
		printf("6. Вывести возраст человека вместе с последующим словом «год», «года» или «лет»\n");
		printf("7. Определить, относятся поля шахматной доски к одному цвету или нет\n");
		printf("8. Ввести a и b и вывести квадраты и кубы чисел от a до b\n");
		printf("9. Найти частное от деления нацело N на K, а также остаток от этого деления\n");
        printf("10. Определить, имеются ли в записи числа N нечетные цифры\n");
        printf("11. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8\n");
        printf("12. Нахождение максимального из трех чисел\n");
        printf("13. Генерирование случайного число от 1 до 100\n");
        printf("14. Вывод на экран все автоморфные числа, не превосходящие N\n");

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
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 6:
                task6();
                break;
            case 7:
                task7();
                break;
            case 8:
                task8();
                break;
            case 9:
                task9();
                break;
            case 10:
                task10();
                break;
            case 11:
                task11();
                break;
            case 12:
                printf("[ОШИБКА!]: Задание 12 не реализовано!\n");
                break;
            case 13:
                printf("[ОШИБКА!]: Задание 13 не реализовано!\n");
                break;
            case 14:
                printf("[ОШИБКА!]: Задание 14 не реализовано!\n");
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

// 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.
void task1() {
    printf("\n");
    double weight = 0;
    double height = 0;

    printf("Введите вес человека(кг): ");
    scanf("%lf", &weight);

    printf("Введите рост человека(м): ");
    scanf("%lf", &height);

    double index = weight / (height * height);

    printf("Полученный индекс массы: %lf\n", index);
}

// 2. Найти максимальное из четырех чисел. Массивы не использовать.
void task2() {
    printf("\n");

    int count = 4;
    int max_value = 0;
    int current_value = 0;

    printf("Введите %d числа.\n", count);
    for (int i = 0; i < count; ++i) {
        printf("Введите число №%d: ", (i+1));
        scanf("%d", &current_value);

        if ((i != 0) && (current_value > max_value)) {
            max_value = current_value;
        } else if (i == 0) {
            max_value = current_value;
        }
    }

    printf("Максимальное число: %d\n", max_value);
}

// 3. Написать программу обмена значениями двух целочисленных переменных:
// a. с использованием третьей переменной;
// b. *без использования третьей переменной.

void task3A() {
    printf("\n");
    int first = 0;
    int second = 0;

    printf("Введите первое число: ");
    scanf("%d", &first);

    printf("Введите второе число: ");
    scanf("%d", &second);
    
    int temp = first;
    first = second;
    second = temp;
    printf("После замены местами: %d, %d\n", first, second);
}

void task3B() {
printf("\n");
    int first = 0;
    int second = 0;

    printf("Введите первое число: ");
    scanf("%d", &first);

    printf("Введите второе число: ");
    scanf("%d", &second);
    
    first = first ^ second;
    second = first ^ second;
    first = first ^ second;
    printf("После замены местами: %d, %d\n", first, second);
}

void task3() {
    printf("\n");

    char char_choice[3];
	int int_choice = 0;
    int exit_code = -1;

	do {
		printf("\n\033[0;37mОбмен значениями двух целочисленных переменных\n");
        printf("-1. Назад\n");
		printf("1. с использованием третьей переменной\n");
		printf("2. без использования третьей переменной\n");

        printf("Ваш выбор: ");
		scanf("%s", char_choice);
		int_choice = atoi(char_choice);

		switch (int_choice)
		{
            case 1:
                task3A();
                break;
            case 2:
                task3B();
                break;
			default:
                if (int_choice != exit_code) {
                    printf("\n\033[1;31m[ОШИБКА!] Неверный ввод! Попробуйте еще раз.\n");
                }
                break;
		}
	} while(int_choice != exit_code);
}

// 4. Написать программу нахождения корней заданного квадратного уравнения.
void task4() {
    double a = 0;
    double b = 0;
    double c = 0;

    printf("\nВведите коэффициенты для уравнения вида: ax^2 + bx + c = 0.\n");
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("c = ");
    scanf("%lf", &c);

    double discriminant = b*b - 4*a*c;

    if (discriminant > 0) {
        double x0 = (-b + sqrt(discriminant)) / (2 * a);
        double x1 = (-b - sqrt(discriminant)) / (2 * a);

        printf("Первый корень x0 = %lf\nВторой корень x1 = %lf\n", x0, x1);
    } else if (discriminant == 0) {
        double x = (-b) / (2 * a);
        printf("Один корень x = %lf\n", x);
    } else {
        printf("Действительный корней нет.\n");
    }
}

// 5. С клавиатуры вводится номер месяца. Требуется определить, к какому времени года он относится.
void task5() {
    int month_number = 0;
    printf("\nВведите номер месяца: ");
    scanf("%d", &month_number);

    if (month_number < 1 || month_number > 12) {
        printf("Такого месяца не существует!\n");
        return;
    }

    if (month_number == 12 || month_number == 1 || month_number == 2) {
        printf("Месяц под номером %d относится к зиме.\n", month_number);
    } else if (month_number == 3 || month_number == 4 || month_number == 5) {
        printf("Месяц под номером %d относится к весне.\n", month_number);
    } else if (month_number == 6 || month_number == 7 || month_number == 8) {
        printf("Месяц под номером %d относится к лету.\n", month_number);
    } else if (month_number == 9 || month_number == 10 || month_number == 11) {
        printf("Месяц под номером %d относится к осени.\n", month_number);
    }
}

// 6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
void task6() {
    int age = 0;
    printf("\nВведите возраст человека (от 1 до 150): ");
    scanf("%d", &age);

    if (age < 1 || age > 150) {
        printf("Ошибка! Возраст человека должен быть от 1 до 150.\n");
        return;
    }

    int age_mod = age % 10;
    if (age_mod == 0 || age_mod == 5 || age_mod == 6 || age_mod == 7 || age_mod == 8 || age_mod == 9) {
        printf("%d лет.\n", age);
    } else if (age_mod == 2 || age_mod == 3 || age_mod == 4) {
        printf("%d года.\n", age);
    } else if (age_mod == 1) {
        printf("%d год.\n", age);
    }
}

// 7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). Требуется определить, относятся поля к одному цвету или нет.
struct Point {
    int x;
    int y;
};

void task7() {
    struct Point point1;
    struct Point point2;

    printf("\nВведите координаты первого поля: ");
    printf("Введите x1: ");
    scanf("%d", &point1.x);
    printf("Введите y1: ");
    scanf("%d", &point1.y);
    printf("Введите x2: ");
    scanf("%d", &point2.x);
    printf("Введите y2: ");
    scanf("%d", &point2.y);

    if ((point1.x < 1 || point1.x > 8) ||
        (point1.y < 1 || point1.y > 8) ||
        (point2.x < 1 || point2.x > 8) ||
        (point2.y < 1 || point2.y > 8)) {
            printf("\nОшибка! Координаты шахматной доски могут принимать значения от 1 до 8.\n");
            return;
        }

    if ((point1.x + point1.y) % 2 == (point2.x + point2.y) % 2) {
        printf("\nПоля имеют одинаковые цвета.");
    } else {
        printf("\nПоля имеют разные цвета.");
    }
}

// 8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
void task8() {
    double first = 0;
    double second = 0;

    printf("\nВведите a: ");
    scanf("%lf", &first);
    printf("\nВведите b: ");
    scanf("%lf", &second);

    double first_square = first*first;
    double second_square = second*second;

    double first_cube = first_square*first;
    double second_cube = second_square*second;

    printf("\nКвадрат первого числа: %lf\nКуб первого числа: %lf\nКвадрат второго числа: %lf\nКуб второго числа: %lf\n",
        first_square, first_cube, second_square, second_cube);
}

// 9. Даны целые положительные числа N и K. Используя только операции сложения и вычитания, найти частное от деления нацело N на K, а также остаток от этого деления.
void task9() {
    int n = 0;
    int k = 0;

    printf("\nВведите N: ");
    scanf("%d", &n);
    printf("\nВведите K: ");
    scanf("%d", &k);

    if (n < 0 || k < 0) {
        printf("Ошибка! Числа должны быть положительными.");
        return;
    }

    int quotient = 0;
    int remainder = 0;

    while (n >= k) {
        quotient += 1;
        n -= k;
    }
    remainder = n;

    printf("\nЧастное: %d\nОстаток: %d\n", quotient, remainder);
}

// 10. Дано целое число N (> 0). С помощью операций деления нацело и взятия остатка от деления определить,
// имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False.
void task10() {
    int n = 0;

    printf("\nВведите N: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("\nОшибка! Число N должно быть больше 0 (N > 0).\n");
        return;
    }

    bool is_odd = false;
    do {
        if (n % 10 % 2 == 1) {
            is_odd = true;
        }
        n /= 10;
    } while (n != 0 && !is_odd);

    if (is_odd) {
        printf("\nВ числе есть нечетные цифр.\n");
    } else {
        printf("\nВ числе нет нечетных цифр.\n");
    }
}

// 11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.
void task11() {
    int exit_code = 0;
    int input_number = 0;
    int count = 0;
    int sum = 0;

    printf("\nВводите числа. Число 0 будет означать конец ввода.\n");
	do {
        printf("Ваше число: ");
        scanf("%d", &input_number);

        if (input_number > 0 && input_number % 10 == 8) {
            ++count;
            sum += input_number;
        }

	} while(input_number != exit_code);

    double mean = sum / count;

    printf("Среднее арифметичкское всех положительных четных чисел, оканчивающихся на 8: %lf", mean);
}