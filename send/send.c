#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv){
    int sd;
    struct sockaddr_in addr;

    if((sd=socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("socket failed.\n");
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(4001);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(sendto(sd, "ohohohoho~~~~~", 17, 0, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        perror("sendto failed.\n");
        return -1;
    }

    close(sd);

    return 0;
}
