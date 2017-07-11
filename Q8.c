#include<stdio.h>
#include<unistd.h>
#define MAX 10

int max(int a, int b){
  int x = a>b? a:b;
  return x;
}

void main(){
  int numberOfEventsP1,numberOfEventsP2;
  int timerP1[MAX],timerP2[MAX];
  int dependencyMatrix[MAX][MAX];
  int i,j,k;
  printf("Enter the number of events in Process 1 then in Process 2 (less than 10)\n");
  scanf("%d %d",&numberOfEventsP1,&numberOfEventsP2);
  for (i = 0 ; i < numberOfEventsP1; i++){
    // printf("%d \t",i );
    timerP1[i]=i+1;
    }
  for (j = 0 ; j < numberOfEventsP2; ++j){
    // printf("%d \t",j );
    timerP2[j]=j+1;
  }

  printf("P1 : ");      // print the output
  for (i = 0 ; i < numberOfEventsP1; i++)
    printf("%d\t",timerP1[i]);

  printf("\nP2 : ");      // print the output
  for (j = 0 ; j < numberOfEventsP2; j++)
    printf("%d\t",timerP2[j]);

  printf("\nEnter the dependencyMatrix, 1 if P1>P2, -1 if P2>P1, 0 otherwise\n");

  for (i=0;i<numberOfEventsP1;i++){
    // printf("\nP1=%d",i);
    for (j=0;j<numberOfEventsP2;j++){
      printf("P1=%d P2=%d \t",i+1,j+1);
      scanf("%d",&dependencyMatrix[i][j]);
    }
  }

  //Now calculate

  for ( i=0;i<numberOfEventsP1;i++){
    for (j=0;j<numberOfEventsP2;j++){
      if(dependencyMatrix[i][j]==1){
        timerP2[j]=max(timerP2[j],timerP1[i]+1);
        for (k=j;k<numberOfEventsP2;k++)
          timerP2[k+1]=timerP2[k]+1;
      }
      else if(dependencyMatrix[i][j]==-1){
        timerP1[i]=max(timerP1[i],timerP2[j]+1);
        for (k=i;k<numberOfEventsP1;k++)
          timerP1[k+1]=timerP1[k]+1;
      }
    }
  }

  //now print the timestamps
  printf("P1 : ");      // print the output
  for (i = 0 ; i < numberOfEventsP1; i++)
    printf("%d\t",timerP1[i]);
  printf("\nP2 : ");      // print the output
  for (j = 0 ; j < numberOfEventsP2; j++)
    printf("%d\t",timerP2[j]);




}
