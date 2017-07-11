#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdint.h>

int main(){
  int shmid,counter;
  int *addr;
  int ch=1;
  key_t key=02577;

  shmid = shmget(key,4096,IPC_CREAT|0666);
  printf("Accessing shared memory at location %d\n",shmid);
  addr = (int *)shmat(shmid,NULL,0);
  printf("Got counter value of %d from server\n",*addr);
  counter=*addr;
  while(ch==1){
    printf("Enter 1 to increment counter, anything else to exit\n");
    scanf("%d",&ch);
    if (ch==1){
      counter++;
      printf("Counter value is now %d\n",counter);
      }
    else
      break;
    }
    return 0;
  }

