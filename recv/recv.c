#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv){
    int sd;
    struct sockaddr_in addr;

    socklen_t sin_size;
    struct sockaddr_in from_addr;
    
    char buf[2048];

    if((sd=socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("socket failed.\n");
        return -1;
    }

    //ソケットに必要な情報を載せる
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4001);
    addr.sin_addr.s_addr =  INADDR_ANY;

    if(bind(sd, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        perror("bind failed.\n");
        return -1;
    }

    memset(buf, 0, sizeof(buf));
    while(1){
      if(recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr *)&from_addr, &sin_size) < 0){
          perror("recvfrom failed.\n");
          return -1;
      }
      printf("%s\n", buf);
    }

    close(sd);

    return 0;
}
