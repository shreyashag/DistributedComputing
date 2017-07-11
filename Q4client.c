#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<time.h>

int main(){
  int sockfd;
  char buf[50];
  struct sockaddr_in client;
  struct timeval start,stop;

  sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  client.sin_family=AF_INET;
  client.sin_addr.s_addr=inet_addr("127.0.0.1");
  client.sin_port=htons(5000);

  connect(sockfd,(struct sockaddr *)&client,sizeof(client));
  printf("Conencted to server\n");
  gettimeofday(&start,NULL);
  recv(sockfd,buf,50,0);
  gettimeofday(&stop,NULL);
  printf("Message from server: %s\n",buf);
  printf("Round trip time is %ld microseconds\n",stop.tv_usec-start.tv_usec);
  close(sockfd);
  exit(0);
}
