#include <stdio.h>

// Stack Stuff

const int SIZE = 64;

struct Stack {
  int i;
  int a[SIZE];
} stack;

void stack_init() {
  stack.i = 0;
}

bool stack_empty() {
  return stack.i == 0;
}

void stack_push(int x) {
  if (stack.i < SIZE) {
    stack.a[stack.i++] = x;
  }
}

int stack_pop() {
  return stack.a[--stack.i];
}

void stack_print() {
  printf("<%i> ", stack.i);
  for (int j = 0; j < stack.i; ++j){
    printf("%i ", stack.a[j]);
  }
  printf("\n");
}

// Test

int main() {
  stack_init();
  stack_print();

  stack_push(3);
  stack_print();

  if (!stack_empty()) {
    printf("POP = %i\n", stack_pop());
  }
  stack_print();

  return 0;
}
