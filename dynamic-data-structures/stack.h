#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

void clear_stack();

bool is_empty();

bool is_full();

void push(char value);

char pop();

int get_size();

char get_top_value();

#endif