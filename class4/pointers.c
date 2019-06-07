#include<stdio.h>

int main(void) {
  int x = 20, y = 0x400, z=30;
  int * p = &z;

  /* The '*' in this line & the next 3 lines means 4 different things! */
  int * pointer_type = &y;   /* The '*' indicates that this is a pointer type */
  *pointer_type = 0x4000;    /* The '*' is the de-reference operator */
  x = 10 * 2;                /* The '*' is the multiplcation operator */

  /* What does this line do? */
  /* int * k = *p * 10; */

  printf("x: %16d, %p, %lu\n", x, (void *) &x, sizeof(x));
  printf("y: %16d, %p, %lu\n", y, (void *) &y, sizeof(y));
  printf("z: %16d, %p, %lu\n", z, (void *) &z, sizeof(z));
  printf("p: %16p, %p, %lu  (value of *p = %d)\n", (void *) p, (void *) &p, sizeof(p), *p); 

  printf("\np++ makes p point to the next integer\n");
  p++;
  *p=50;
  printf("y: %16d, %p, %lu\n", y, (void *) &y, sizeof(y));
  printf("p: %16p, %p, %lu  (value of *p = %d)\n", (void *) p, (void *) &p, sizeof(p), *p); 

  printf("\nUse p to change x\n");
  p = &x;
  *p = 60;
  printf("x: %16d, %p, %lu\n", x, (void *) &x, sizeof(x));
  printf("p: %16p, %p, %lu  (value of *p = %d)\n", (void *) p, (void *) &p, sizeof(p), *p);

  printf("\n(*p)++;\n");
  (*p)++;
  printf("x: %16d, %p, %lu\n", x, (void *) &x, sizeof(x));
  printf("p: %16p, %p, %lu  (value of *p = %d)\n", (void *) p, (void *) &p, sizeof(p), *p);

  printf("\n*(--p)\n");
  *(--p)=75;
  printf("y: %16d, %p, %lu\n", y, (void *) &y, sizeof(y));
  printf("p: %16p, %p, %lu  (value of *p = %d)\n", (void *) p, (void *) &p, sizeof(p), *p);

  printf("\n(*(++p))++\n");
  (*(++p))++;
  printf("x: %16d, %p, %lu\n", x, (void *) &x, sizeof(x));
  printf("y: %16d, %p, %lu\n", y, (void *) &y, sizeof(y));
  printf("p: %16p, %p, %lu  (value of *p = %d)\n", (void *) p, (void *) &p, sizeof(p), *p);

  return 0;
}
