#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define MAX 1024
#define PORT 7080


int main()
{
	int sockfd, cf,n;
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
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) <0 0) {
		printf("connection with the server failed...\n");
		return EXIT_FAILURE;
	}
	else
		printf("connected to the server..\n");

	bzero(buff, MAX);
    bzero(msg, MAX);
        
	printf("Enter the message:");
	fgets(msg,MAX,stdin);
	strtok(msg,"\n");
	
	s = send(socketfd,msg, strlen(msg),0);
	f(s<0){
		printf("send problem");
		return EXIT_FAILURE;
	}
	
	s = send(cf,msg,strlen(msg),0);
	if(s<0){
		printf("send problem");
		return EXIT_FAILURE;
	}
	
	n = recv(cf, buff, sizeof(buff),0);
	write(1,buff,s);
	
	close(sockfd);
	return EXIT_FAILURE;
}
