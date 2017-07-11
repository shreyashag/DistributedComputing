#include<stdio.h>
#include<pthread.h>

#define NTHREADS 10
int counter=0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *thread_function (void *dummyPtr) {
  pthread_mutex_lock(&mutex1);
  printf("\nLock acquired, by thread %ld incrementing counter value",pthread_self());
  printf("\nCounter value is now %d",++counter);
  pthread_mutex_unlock(&mutex1);
}

void main(){
  pthread_t thread_id[NTHREADS];
  int i,j;

  for (i =0 ; i<NTHREADS;i++){
    pthread_create(&thread_id[i],NULL,thread_function,NULL);
  }

  for ( j =0 ; j<NTHREADS;j++){
    pthread_join(thread_id[j],NULL);
  }

  printf("\nFinal Counter value is %d\n",counter);
}
