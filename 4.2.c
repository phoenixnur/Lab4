#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<string.h>

int main(int argc, char *argv[])
{
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;

	//create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(socket_desc == -1)
	{
		printf("could not create socket");
	}
	
	//prepare the sock_addr structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADRR_ANY;
	server.sin_port = htons(8888);
	
	//bind
	if(bind(socket_desc,(struct sockadddr *)&server, sizeof(server))<0)
	{
		puts("bind failed");
	}
	puts("bind done");
	
	//listen
	listen(socket_dec, 3);
	
	//accept incoming connection
	put("waiting for incoming connections");
	c=sizeof(struct sockaddr_in);
	new_socket=accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if(new_socket<0)
	{
		perror("accept failed");
	}
