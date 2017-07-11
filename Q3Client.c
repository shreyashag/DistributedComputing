#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<time.h>

int main() {
  int sockfd;
  char buf[50];
  struct sockaddr_in client;

  sockfd= socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  client.sin_family=AF_INET;
  client.sin_addr.s_addr=inet_addr("127.0.0.1");
  client.sin_port=htons(5000);

  connect(sockfd,(struct sockaddr*)&client,sizeof(client));
  printf("Connected to server\n");
  recv(sockfd,buf,50,0);
  printf("Message from server: %s", buf);
  close(sockfd);
  exit(0);
}
