printf("Enter 1 to specify client id to speak to ");
bzero(buffer,BUF_SIZE);
retval=read(clientfd,buffer,BUF_SIZE);

if(retval<0){
	perror("Reading Error");
	break;
}
if(stread(buffer)<1){
	printf("Client %d :%s",clientfd,buffer);
}
switch(buffer[0]){
	case '1':
	bcopy(buffer,"Enter client to whom you need to speak");
	write(clientfd,buffer,BUF_SIZE);
	bzero(buffer,BUF_SIZE);
	retval=read(clientfd,buffer,BUF_SIZE);

	if(retval<0){
	perror("Reading Error");
	break;
	}
	
		break;
	case '':
		break;
}

