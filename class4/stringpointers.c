#include<stdio.h>

int main (void) {
  char s1[] = "Hello";
  char *p = "World";
  int ii; 

  printf("s1[] and *p\n");
  printf("s1: %p %s\n", (void *) &s1, s1);
  printf("p: &p=%p, p=%p %s\n", (void *) &p, p, p);

  printf("\ns1[0] and *p as characters\n");
  printf("s1: %p %c\n", (void *) &s1, s1[0]);
  printf("p: &p=%p, p=%p %c\n", (void *) &p, p, *p);

  printf("\nAfter p++\n");
  p++;
  printf("s1: %p %s\n", (void *) &s1, s1);
  printf("p: &p=%p, p=%p %s\n", (void *) &p, p, p);

  printf("\nS1 Character by character\n");
  for(ii=0;ii<6;ii++) {
    printf("s1[%d] = %c [%d] (%p)\n", ii, s1[ii], s1[ii], &s1[ii]);
  }

  p--;  /* Undo what was done before */
  printf("\np Character by character - LIKE AN ARRAY?!?!?\n");
  for(ii=0;ii<6;ii++) {
    printf("p[%d] = %c [%d] (%p)\n", ii, p[ii], p[ii], &p[ii]);
  }
  printf("\np Character by character - pointer arithmetic\n");
  for(ii=0;ii<6;ii++) {
    printf("*(p+%d) = %c [%d] (%p)\n", ii, *(p+ii), *(p+ii), &*(p+ii));
  }
  printf("\np Character by character - pointer increment\n");
  while (*p) {
    printf("*p = %c [%d] (%p)\n", *p, *p, &*p);
    p++;
  }

  return 0;
}
