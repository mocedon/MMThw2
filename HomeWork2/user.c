// user file implemantaion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "user.h"
#include "defs.h"

user* createUser(char* newName)
{
	user* u ;
	u = (user*) malloc(sizeof(user));
	if (u == NULL)
	{
		return NULL;
	}
	u->name = (char*) malloc(sizeof(char*));
	if (u->name == NULL) return NULL ;
	strcpy(u->name , newName) ;
	u->friend_list = NULL;
	u->friend_num = 0;
	return u;
}

void deleteUser(user* self) {
	cleanList(self->friend_list);
	free(self->name) ;
	free(self);
}

Result addFriend(user* self, char* add)
{
	node* listItem;
	for (listItem = getFriendList(self); listItem != NULL; listItem = listItem->next)
	{
		if (strcmp((char*)listItem->data, add) == 0)
		{
			return FAILURE;
		}
	}
	char* name = (char*) malloc(sizeof(char*)) ;
	if (name == NULL) return FAILURE ;
	strcpy(name , add) ;
	node* newNode = pushItem(getFriendList(self), name);
	if (newNode == NULL) return FAILURE;
	self->friend_list = newNode;
	self->friend_num++;
	return SUCCESS;
}

Result removeFriend(user* self, char* remove)
{
	node* listItem = getFriendList(self);
	if (strcmp((char*)listItem->data, remove) == 0)
	{
		self->friend_list = listItem->next;
		free(listItem);
	}
	for (node* nextItem = listItem->next; nextItem != NULL; nextItem = nextItem->next)
	{
		if (strcmp((char*)nextItem->data, remove) == 0) {
			listItem->next = nextItem->next;
			free(nextItem);
			self->friend_num--;
			return SUCCESS;
		}
		listItem = nextItem;
	}
	return FAILURE;
}

char* getName(user* self)
{
	return self->name;
}

node* getFriendList(user* self)
{
	return self->friend_list;
}

int getFriendNum(user* self)
{
	return self->friend_num;
}

void printUser(user* self)
{
	if (self == NULL) return ;
	printf("User's name: %s at adrress %p\n", getName(self) , (void*)self);
	int num = getFriendNum(self);
	node* listItem = getFriendList(self);
	printf("The user has %d friends:\n", num);
	for (int i = 0; i < num; i++) {
		char* name = (char*)listItem->data;
		printf("%s\n", name);
		listItem = listItem->next;
	}
}

bool nodeDataMatch(node* n1, node* n2)
{
	if (!strcmp((char*)n1->data, (char*)n2->data)) return true;
	else return false;
}

void cleanList(node* self)
{// Recursively frees up the momery from list
	if (self == NULL)
	{
		return;
	}
	cleanList(self->next);
	free(self->data) ;
	free(self);
}

node* pushItem(node* head , void* item)
{
	node* newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL) return NULL;
	
	newNode->data = item;
	newNode->next = head;
	return newNode;
}