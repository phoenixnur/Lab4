#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<string.h>

int main(int argc, char *argv[])
{
        int socket_desc;
        struct sockaddr_in server;
        char *message;
        char server_reply[2000];



        //create socket
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if(socket_desc == -1)
        {
                printf("could not create socket");
        }

        server.sin_addr.s_addr = inet_addr("192.168.0.162"); //server ip
        server.sin_family = AF_INET;
        server.sin_port = htons(8888);

        //connect to remote server
        if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server))<0)
        {
                puts("connect error");
                return 1;
        }

        puts("connected");
        //send some data
        message ="connect";
        if(send(socket_desc, message, strlen(message), 0)<0)
        {
                puts("send failed");
                return 1;
        }
        puts("data send");
        //receive reply from server
        if(recv(socket_desc, server_reply, 2000, 0)<0)
        {
                puts("receive failed");
                return 1;
        }
        puts(server_reply);
	puts("receive");
        return 0;
}
