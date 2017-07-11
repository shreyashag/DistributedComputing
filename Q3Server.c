#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<time.h>
int main(){
  int sockfd,len,cs;
  struct sockaddr_in server,client;
  pid_t pid;
  time_t currentTime;

  sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

  printf("Socket created sucessdfully \n");

  server.sin_family=AF_INET;
  server.sin_addr.s_addr=INADDR_ANY;
  server.sin_port=htons(5000);

  bind(sockfd,(struct sockaddr *)&server, sizeof(server));
  printf("Binding done\n");
  listen(sockfd,5);
  printf("Listenining\n");

  while(1){
    len=sizeof(client);
    cs=accept(sockfd,(struct sockaddr *)&client, &len);
    if((pid=fork())==0){
      printf("In child\n");
      close(sockfd);
      time(&currentTime);
      send(cs,ctime(&currentTime),50,0);
      close(cs);
      exit(0);
    }
    close(cs);
  }
close(sockfd);
exit(0);
}
