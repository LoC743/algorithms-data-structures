// Morozov Alexey

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void task1();
void task2();
void task3();

int main() {
    char char_choice[3];
	int int_choice = 0;
    int exit_code = -1;

	do {
		printf("\n\033[0;37mМеню: \n");
        printf("-1. Выход\n");
		printf("1. Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.\n");
		printf("2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.\n");
		printf("3. Требуется обойти конем шахматную доску размером NxM, пройдя через все поля доски по одному разу.\n");

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
			default:
                if (int_choice != exit_code) {
                    printf("\n\033[1;31m[ОШИБКА!] Неверный ввод! Попробуйте еще раз.\n");
                }
                break;
		}
	} while(int_choice != exit_code);

    return 0;
}

// 1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов.
// Например, карта:
// 3 3
// 1 1 1
// 0 1 0
// 0 1 0
int** read_file(int rows, int columns) {
    FILE *fptr;
    fptr = fopen("task1-input.txt","r");

    if(fptr == NULL) {
        printf("[Ошибка]: Файл не найден.");
        int** empty_matrix = (int**) calloc(0, sizeof(int*));
        return empty_matrix;
    }

    int** matrix = (int**) calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = calloc(columns, sizeof(int));
    }

    matrix[rows] = NULL;
    int value = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            fscanf(fptr, "%d", &value);
            matrix[i][j] = value;
        }
    }

    fclose(fptr);

    return matrix;
}

void print_matrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int routes(int i, int j, int** map) {
    if (i == 0 || j == 0)
        return 1;
    else if (map[j][i] == 0)
        return 0;
    else
        return routes(i - 1, j, map) + routes(i, j - 1, map);
}

void task1() {
    int rows = 0;
    int columns = 0;

    printf("\nВведите количество строк матрицы: ");
    scanf("%d", &rows);
    printf("\nВведите количество столбцов матрицы: ");
    scanf("%d", &columns);
    
    int** matrix = read_file(rows, columns);
    printf("\nСчитанная матрица:\n");
    print_matrix(matrix, rows, columns);

    printf("\nРешение:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d ", routes(i, j, matrix));
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

// 2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы.
// Update: по аналогии с тем что мы делали на уроке в Excel с двумерной матрицей, нужно сделать программу которая рассчитает сама элементы двумерного массива.
// Нужно чтобы пользователь ввел 2 строки которые сформируют размер матрицы.
// Затем строка за строкой рассчитываем значения элементов. Решение без рекурсии, цикл for внутри другого for.
void task2() {
    
}

// 3. ***Требуется обойти конем шахматную доску размером NxM, пройдя через все поля доски по одному разу.
// Здесь алгоритм решения такой же, как в задаче о 8 ферзях. Разница только в проверке положения коня.
void task3() {
    
}