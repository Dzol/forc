#include <stdio.h>

const int SIZE = 64;

// Stack Stuff

struct Stack {
  int i;
  int a[SIZE];
} p_stack, r_stack;

void stack_init(Stack* s) {
  s->i = 0;
}

bool stack_empty(Stack* s) {
  return s->i == 0;
}

void stack_push(Stack* s, int x) {
  if (s->i < SIZE) {
    s->a[s->i++] = x;
  }
}

int stack_pop(Stack* s) {
  return s->a[--(s->i)];
}

void stack_print(Stack* s) {
  printf("<%i> ", s->i);
  for (int j = 0; j < s->i; ++j){
    printf("%i ", s->a[j]);
  }
  printf("\n");
}

// Forth Words - Stack Manipulation

void duplicate() {
  if (!stack_empty(&p_stack)) {
    int x = stack_pop(&p_stack);
    stack_push(&p_stack, x);
    stack_push(&p_stack, x);
  }
  else {
    printf("Nah! Not dupin' bro.\n");
  }
}

// Forth Words - Integer Arithmetic

void star() {
  if (p_stack.i >= 2) {
    int x = stack_pop(&p_stack);
    int y = stack_pop(&p_stack);
    stack_push(&p_stack, x*y);
  }
  else {
    printf("Nah! Not starin' bro.\n");
  }
}

// Dictionary Stuff

typedef void (* funcptr)();

funcptr DICT[SIZE] = {
  &duplicate,
  &star,
};

// Test

int main() {
  stack_init(&p_stack);
  stack_print(&p_stack);

  stack_push(&p_stack, 3);
  stack_print(&p_stack);

  DICT[0](); // duplicate()
  stack_print(&p_stack);

  DICT[1](); // star()
  stack_print(&p_stack);

  if (!stack_empty(&p_stack)) {
    printf("POP = %i\n", stack_pop(&p_stack));
  }
  stack_print(&p_stack);

  return 0;
}
