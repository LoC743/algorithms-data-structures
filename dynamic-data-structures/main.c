// Morozov Alexey

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void task4();

int main() {
    task4();
}

int get_priority(char ch) {
    switch (ch) {
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void task4() {
    FILE *fptr;
    fptr = fopen("polish-input.txt","r");

    if(fptr == NULL) {
        printf("[Ошибка]: Файл не найден.");
        return;
    }

    clear_stack();

    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (get_top_value() != '(') {
                if (is_empty()) {
                    printf("\nСкобоки не согласованы.\n");
                    return;
                }
                printf("%c ", pop());
            }
            pop();
        } else if (ch == '-' || ch == '+' || ch == '*' || ch == '/') {
            if (!is_empty()) {
                char top_value = get_top_value();
                while (get_priority(top_value) >= get_priority(ch) && !is_empty()) {
                    char out = pop();
                    printf("%c ", out);
                }
            }
            push(ch);
        } else if (ch != ' ') {
            printf("%c ", ch);
        }
    }

    while (!is_empty()) {
        printf("%c ", pop());
    }

    fclose(fptr);
}