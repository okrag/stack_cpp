#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Stack {
  int *pointer;
  int *start;
  int maxSize;
};

struct Stack stack_create(int maxSize) {
  struct Stack stack;

  stack.maxSize = maxSize;
  stack.start = malloc(sizeof(int) * maxSize);
  stack.pointer = stack.start;

  return stack;
}

int stack_size(struct Stack* stack) {
  return stack->pointer - stack->start;
}

bool stack_full(struct Stack* stack) {
  return stack_size(stack) == stack->maxSize;
}
bool stack_empty(struct Stack* stack) {
  return stack_size(stack) == 0;
}

void stack_push(struct Stack* stack, int value) {
  if (stack_full(stack)) {
    return;
  }

  *(stack->pointer) = value;
  stack->pointer++;
}



int stack_pop(struct Stack* stack) {
  if (stack_empty(stack)) {
    return 0;
  }

  stack->pointer--;
  return *(stack->pointer);
}

void stack_destroy(struct Stack* stack) {
  free(stack->start);
  stack->pointer = NULL;
  stack->start = NULL;
}


int main() {
  struct Stack stack = stack_create(10);


  stack_push(&stack, 10);
  stack_push(&stack, 255);

  printf("pop %d\n", stack_pop(&stack));
  printf("pop %d\n", stack_pop(&stack));

  stack_destroy(&stack);

  return 0;
}