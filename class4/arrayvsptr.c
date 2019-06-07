#include<stdio.h>

#define COUNT 16

void print_array(char ar[], int size) {
  for(int ii=0; ii<size; ii++) {
     printf("%2d: ar[%2d]=%c\n", ii, ii, ar[ii]);
  }
  printf("\t\t\tSize of ar: %lu\n\n", sizeof(ar));
}

void print_pointer(char * ptr, int size) {
  for(int ii=0; ii<size; ii++) {
     printf("%2d: *(ptr+%2d)=%c\n", ii, ii, *(ptr+ii));
  }
  printf("\t\t\tSize of ptr: %lu\n\n", sizeof(ptr));
}


int main(void) {
  char array[] = "ABCDEFGHIJKLMNOP"; /* char array */
  int nums[COUNT];
  char * ptr = "ZYXWVUTSRQPONMLK";   /* pointer to char */
  int ii;
   
  printf("Sizes: array: %lu,  ptr: %lu,  nums: %lu\n", sizeof(array), sizeof(ptr), sizeof(nums)); 

  for(ii=0;ii<COUNT;ii++) {
    nums[ii]=ii;
  }
  for(ii=0;ii<COUNT;ii++) {
    printf("array[%2d]=%c *(ptr+%2d)=%c, nums[%2d]=%2d\n", ii, array[ii], ii, *(ptr+ii), ii, nums[ii]);
  }

  printf("\nprint_array(array, COUNT)\n");
  print_array(array, COUNT);
  printf("\nprint_array(ptr, COUNT)\n");
  print_array(ptr, COUNT);

  printf("\nprint_pointer(array, COUNT)\n");
  print_pointer(array, COUNT);
  printf("\nprint_pointer(ptr, COUNT)\n");
  print_pointer(ptr, COUNT);
  /* 
  printf("\nprint_pointer(nums, COUNT)\n");
  print_pointer(nums, COUNT);
  */

 /* array indexing */
  printf("\n\narray indexing:\n  ");
  for(ii=0;ii<5;ii++) {
    printf("%d ", array[ii]);
  }
  printf("\n");

  /* pointer arithmetic */
  printf("pointer arithmetic:\n  ");
  for(ii=0;ii<5;ii++) {
    printf("%d ", *(ptr+ii));
  }
  printf("\n");

  /* array indexing with pointer variable */
  printf("\narray indexing with pointer variable:\n  ");
  for(ii=0;ii<5;ii++) {
    printf("%d ", ptr[ii]);
  }
  printf("\n");

  /* pointer arithmetic with an array name */
  printf("pointer arithmetic with an array name:\n  ");
  for(ii=0;ii<5;ii++) {
    printf("%d ", *(array+ii));
  }
  printf("\n");

  printf("Are arrays and pointers the same?\n");
  printf("  size of arr=%lu\n", sizeof(array));
  printf("  size of ptr=%lu\n", sizeof(ptr));

  ptr=array;
  /* pointer arithmetic */
  printf("after ptr=array:\n  ");
  for(ii=0;ii<5;ii++) {
    printf("%d ", *(ptr+ii));
  }
  printf("\n");

  /* 
  array=ptr;    // Not allowed!
  */

  return 0;
}
