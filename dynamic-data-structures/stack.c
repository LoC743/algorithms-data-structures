#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100

char stack[MAX_STACK_SIZE] = {0};
int current_idx = 0;

void clear_stack() {
    current_idx = 0;
}

bool is_empty() {
    return current_idx == 0;
}

bool is_full() {
    return current_idx == MAX_STACK_SIZE;
}

int get_size() {
    return current_idx;
}

void push(char value) {
    stack[current_idx++] = value;
}

char pop() {
    if (is_empty()) {
        printf("[Ошибка!] Стэк уже пуст.");
        exit(-1);
    }

    return stack[--current_idx];
}

char get_top_value() {
    char ch = pop();
    push(ch);
    return ch;
}