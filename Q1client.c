#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){
  int sockfd, cs;
  struct sockaddr_in client;
  char buf[50];
  sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

  client.sin_family = AF_INET;
  client.sin_addr.s_addr=inet_addr("127.0.0.1");
  client.sin_port=htons(5000);
  printf("\nTrying to connect");
  connect(sockfd,(struct sockaddr *)&client, sizeof(client));
  printf("Enter the data to send\n");
  fgets(buf,50,stdin);
  send(sockfd,buf,50,0);
  recv(sockfd,buf,50,0);
  printf("Recieved from server\n %s",buf);
  return 0;
}
