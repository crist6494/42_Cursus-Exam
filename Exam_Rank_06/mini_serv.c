#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX_CLIENTS 13000
#define BUFFER_SIZE 200000

// COPIED FROM SUBJECT main.c
int extract_message(char **buf, char **msg)
{
    char    *newbuf;
    int     i;
    *msg = 0;
    if (*buf == 0)
        return (0);
    i = 0;
    while ((*buf)[i])
    {
        if ((*buf)[i] == '\n')
        {
            newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
            if (newbuf == 0)
                    return (-1);
            strcpy(newbuf, *buf + i + 1);
            *msg = *buf;
            (*msg)[i + 1] = 0;
            *buf = newbuf;
            return (1);
        }
        i++;
    }
    return (0);
}

// COPIED FROM SUBJECT main.c
char *str_join(char *buf, char *add)
{
    char    *newbuf;
    int     len;
    if (buf == 0)
        len = 0;
    else
        len = strlen(buf);
    newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
    if (newbuf == 0)
        return (0);
    newbuf[0] = 0;
    if (buf != 0)
        strcat(newbuf, buf);
    free(buf);
    strcat(newbuf, add);
    return (newbuf);
}

void exitErr(char *msg){
    if(msg == NULL)
        msg = "Fatal error\n";
    write(2, msg, strlen(msg));
    exit(1);
}

void sendMsg(int sock_id, int maxSock, char *msg, int clients[MAX_CLIENTS][2],  fd_set *write_fd)
{
    for(int i = 0; i <= maxSock; i++){
        if(i != sock_id && clients[i][0] > 0 && FD_ISSET(i, write_fd))
            send(i, msg, strlen(msg), 0);
    }
}

void handleMsg(int sock_id, char *buff, char **messages){
    if(messages[sock_id] != NULL)
        messages[sock_id] = str_join(messages[sock_id], buff);
    else{
        messages[sock_id] = calloc(sizeof(char), strlen(buff) + 1);
        strcpy(messages[sock_id], buff);
    }
}

int main(int ac, char **av){
    if(ac != 2)
        exitErr("Wrong number of arguments\n");

    int serverSock = socket(AF_INET, SOCK_STREAM, 0);

    if(serverSock < 0)
        exitErr(0);
		
    int maxSock = serverSock;

    struct sockaddr_in conf = {0};
    conf.sin_family = AF_INET;
    conf.sin_port = htons(atoi(av[1]));
    conf.sin_addr.s_addr = htonl(2130706433);

    if(bind(serverSock, (struct sockaddr *)&conf, sizeof(conf)) != 0)
        exitErr(0);
    if(listen(serverSock, 120) != 0)
        exitErr(0);

    int clients[MAX_CLIENTS][2];
    char *messages[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];

    fd_set work_fd, read_fd, write_fd;
    FD_ZERO(&work_fd);
    FD_SET(serverSock, &work_fd);

    int next_id = 0;

    while(1)
	{
        read_fd = write_fd = work_fd;
        if(select(maxSock + 1, &read_fd, &write_fd, NULL, NULL) < 0)
            continue;
        for(int sock_id = 0; sock_id <= maxSock; sock_id++)
		{
            if(FD_ISSET(sock_id, &read_fd))
			{
                if(sock_id == serverSock)
				{
                    int newClient = accept(serverSock, NULL, NULL);
                    if(newClient < 0)
                        continue;
                    if(newClient > maxSock)
                        maxSock = newClient;
                    clients[newClient][0] = newClient;
                    clients[newClient][1] = next_id++;
                    bzero(buffer, BUFFER_SIZE);
                    sprintf(buffer, "server: client %d just arrived\n", clients[newClient][1]);
                    sendMsg(newClient, maxSock, buffer, clients, &write_fd);
                    FD_SET(newClient, &work_fd);
                }
                else
				{
                    bzero(buffer, BUFFER_SIZE);
                    ssize_t bytes_read = recv(sock_id, buffer, BUFFER_SIZE - 1, 0);
                    if(bytes_read <= 0){
                        bzero(buffer, BUFFER_SIZE);
                        sprintf(buffer, "server: client %d just left\n", clients[sock_id][1]);
                        sendMsg(sock_id, maxSock, buffer, clients, &write_fd);
                        clients[sock_id][0] = 0;
                        clients[sock_id][1] = 0;
                        free(messages[sock_id]);
                        messages[sock_id] = NULL;
                        close(sock_id);
                        FD_CLR(sock_id, &work_fd);
                    }
                    else
					{
                        handleMsg(sock_id, buffer, messages);
                        if(strstr(messages[sock_id], "\n") != NULL)
						{
                            while(1)
							{
                                char *msg;
                                int ret_ex = extract_message(&messages[sock_id], &msg);
                                if(ret_ex < 0)
                                    exitErr(0);
                                else if(ret_ex == 0)
                                    break;
                                bzero(buffer, BUFFER_SIZE);
                                sprintf(buffer, "client %d: %s", clients[sock_id][1], msg);
                                sendMsg(sock_id, maxSock, buffer, clients, &write_fd);
                                free(msg);
                            }
                        }
                    }
                }
            }
        }
        while(clients[maxSock][0] <= 0)
            maxSock--;
    }
}
