#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define BUF_SIZE 512

int main(int argc, char *argv[]){

	if(argc < 3){
		printf("SYNTAX: %s [ipaddress] [portno]", argv[0]);
		exit(1);
	}
	
	int sockfd, portno, retval;
	struct sockaddr_in server_addr;
	char buffer[BUF_SIZE];
	portno = atoi(argv[2]);
	
// 1) Socket function
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		perror("Socket creation Error");
		exit(1);
	}
	bzero((char *)&server_addr, sizeof(server_addr));
	
	// set the values in structure
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	if(server_addr.sin_addr.s_addr == -1){
		perror("Inet conversion Error");
		exit(1);
	}
	server_addr.sin_port = htons(portno);
	
// 2) Connect Function	
	if(connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0){
		perror("Connection Error");
		exit(1);
	}
	else{
		printf("\nConnected to the server:\nClient: ");
	}
	
	
	while(1){
		bzero(buffer, BUF_SIZE);
		fgets(buffer, BUF_SIZE, stdin); // takes input only of the given size or less
		
		retval = write(sockfd, buffer, strlen(buffer));
		if(retval < 0){
			perror("Writing Error");
			exit(1);
		}
		if(strncmp(buffer, "exit", 4) == 0)
			break;
		
		bzero(buffer, BUF_SIZE);
		retval = read(sockfd, buffer, BUF_SIZE);
		if(retval < 0){
			perror("Reading Error");
			exit(1);	
		}
		
		if(strncmp(buffer, "exit", 4) == 0){
			printf("Server: %s\n", buffer);
			break;
		}
				
		printf("Server: %sClient: ", buffer);
	}
	
	close(sockfd);
	return 0;	
}
