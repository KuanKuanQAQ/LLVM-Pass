//=============================================================================
// FILE:
//      input_for_hello.c
//
// DESCRIPTION:
//      Sample input file for test
//
// License: MIT
//=============================================================================
#include <stdlib.h>



int foo(int a) {
  return a * 2;
}

int bar(int a, int b, int c) {
  return (a + (a + b) * 2 + c);
}

int fez(int a, int b, int c) {
  return (a + (a + b + c) * 2 + c * 3);
}
// int import(int a, int b);

struct aa {
  int xy;
};

extern int chifan;

struct elevator_mq_ops {
	int (*init)(int, int, int);
	int (*exit)(int, int, int);
};
struct elevator_type
{
	int x_i;
  int (*sched)(int);
	struct elevator_mq_ops ops;
};
static struct elevator_type iosched_bfq_mq = {
	.x_i = 15,
  .sched = foo,
  .ops = {
		.init = bar,
		.exit	= fez,
	},
};


struct ab {
  int al;
}x;

int a = 0;



int main(int argc, char *argv[]) {
  int a = 123;
  int ret = foo(a);
  int (*indirectjump)(int, int, int);
  int randomValue = rand() % 2;
  ret += bar(a, ret, 15);
  ret += fez(a, ret, 123);
  // ret += import(3, 34);
  ret += x.al;
  ret += iosched_bfq_mq.x_i;
  if (randomValue) {
    indirectjump = bar;
  } else {
    indirectjump = fez;
  }
  indirectjump(1, 2, 3);
  // ret += chifan;
  return ret;
}
