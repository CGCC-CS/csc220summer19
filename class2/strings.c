#include<stdio.h>

/* This code is very machine-specific */

#define LEN 20

int main(void) {
  int ii;
  char buff1[LEN];
  char s1[] = "Hello";
  char s2[5] = "world";
  char s3[] = {'S', 't', 'r', 'i', 'n', 'g', '\0'};
  char buff2[LEN];

  for(ii=0;ii<LEN;ii++) {
    buff1[ii] = '#';
    buff2[ii] = '@';
  }

  printf("buff1: %s\n", buff1);
  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);
  printf("s3: %s\n", s3);
  printf("buff2: %s\n", buff2);

  printf("s1 %ld bytes, s2 is %ld bytes\n", sizeof(s1), sizeof(s2));

  /* This is a problem!  C does not do bounds checking */
  printf("\n");
  for(ii=0;ii<20;ii++) {
    printf("s2[%d]: %c (%d)\n", ii, s2[ii], s2[ii]);
  }

  /* More problems! */
  printf("\n");
  s2[5] = '*';
  printf("s2: %s\n", s2);
  s2[6] = '*';
  printf("s2: %s\n", s2);
  s2[17] = '*';
  printf("s1: %s\n", s1);
 
  printf("\n");
  s1[3] = 'Z';
  s1[5] = 43;
  s1[6] = 'X'; 
  printf("s1: %s\n", s1);
  printf("s2: %s\n", s2);
  printf("s3: %s\n", s3);

  return 0;
}
