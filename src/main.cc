#include <stdio.h>

const int SIZE = 64;

// Stack Stuff

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

// Forth Words - Stack Manipulation

void duplicate() {
  if (!stack_empty()) {
    int x = stack_pop();
    stack_push(x);
    stack_push(x);
  }
  else {
    printf("Nah! Not dupin' bro.\n");
  }
}

// Forth Words - Integer Arithmetic

void star() {
  if (stack.i >= 2) {
    int x = stack_pop();
    int y = stack_pop();
    stack_push(x*y);
  }
  else {
    printf("Nah! Not starin' bro.\n");
  }
}

// Dictionary Stuff

void (*DICT[SIZE])() = {
  &duplicate,
  &star
};

// Test

int main() {
  stack_init();
  stack_print();

  stack_push(3);
  stack_print();

  DICT[0]();
  stack_print();

  DICT[1]();
  stack_print();

  if (!stack_empty()) {
    printf("POP = %i\n", stack_pop());
  }
  stack_print();

  return 0;
}
