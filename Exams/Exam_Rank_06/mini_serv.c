#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdlib.h>
#include <stdio.h>

// ========== GIVEN BY EXAM ==========
int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

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

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

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

int		ids[65536];      // client id by fd
char	*bufs[65536];    // client buffer by fd
int		maxfd, nextid, sockfd;
fd_set	active, readset, writeset;

void fatal() {
	write(2, "Fatal error\n", 12);
	exit(1);
}
void send_all(int except, char *msg) {
	for (int fd = 0; fd <= maxfd; fd++)
		if (FD_ISSET(fd, &writeset) && fd != except && fd != sockfd)
			send(fd, msg, strlen(msg), 0);
}

int main(int ac, char **av) {
	if (ac != 2) {
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	// 1. CREATE SOCKET
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
		fatal();

	// 2. BIND TO 127.0.0.1:PORT
	struct sockaddr_in addr;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	addr.sin_port = htons(atoi(av[1]));
	if (bind(sockfd, (void *)&addr, sizeof(addr)) < 0) 
		fatal();
	if (listen(sockfd, 128) < 0) 
		fatal();

	// 3. INIT SELECT
	FD_ZERO(&active);
	FD_SET(sockfd, &active);
	maxfd = sockfd;

	// 4. MAIN LOOP
	while (1) {
		readset = writeset = active;
		if (select(maxfd + 1, &readset, &writeset, NULL, NULL) < 0) 
			fatal();

		for (int fd = 0; fd <= maxfd; fd++) {
			if (!FD_ISSET(fd, &readset)) 
				continue ;

			// NEW CLIENT
			if (fd == sockfd) {
				socklen_t len = sizeof(addr);
				int client = accept(sockfd, (void *)&addr, &len);
				if (client < 0) 
					continue;
				if (client > maxfd) 
					maxfd = client;
				FD_SET(client, &active);
				ids[client] = nextid++;
				bufs[client] = NULL;
				char msg[64];
				sprintf(msg, "server: client %d just arrived\n", ids[client]);
				send_all(client, msg);
				break;
			}
			// EXISTING CLIENT
			else {
				char buf[4096];
				int n = recv(fd, buf, sizeof(buf) - 1, 0);

				// CLIENT LEFT
				if (n <= 0) {
					char msg[64];
					sprintf(msg, "server: client %d just left\n", ids[fd]);
					send_all(fd, msg);
					free(bufs[fd]);
					FD_CLR(fd, &active);
					close(fd);
					break;
				}
				// CLIENT SENT MESSAGE
				else {
					buf[n] = '\0';
					bufs[fd] = str_join(bufs[fd], buf);
					if (!bufs[fd]) 
						fatal();

					char *msg;
					while (extract_message(&bufs[fd], &msg) == 1) {
						char header[32];
						sprintf(header, "client %d: ", ids[fd]);
						send_all(fd, header);
						send_all(fd, msg);
						free(msg);
					}
				}
			}
		}
	}
	return 0;
}
