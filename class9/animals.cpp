#include<iostream>

using namespace std;

class Animal {
  protected:
    string id;

  public:
    Animal(string s = "Generic Animal") {  // Default value = "Generic Animal"
      id = s;
    }

    // Pure virtual method - must be overridden by any non-abstract 
    //  derrived class.
    virtual void speak() = 0;

    // Virtual method - can be overridden by the child class.  The type of
    //  the *object* being pointed to determines the method that gets called.
    virtual void move() { cout << "  " << id << ": I'm moving like an animal!" << endl; }
  

    // Non-virtual method - can overridden by the child class.  The 
    //  type of the *pointer* determines the method that gets called.
    void name() { cout << "  I am " << id << endl; }
};
  
class Dog : public Animal {
  public:
    Dog(string s = "Dog") : Animal(s) {}

    void speak() { cout << "  " << id << ": Woof!" << endl; }
    void move() { cout << "  " << id << ": Run around!" << endl; }
    void fetch() { cout << "  " << id << ": Ball! Ball! " << endl; }
};

class Cat : public Animal {
  public:
    Cat(string s="Cat") : Animal(s) {}
    void speak() { cout << "  " << id << ": Meow!" << endl; }
    void name() { cout << "  My names is none of your business" << endl; }
};

int main() {

  // Animal a;  // Can't instantiate an abstract class
  Dog d("Rover");
  Dog * dptr;
  Dog &dogRef = d;
  Cat c("Whiskers");
  Cat * cptr;
  Cat &catRef = c;
  Animal *danimal, *canimal;

/*  We cannot instantiate an abstract class!
  cout << "C++ Inheritance & Polymorphism example" << endl;
  cout << endl << "Animal object: " << endl;
  a.speak();
  a.move();
  a.name();

  cout << endl << "Animal pointer to an Animal object: " << endl;
  Animal * aptr = new Animal("Peter");
  aptr->speak();
  aptr->move();
  aptr->name();
*/

  cout << endl << "Dog object: " << endl;
  d.speak();
  d.move();
  d.name();
  d.fetch();

  cout << endl << "Dog reference to a Dog object: " << endl;
  dogRef.speak();
  dogRef.move();
  dogRef.name();
  dogRef.fetch();

  cout << endl << "Dog pointer to a Dog object: " << endl;
  dptr = new Dog("Rocket");
  dptr->speak();
  dptr->move();
  dptr->name();
  dptr->fetch();

  cout << endl << "Animal pointer to an Dog object: " << endl;
  danimal = dptr;
  danimal->speak();
  danimal->move();
  // danimal->fetch();  // Animals do not know how to fetch
  // ((Dog *) danimal)->fetch();  // If necessary, you can cast
  danimal->name();

  cout << endl << "Cat object: " << endl;
  c.speak();
  c.move();
  c.name();

  cout << endl << "Cat reference to a Cat object: " << endl;
  catRef.speak();
  catRef.move();
  catRef.name();

  cout << endl << "Cat pointer to a Cat object: " << endl;
  cptr = new Cat("Peanut");
  cptr->speak();
  cptr->move();
  cptr->name();

  cout << endl << "Animal pointer to an Cat object: " << endl;
  canimal = cptr;
  canimal->speak();
  canimal->move();
  canimal->name();

  cout << endl << "Animal reference to a Cat object: " << endl;
  Animal & animalRef = *cptr;  // Need to dereference
  animalRef.speak();
  animalRef.move();
  animalRef.name();

  cout << endl << "Array of animal pointers: " << endl;
  Animal * pets[2];
  pets[0] = &d;
  pets[1] = cptr;
  for (int ii=0;ii<2;ii++) {
    pets[ii]->speak();
    pets[ii]->move();
    pets[ii]->name();
  }

  return 0;
}
