#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int num = 0;

int main() {
  int n = 0;
  char c = 'X';
  int pid;
  pid_t childwait;

  printf("[%c]: Before fork: n=%d\n", c, n);
  sleep(2);

  pid = fork();
  /* child */
  if (pid == 0) {
    n = 1;
    c = 'C';
    printf("Child process.  n=%d, returned PID=%d\n", n, pid);
    for(int ii=0;ii<10;ii++) {
       printf("\t\t\t\t\t\tC%d (%d)\n",ii, ++num);
       sleep(2);
    }
    printf("Child process: complete\n");
  }
  else {
    c = 'P';
    printf("Parent process.  n=%d, child's PID=%d\n", n, pid);
    for(int ii=0;ii<10;ii++) {
       printf("\t\t\tP%d (%d)\n",ii, ++num);
       sleep(1);
    }
    wait(&childwait);
    printf("Parent process: child complete\n");
  }
  
  printf("[%c]: After fork: n=%d\n", c, n);
  sleep(2);

  exit(0);
}
