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

// Forth Words

void duplicate() {
  if (!stack_empty()) {
    int x = stack_pop();
    stack_push(x);
    stack_push(x);
  }
  else {
    printf("Nah! Not happenin' bro.\n");
  }
}

// Test

int main() {
  stack_init();
  stack_print();

  stack_push(3);
  stack_print();

  duplicate();
  stack_print();

  if (!stack_empty()) {
    printf("POP = %i\n", stack_pop());
  }
  stack_print();

  return 0;
}
