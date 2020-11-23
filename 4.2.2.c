#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;
	char messages[2000];

	//create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if(socket_desc == -1)
        {
                printf("could not create socket");
        }

	//prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
        server.sin_port = htons(8888);

	//bind
	if(bind(socket_desc,(struct sockaddr *)&server, sizeof(server))<0)
	{
		puts("bind failed");
		return 1;
	}
	puts("bind done");

	//listen
	listen(socket_desc, 3);

	//accept incoming connection
	puts("waiting for incoming connection");
	c=sizeof(struct sockaddr_in);
	while((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)))
	{
		if(recv(new_socket, messages, 2000, 0) <0)
		{
			puts("receives failed");
			return 1;
		}		
		puts("successful");
		puts("receive");
		puts(messages);

		char msg[]="error";
		send(new_socket, msg,sizeof(msg),0);
	}
}
