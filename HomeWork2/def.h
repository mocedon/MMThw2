// Def header file
#ifndef _DEFS_H_
#define _DEFS_H_

typedef enum { FAILURE, SUCCESS } Result;

typedef struct _Node {
	void* data;
	struct _Node* next;
} node;


#endif
