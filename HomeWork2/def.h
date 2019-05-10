// Def header file
#ifndef _DEFS_H_
#define _DEFS_H_

typedef enum { FAILURE=0, SUCCESS } Result;

typedef struct _Node {
	void* data;
	struct _Node* next;
} node;

node* pushItem(node* head , void* data) ;
void removeItem(node* curr , node* del) ;
#endif
