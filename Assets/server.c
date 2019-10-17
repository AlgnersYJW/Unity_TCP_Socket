#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void main(int argc, char* argv[]) {
	
	char sendBuff[1024];
	int sendNum = 0; 

	struct sockaddr_in serv_addr; 

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, '0', sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1",  &serv_addr.sin_addr.s_addr);
    serv_addr.sin_port = htons(1337); 
    printf("Init\n");

    bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 
    listen(listenfd, 100000);
    printf("Listen\n");

    int connfd = 0;

    while(connfd == 0)
    {
    	connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
    	printf("Num: %d\n", connfd);
    	break;
    }

    printf("Ready!\n");
    

    while(1){
    	
    	sendNum += 1;
    	sprintf(sendBuff,"%d",sendNum);
		send(connfd, sendBuff, strlen(sendBuff), 0);
		printf("Sent!\n");
		usleep(30000);
	}

    return;
}