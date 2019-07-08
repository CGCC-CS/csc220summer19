#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

/* gcc pthread.c -ansi -Wall -pedantic -pthread */

#define NUM_THREADS 6

void *count_to_ten(void *tab_count) {
    int ii, jj;
    char buffer[100];
    char tabs[20] = {'\0'};

    /* Set up a string of tab_count tab characters for indention */
    int skip = *((int *) tab_count);
    for(jj=0;jj<skip;jj++) {
        tabs[jj] = '\t';
    }
    tabs[skip] = '\0';

    /* print the numbers up to 10 */
    for (ii=0;ii<10;ii++) {
        sprintf(buffer, "%s%d\n", tabs, ii);
        printf("%s", buffer);
        fflush(stdout);
        sleep(1);
    }
    return NULL;
}

int main() {
  int ii;

  int num[NUM_THREADS];
  pthread_t new_thread[NUM_THREADS];

  for (ii=0;ii<NUM_THREADS;ii++) {
    num[ii] = ii;
  }

  for (ii=0;ii<NUM_THREADS;ii++) {
    int rc;
    if ((rc = pthread_create(&new_thread[ii], NULL, count_to_ten, &num[ii])) != 0) {
      fprintf(stderr, "ERROR code %d calling pthread_create\n",rc);
      return 1;
    }
  }

  for (ii=0;ii<NUM_THREADS;ii++) {
    if (pthread_join(new_thread[ii], NULL) != 0) {
      fprintf(stderr, "Error joining pthread\n");
      return 1;
    }
  }

  return(0);
}
