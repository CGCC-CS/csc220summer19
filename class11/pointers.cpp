#include<iostream>
#include<string.h>

using namespace std;

int * get_array(int size) {
  int * arr = (int *) malloc(size * sizeof(int));
 return arr;
}

typedef struct {
  int num;
  char * name;
} junk_t;

int main() {
  int array[] = {1, 2, 3, 4, 5, 6};
  int * ptr = get_array(6);
 
  junk_t try1;
  junk_t * try2;

  
  for(int ii=0;ii<6;ii++) {
    *(ptr+ii) = array[ii] * 10;
  }

  for(int ii=0;ii<6;ii++) {
   cout << array[ii] << " : " << *(ptr+ii) << endl;
  }

  try1.num = 20;
  try1.name = (char *) malloc(10 * sizeof(char));
  strncpy(try1.name, "Hello", 10);

  cout << endl;

  // junk_t variable
  cout << "Try1: " << try1.name << " " << try1.num << endl;


  // junk_t variable
  try2 = (junk_t *) malloc(sizeof(junk_t));
  try2->num = 40;
  try2->name = (char *) malloc(10 * sizeof(char));
  strncpy(try2->name, "World", 10);
  cout << "Try2: " << try2->name << " " << try2->num << endl;
  return 0;
}
