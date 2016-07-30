#include "ichat.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

#include <string.h>

#define PORT "2005"

int main() {

	int c_socket, s_socket;		// c: client, s: server
	struct addrinfo c_addr, s_addr;
	
	bool exit = false;
	
	char response[50];
	char name[50];
	char address[50];
	
	memset(&response, ' ', 50);
	prompts(P_USERNAME, response);
	strcpy(name, response);
	
	if (!fork()) {
	
		initServer(name, &s_socket, &s_addr);	// will need to use pipes or some other method of communicating information like when messages are recieved, maybe if this process will be incharge of monitoring the ports...
	}
	
	while(!exit) {
	
		prompts(P_IDLE, response);	// wait for user
		
		prompts(P_CONNECT, response);	// user sets up client connection
		strcpy(address, response);
		
		if (!fork()) {
		
			initClient(name, address, (char*)PORT, &c_socket, &c_addr);
		}
		
		//prompts(P_CHAT, response);
		
	}
}
