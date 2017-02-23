
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define PORT "3490"  // los usuarios se van a conectar a este puerto
#define BACKLOG 10	 // cantidad de colas de conexiones que mantienen

void sigchld_handler(int s);

void *get_in_addr(struct sockaddr *sa);
