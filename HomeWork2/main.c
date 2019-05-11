// main implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "user.h"
#include "social_network.h"

#define MAX_STR 256
#define MAX_ARG 2
#define NUM_CMD 5

#define INS_S Add To Network
#define ADD_S Add Relationship
#define REM_S Remove Relationship

#define STR(x) #x

#define ERROR_PAR(x) \
	do { \
		fprintf(stderr , "%s failed: not enough parameters\n", STR(x)) ; \
		return ; \
	} \
	while(0);

#define ERROR_FAIL(x) \
	do { \
		fprintf(stderr , "%s execution failed\n", STR(x)) ;	\
		return ; \
	}  \
	while(0);

typedef enum { Insert, Add, Remove, Print, Exit, Other } knownCMD;

knownCMD parseCMD(char* cmd , char** args) ;

void runIns(char** args , node* network) ;
void runAdd(char** args , node* network) ;
void runAdd(char** args , node* network) ;
void runRem(char** args , node* network) ;
void runPnt(node* network) ;
void runExt(node* network) ;

int main() {
	node* network = NULL;
	char cmd[MAX_STR] ;
	char* args[MAX_ARG] ;



	while (fgets(cmd, MAX_STR, stdin)) {
		printf("> %s\n" , cmd) ;
		knownCMD runCMD = parseCMD(cmd , args) ;
		switch (runCMD) {
			case Insert :
				runIns(args , network) ;
				break ;

			case Add :
				runAdd(args , network) ;
				break ;

			case Remove :
				runRem(args , network) ;
				break ;

			case Print :
				runPnt(network) ;
				break ;

			case Exit :
				runExt(network) ;
				return 0 ;
				break ;

			case Other :
				printf("Command not found\n") ;
				break ;
		}
	}
}

knownCMD parseCMD(char* cmd, char** args) {
	char* x ;
	char cut[] = " \n" ;
	char cmdTable[NUM_CMD][MAX_STR] = {
		"Insert" , 
		"Add" ,
		"Remove" ,
		"Print" , 
		"Exit"
	} ;
	x = strtok(cmd , cut) ;
	args[0] = strtok(NULL , cut) ;
	args[1] = strtok(NULL , cut) ;

	for (int i=0 ; i < NUM_CMD ; i++){
		if (!strcmp(x, cmdTable[i])) return i;
	}
	return Other ;
}

void runIns(char** args, node* network) {
	Result result ;
	if (network == NULL && args[0] != NULL) {
		node* netPtr = &network;
		result = addToNetwork(netPtr , args[0] , args[1]) ;	
		if (!result) ERROR_FAIL(INS_S);
		return ;
	}
	if (args[0] == NULL || args[1] == NULL)
		ERROR_PAR(INS_S) ;
	result = addToNetwork(network, args[0], args[1]);
	if (!result) ERROR_FAIL(INS_S) ;
}

void runAdd(char** args, node* network) {
	Result result ;
	if (args[0] == NULL || args[1] == NULL)
		ERROR_PAR(ADD_S);
	result = addRelationship(network , args[0] , args[1]) ;
	if (!result) ERROR_FAIL(ADD_S) ;
}

void runRem(char** args, node* network) {
	Result result;
	if (args[0] == NULL || args[1] == NULL)
		ERROR_PAR(REM_S);
	result = removeRelationship(network, args[0], args[1]);
	if (!result) ERROR_FAIL(REM_S);
}

void runPnt(node* network) {
	printNetwork(network) ;
}

void runExt(node* network) {
	deleteNetwork(network) ;
}
