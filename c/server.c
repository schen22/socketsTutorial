#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 2222

int main(int argc, char *argv[]) {
  // create socket
  // family, type, protocol
  int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  
  // create socket address
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof addr); // to make sure struct is empty

  addr.sin_family = AF_INET;
  // translate to network byte order due to system having little endian vals
  addr.sin_port = htons(2222);
  addr.sin_addr.s_addr = INADDR_ANY;
  
  // bind to port
  int status = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
  if (status == -1) {
    printf("failed to bind");
  }

  printf("binding status = %d\n", status);
  printf("port no = %hu\n", addr.sin_port);

  // listen
  int listenStatus = listen(sockfd, 5);
  if (listenStatus == -1) {
    printf("faled to begin listening");
  }

  printf("server: waiting for connections...\n");
  struct sockaddr_in client_addr;
  socklen_t addr_size;
  
  while (1) {
    // accept continuously from clients
    int new_fd = accept(sockfd, (struct sockaddr*)&client_addr, &addr_size);
    if (new_fd == -1) {
      printf("failed to begin accepting messages");
    }
    printf("beginning to listen on port: %hu\n", addr.sin_port);      
    send(new_fd, "hello, world!\n", 14, 0);
    //write(new_fd, "hello, world!", 14);
    char buffer[256];
    int read_status = read(new_fd, buffer, 255);
    if (read_status < 0) {
        printf("error reading message\n");
    } else {
        printf("received message: %s\n", buffer);
    }

  }
  return 0;
}
