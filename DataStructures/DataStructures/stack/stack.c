#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


Stack* createStack(int capacity) {

	if (capacity <= 0) {
		return NULL;
	}

	Stack* stack = (Stack*)malloc(sizeof(Stack));

	if (!stack) {
		return NULL;
	}

	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));

	if (!stack->array) {
		free(stack);
		return NULL;
	}

	return stack;
}

void destroyStack(Stack* stack) {
	if (stack) {
		free(stack->array);
		free(stack);
	}
}

bool isFull(Stack* stack) {
	if (!stack) {
		return false;
	}
	if (stack->top == stack->capacity -1)
	{
		return true;
	}
	return false;
}

bool isEmpty(Stack* stack) {
	if (!stack) {
		return false;
	}
	if (stack->top == -1)
	{
		return true;
	}
	return false;
}

void push(Stack* stack, int item) {
	if (!stack) {
		return;
	}
	if (isFull(stack)) {
		printf("Stack overflow\n");
		return;
	}
	stack->top++;
	stack->array[stack->top] = item;
}

int pop(Stack* stack) {
	if (!stack) {
		return -1;
	}
	if (isEmpty(stack)) {
		printf("Stack underflow\n");
		return -1;
	}
	int item = stack->array[stack->top];
	stack->top--;
	return item;
}

int peek(Stack* stack) {
	if (!stack) {
		return -1;
	}
	if (isEmpty(stack)) {
		printf("Stack is empty\n");
		return -1;
	}
	int item = stack->array[stack->top];
	return item;
}