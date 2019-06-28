#include<iostream>

using namespace std;

class MyClass {
  public:
    int *a;
  private:
    int b;

  public:
    MyClass(int x=0) {
      a = new int;
      *a = x;
      b = getCounter();
      cout << "  Constructor " << b << ": " << *a << " (" << a << ")" << endl;
    }


    // Destructor
    ~MyClass() {
      cout << "  Destructor " << b << ": " << *a << " (" << a << ")" << endl;
      delete a;
      a = nullptr;
    }

    // Copy constructor
    MyClass(const MyClass & original) {
      a = new int;
      b = getCounter();
      *a = *(original.a);
      cout << "  Copy Constructor " << b << "{" << original.b << "] : "
               << *a << " (" << a << ")" << endl;
    }

    void print() {
      cout << "  Print " << b << ": " << *a << " (" << a << ")" << endl;
    }

  private:
    static int getCounter() {
      static int counter = 1;  
      return counter ++;
    }
};

void func(MyClass k) {
  cout << " FUNC: begin declare c4" << endl;
  MyClass c4(40);
  cout << " FUNC: end declare c4" << endl;

  cout << " FUNC: print k: ";
  k.print();
  cout << " FUNC: print c4: ";
  c4.print();
  cout << " FUNC: end" << endl;
}

int main() {
  cout << "MAIN: begin declare c1" << endl;
  MyClass c1(10);  // Stack variable (value semantics)
  cout << "MAIN: end declare c1" << endl;

  cout << "MAIN: begin declare c2" << endl;
  MyClass * c2;    // Heap object (reference semantics)
  cout << "MAIN: end declare c2" << endl;

  cout << "MAIN: begin declare c3" << endl;
  MyClass * c3;    // Heap object (reference semantics)
  cout << "MAIN: end declare c3" << endl;

  cout << "MAIN: begin allocate c2" << endl;
  c2 = new MyClass(20);  
  cout << "MAIN: end allocate c2" << endl;

  cout << "MAIN: begin allocate c3" << endl;
  c3 = new MyClass(300);  
  cout << "MAIN: end allocate c3" << endl;
 

  cout << "MAIN: begin call func(c1)" << endl; 
  func(c1);
  cout << "MAIN: end call func(c1)" << endl; 

  cout << "MAIN: begin delete c3" << endl;
  delete c3;
  cout << "MAIN: end delete c3" << endl;

  cout << "MAIN: begin delete c2" << endl;
  delete c2;
  cout << "MAIN: end delete c2" << endl;

  cout << "MAIN: return" << endl;
  return 0;
}
