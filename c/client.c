#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT 2222

int main(void)
{
  // create socket
  // family, type, protocol
  int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sockfd == -1) {
    printf("failed to create socket");
  }

  // connect to server addr
  struct sockaddr_in server_addr;
  socklen_t addr_size;
  memset(&server_addr, 0, sizeof server_addr);

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(2222);
  server_addr.sin_addr.s_addr = INADDR_ANY;
  
  int status = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

  if (status < 0) {
    printf("failed to connect to server\n");
  }

  printf("Enter message to send:\n");
  char buffer[256];

  memset(&buffer, 0, 256);
  fgets(buffer, 255, stdin);

  // send
  int n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    printf("error writing to server\n");
  }

  memset(&buffer, 0, 256);
  n = read(sockfd, buffer, 255);
  if (n < 0) {
    printf("error reading from server\n");
  }

  printf("%s\n",buffer);
  return 0;
}
