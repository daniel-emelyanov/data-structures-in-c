#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity);
void destroyStack(Stack* stack);
bool isFull(Stack* stack);
bool isEmpty(Stack* stack);
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);

#endif 
