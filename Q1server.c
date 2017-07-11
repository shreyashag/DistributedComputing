#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){
  int sockfd,len,cs;
  char buf[50];

  struct sockaddr_in server,client;
  pid_t pid;

  sockfd =  socket(AF_INET, SOCK_STREAM, IPPROTO_TCP );
  printf("Socked created sucessfully");

  server.sin_family=AF_INET;
  server.sin_addr.s_addr=INADDR_ANY;
  server.sin_port=htons(5000);

  bind(sockfd,(struct sockaddr *)&server,sizeof(server));
  printf("Binding done\n");
  listen(sockfd,5);
  while(1){
    len = sizeof(client);
    cs = accept(sockfd,(struct sockaddr *)&client,&len);
    printf("client connected\n");
    if((pid=fork())==0){
      printf("In Child\n");
      recv(cs,buf,50,0);
      printf("Message from client: %s \n",buf );
      send(cs,buf,50,0);
      close(cs);
      close(sockfd);
      exit(0);
    }
    close(cs);
  }
return(0);
}
