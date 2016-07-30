#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

#include <string.h>

#include "ichat.h"

int prompts(int p_tag, char *response) {

	if (p_tag == P_IDLE) {
		printf("\nWaiting for connections.  Press [ENTER] to start a chat.");
		//cout << "\nWaiting for connections.  Press [ENTER] to start a chat.";
		char msg[50];
		memset(msg, ' ', sizeof msg);
		char *ptr;
		while (true) {
			fgets(msg, sizeof msg, stdin);
			ptr = (char*)memchr(msg, '\n', strlen(msg));
			if (ptr != NULL) {
				break;
			}
		}
		
	} else if (p_tag == P_USERNAME) {
	
		printf("\nPlease enter a username you'd like to use: ");
		char msg[50];
		memset(msg, ' ', sizeof msg);
		char *ptr;
		while (true) {
			fgets(msg, sizeof msg, stdin);
			ptr = (char*)memchr(msg, '\n', strlen(msg));
			if (ptr != NULL) {
				*ptr = '\0';
				break;
			}
		}
		
		strcpy(response, msg);
		
	} else if (p_tag == P_CONNECT) {
	
		printf("\nPlease enter a destination address: ");
		char msg[50];
		memset(msg, ' ', sizeof msg);
		char *ptr;
		while (true) {
			fgets(msg, sizeof msg, stdin);
			ptr = (char*)memchr(msg, '\n', strlen(msg));
			if (ptr != NULL) {
				*ptr = '\0';
				break;
			}
		}
		
		strcpy(response, msg);
		
	} else if (p_tag == P_CHAT) {
	
	
	}
}

int initClient(char* name, char* addr, char* port, int *socket, addrinfo *c_addrinfo) {// name, address, socket, addrinfo

	int retStatus;
	int sock;
	struct addrinfo hints, *p;
	
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	
	if ((retStatus = getaddrinfo(addr, port, &hints, &c_addrinfo)) != 0) {
	
		fprintf(stderr, "getaddrinfo(): %s\n", gai_strerror(retStatus));
		return 1;
	}
	
	for (p = c_addrinfo; p != NULL; p = p->ai_next) {
	
		if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
		
			perror("server: socket()");
			continue;
		}
		
		if (// left of in the book, page 28
	}
}


int initServer(char* name, int socket, addrinfo s_addrinfo) {

	
}












