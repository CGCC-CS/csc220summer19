#include<iostream>

using namespace std;

class MyDeleteClass {
  private:
    int * a;
    int * b;
    int c;
  public:
    // Constructor
    MyDeleteClass() {
      static int counter = 1;     // Allocated in static memory

      a = new int;                // Allocated on the heap
      *a = counter * 5;
      b = new int[*a];            // Allocated on the heap
      for(int ii=0;ii<*a;ii++) {
         b[ii] = ii;
      }
      counter++;
    }

   // Destructor
   ~MyDeleteClass() {
      delete a;
      a = nullptr;
      delete[] b;    // b points to an array, use delete[]
      b = nullptr;
   }

   void print() {
     cout << "  object " << *a << ", " << c << ": ";
     for(int ii=0;ii<*a;ii++) {
        cout <<b[ii] << " ";
     }
     cout << endl; 
   }
};

int main() {
  MyDeleteClass c1;
  MyDeleteClass *c2 = new MyDeleteClass();

  cout << "c1: ";
  c1.print();
  cout << "c2: ";
  c2->print();
  delete(c2);
  return 0;
}
