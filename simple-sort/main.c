// Morozov Alexey

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

void task1();
void task2();

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

int* generate_array(size_t size) {
    if (size <= 0) { 
        int* empty_array = (int*) calloc(0, sizeof(int));
        return empty_array;
    }

    int* array = (int*) calloc(size, sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        array[i] = rand() % 101;
    }

    return array;
}

int* create_copy_of_array(int* array, int size) {
    int* copy = (int*) calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        copy[i] = array[i];
    }

    return copy;
}

void print_array(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
}

void swap(int* first, int* second) {
    *first  = *first  ^ *second;
    *second = *first  ^ *second;
    *first  = *second ^ *first;
}

int bubble_sort(int* array, int size) {
    int op_counter = 0;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            ++op_counter;
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
    return op_counter;
}

int bubble_sort_optimized(int* array, int size) {
    int op_counter = 0;
    for (size_t i = 0; i + 1 < size; ++i) {
        for (size_t j = 0; j + 1 < size - i; ++j) {
            ++op_counter;
            if (array[j + 1] < array[j]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
    return op_counter;
}

void task1() {
    int array_size = 0;

    printf("\nВведите размер массива: ");
    scanf("%d", &array_size);

    int* array = generate_array(array_size);
    int* array_copy = create_copy_of_array(array, array_size);
    // printf("Полученный массив: ");
    // print_array(array, array_size);

    // Сортировка пузырьком
    clock_t begin_bubble = clock();
    int bubble_op = bubble_sort(array, array_size);
    clock_t end_bubble = clock();

    printf("\n\n[Bubble sort]: ");
    // print_array(array, array_size);
    double time_spent_bubble = (double)(end_bubble - begin_bubble) / CLOCKS_PER_SEC;
    printf("\nЗатраченное время: %lf", time_spent_bubble);
    printf("\nКоличество операций: %d\n", bubble_op);

    // Сортировка пузырьком с оптимизациями
    clock_t begin_bubble_op = clock();
    int bubble_optimized_op = bubble_sort_optimized(array_copy, array_size);
    clock_t end_bubble_op = clock();

    printf("\n[Bubble sort оптимизированный]: ");
    // print_array(array_copy, array_size);
    double time_spent_bubble_op = (double)(end_bubble_op - begin_bubble_op) / CLOCKS_PER_SEC;
    printf("\nЗатраченное время: %lf", time_spent_bubble_op);
    printf("\nКоличество операций: %d\n", bubble_optimized_op);

    free(array);
    free(array_copy);
}

long int shaker_sort(int* array, int size) {
    long int op_counter = 0;
    int left = 0;
    int right = size - 1;

    while(left <= right) {
        for (int i = right; i > left; --i) {
            ++op_counter;
            if (array[i - 1] > array[i]) {
                swap(&array[i - 1], &array[i]);
            }
        }
        ++left;
        for (int i = left; i < right; ++i) {
            ++op_counter;
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
            }
        }
        --right;
    }

    return op_counter;
}

void task2() {
    int array_size = 0;

    printf("\nВведите размер массива: ");
    scanf("%d", &array_size);

    int* array = generate_array(array_size);
    // printf("Полученный массив: ");
    // print_array(array, array_size);

    clock_t begin = clock();
    long int op_count = shaker_sort(array, array_size);
    clock_t end = clock();

    printf("\n[Shaker sort]: ");
    // print_array(array, array_size);
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nЗатраченное время: %lf", time_spent);
    printf("\nКоличество операций: %ld\n", op_count);

    free(array);
}