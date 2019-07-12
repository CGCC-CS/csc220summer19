#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

/* Compile with :
     gcc pthread.c --std=c11 -pedantic -Wall -pthread
*/

#define NUM_THREADS 6

void * count_to_ten(void *tab_count) {
  char buffer[100];
  char tabs[20] = {'\0'};

  /* Set up a string of tab_count tab characters for indention */
  int skip = *((int *) tab_count);
  for(int jj=0;jj<skip;++jj) {
    tabs[jj] = '\t';
  }
  tabs[skip] = '\0';

  /* Print the numbers up to 10 */
  for(int ii=0;ii<10;++ii) {
    sprintf(buffer, "%s%d\n", tabs, ii);
    printf("%s", buffer);
    fflush(stdout);
    sleep(1);
  }
  return NULL;
}

int main() {
  int num[NUM_THREADS];
  pthread_t new_thread[NUM_THREADS];

  for (int ii=0;ii<NUM_THREADS;ii++) {
    num[ii]=ii;
  }

  for(int ii=0;ii<NUM_THREADS;ii++) {
    int rc;
    if (( rc = pthread_create(&new_thread[ii], NULL, count_to_ten, &num[ii])) != 0 ) {
      fprintf(stderr, "ERROR code %d calling pthread_create\n", rc);
      exit(1);
    }
  }

  for(int ii=0;ii<NUM_THREADS;ii++) {
    int rc;
    if ( (rc = pthread_join(new_thread[ii], NULL)) != 0) {
      fprintf(stderr, "ERROR joining pthread %d\n", ii);
      exit(1);
    }
  }

  return 0;
}
