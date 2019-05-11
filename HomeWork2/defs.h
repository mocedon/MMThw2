// Def header file
#ifndef _DEFS_H_
#define _DEFS_H_

//#define _CRT_SECURE_NO_WARNINGS 

typedef enum { FAILURE=0, SUCCESS } Result;

typedef struct _Node {
	void* data ;
	struct _Node* next;
} node;

node* pushItem(node* head , void* data) ;

void cleanList(node* self) ;
#endif
