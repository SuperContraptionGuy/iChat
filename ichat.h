#ifndef ICHAT_H_
#define ICHAT_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

//	Used to make the chat file to save messages to, and create the connection with the remote chatter.
int initClient(char*, char*, char*, int*, addrinfo*);// name, address, port, socket, addrinfo
int initServer(char*, int, addrinfo);	// name, socket, addrinfo

//	used to produce all the user prompts and return the data
//	
//	Prompts:
//
//	System Idle screen 				= 0
//		wating for connections.  Press enter to login and chat.
//	Username Prompt 				= 1
//		Please select a username: 
//	Select remote computer to communicate with 	= 2
//		Enter the address of remote computer: 
//	Messaging screen				= 3
//		display a history of the chat
//			eg:
//			
//			Hudson: Hey man, wud up?
//					Just working on 
//					RULLING THE WORLD		:Jack
//			Hudson: Sweet man! I've got a few ideas
//			 on the topic, wanna chat???
//			 		Sure, what's your ideas?	:Jack	
//			 
//				Jack is typeing...
//				Press ENTER to send.
//			Message: Well, my first idea is, if you were to
int prompts(int, char*);

//	Used to send data to the other user, formated:
//		
//		#:#:data...
//		
//		data type flag:data length:data
//		
//	data type flags:
//		
//		Flag meaning		integer representation
//		
//		Message			0
//		user is typing		1
//		user stopped typing	2
//		end the chat		3		
int sendMessage();

//	Called when a message is recieved from the other user, takes neccisary action when a message is recieved.
int onReceiveMessage();

//	Save a message to disk
int saveMessage();

//	retrieve a message stored on the disk
int retrieveMessage();

//	Main functions for client and server types
void client();
void server();


// 	message data type flags
#define F_MESSG		0
#define F_TYPING	1
#define F_STOPEDTYPING	2
#define F_ENDCHAT	3

//	prompt message tags
#define P_IDLE		0
#define P_USERNAME	1
#define P_CONNECT	2
#define P_CHAT		3

#endif
