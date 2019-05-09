// main implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"
#include "user.h"
#include "social_network.h"

#define MAX_STR 256
#define MAX_ARG 2
#define NUM_CMD 5

knownCMD parseCMD(char* cmd , char** args) ;

typedef enum { Insert , Add , Remove , Print , Exit , Other} knownCMD;

void runIns(char** args) ;
void runAdd(char** args) ;
void runRem(char** args) ;
void runPnt(char** args) ;
void runExt(char** args) ;

int main() {
	node* network = nullptr ;
	char cmd[MAX_STR] ;
	char* args[MAX_ARG] ;



	while (fgets(cmd, MAX_STR, stdin)) {
		knownCMD runCMD = parseCMD(cmd , args) ;
		switch (runCMD) {
			case Insert :
				runIns(args) ;
				break ;

			case Add :
				runAdd(args) ;
				break ;

			case Remove :
				runRem(args) ;
				break ;

			case Print :
				runPnt(args) ;
				break ;

			case Exit :
				runExt(args) ;
				break ;

			case Other :
				printf("Command not found") ;
				break ;
		}
	}
}

