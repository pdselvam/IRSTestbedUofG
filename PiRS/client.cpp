#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
  int sock = 0, valread;
  struct sockaddr_in serv_addr;
  //char *hello = "Hello from client";
  char hello[] = "Hello from the client";
  char buffer[1024] = {0};
  printf("1\n");
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
  { printf("\n Socket creation error"); return -1;}

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
  { printf("\n Invalid address \n"); return -1;}

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  { printf("\n Connection failed \n"); return -1;}

  printf("2\n");
  send(sock, hello, strlen(hello), 0);
  printf("Hello message send\n");
  valread = read(sock, buffer, 1024);
  printf("%s\n", buffer);
  return 0;
}