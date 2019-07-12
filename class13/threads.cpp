#include<iostream>
#include<thread>
#include<mutex>

// To compile:
//   g++ threads.cpp --std=c++11 -pedantic -Wall -pthread

using namespace std;

mutex m;
int num = 0;

// This function counts to 10 with 1 second delay between numbers.
//   The tabs argument lets us differentiate between different 
//   threads visually.
void count_to_ten(int tabs) {
  for (int jj=0;jj<10;++jj) {
    //  The next line locks the output stream so the threads don't
    //    write over each other. Try commenting it out to see what
    //    happens.
    unique_lock<mutex> output_mutex(m);
    for (int ii=0;ii<tabs;++ii) {
      cout << "\t";
    }
    cout << jj << "(" << ++num << ")" << endl;
    // Free the mutex
    output_mutex.unlock();

    // wait a second
    this_thread::sleep_for(chrono::milliseconds(1000));
  }
}

int main() {
  const int numThreads = 6;
  thread t[numThreads];

  for(int ii=0;ii<numThreads;++ii) {
    t[ii] = thread(count_to_ten,ii);
  }

  for(int jj=0;jj<numThreads;++jj) {
    t[jj].join();
  }

  return 0;
}
