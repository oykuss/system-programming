#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX 1024
#define PORT 7080
#define SIZE sizeof(struct sockaddr_in) 

int main()
{
    int sockfd, cf, len, n, s;
    struct sockaddr_in servaddr, cliaddr;
    char buff[MAX];
    char msg[MAX];
   
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        return EXIT_FAILURE;
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
   
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
   
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) < 0) {
        printf("socket bind failed...\n");
        return EXIT_FAILURE;
    }
    else
        printf("Socket successfully binded..\n");
   

    if ((listen(sockfd, 5)) < 0) {
        printf("Listen failed...\n");
        return EXIT_FAILURE;
    }
    else
        printf("Server listening..\n");
    
	len = sizeof(cliaddr);

    cf = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
    if (cf < 0) {
        printf("server accept failed...\n");
        return EXIT_FAILURE;
    }
    else
        printf("server accept the client...\n");
   
    while(1) {
        bzero(buff, MAX);
        bzero(msg, MAX);

        n = recv(cf, buff, sizeof(buff),0);
		if(n<0){
			printf("read problem");
			return EXIT_FAILURE;
		}
	

		printf("Enter the message:");
		fgets(msg,MAX,stdin);
		strtok(msg,"\n");
		
		s = send(cf,msg,strlen(msg),0);
		if(s<0){
			printf("send problem");
			return EXIT_FAILURE;
		}
		
		close(cf);
    }
    
   
    close(sockfd);
    return EXIT_FAILURE;
}
