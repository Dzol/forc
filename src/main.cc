#include <stdio.h>

const int SIZE = 64;

enum {DO_CONST, DO_NATIVE, DONE};

typedef void* Cell;

typedef void (* funcptr)();

struct Literal {
  int type;
  Cell value;
};

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

void stack_push(Stack* s, Cell x) {
  if (s->i < SIZE) {
    s->a[s->i++] = *(int*)(&x);
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
    stack_push(&p_stack, (Cell)x);
    stack_push(&p_stack, (Cell)x);
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
    stack_push(&p_stack, (Cell)(x*y));
  }
  else {
    printf("Nah! Not starin' bro.\n");
  }
}

// Dictionary Stuff

Literal DICT[SIZE] = {
  {DO_CONST,  (Cell)3},
  {DO_NATIVE, (Cell)&duplicate},
  {DO_NATIVE, (Cell)&star},
  {DONE,      NULL}
};

// Test

int main() {

  stack_init(&p_stack);
  Literal* instruction = &DICT[0];

  for (int pc = 1; instruction->type != DONE; instruction = &DICT[pc++]) {
    switch (instruction->type) {
      case DO_CONST:
        stack_push(&p_stack, instruction->value);
        break;
      case DO_NATIVE:
        ((funcptr)(instruction->value))();
        break;
    }
    stack_print(&p_stack);
  }

  return 0;
}
