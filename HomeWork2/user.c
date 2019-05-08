// user file implemantaion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "def.h"

user* createUser(char* newName) {
	u = (user*) malloc(sizeof(user));
	if (u == nullptr) return nullptr ;
	u->name = newName ;
	u->friendList = nullptr ;
	u->friendNum = 0 ;
	return u ;
}

void deleteUser(user* self) {
	cleanList(self->friend_list) ;
	free(self) ;
}

Result addFriend(user* self, char* add) {
	node* listItem = getFriendList(self) ;
	for (int i = 0 ; i < self->friend_num ; i++) {
		if (listItem == nullptr) {
			node* tmp = self->friend_list ;
			node* newNode ;
			newNode = (node*) malloc(sizeof(node)) ;
			newNode->data = add ;
			newNode->next = tmp ;
			self->friend_list = newNode ;
			self->friend_num++ ;
			return SUCCESS ;
		}
		if (!strcmp((char*)listItem->data , add)) return FAILURE ;
	}
}

Result removeFriend(user* self, char* remove) {
	node* listItem = getFriendList(self) ;
	for (int i = 0 ; i < self->friend_num ; i++) {
		if (listItem == nullptr) return FAILURE ;
		node* nextItem = listItem->next ;
		if (!strcmp((char*)listItem->data , remove)) {
			node* tmp = listItem ;
			listItem = nextItem ;
			free(tmp) ;
			self->friend_num-- ;
			return SUCCESS ;
		listItem = nextItem ;
		}
	}
}

char* getName(user* self) {
	return self->name ;
}

node* getFriendList(user* self) {
	return self->friend_list ;
}

int getFriendNum(user* self) {
	return self->friend_num ;
}

void printUser(user* self) {
	printf("User's name: %s \n" , getName(self));
	int num = getFriendNum(self) ;
	node* listItem = getFriendList(self)
	printf("The user has %d friends:\n" , &num)
	for (int i = 0 ; i < num ; i++) {
		char* name = (char*)listItem->data ;
		printf("%s\n" , name) ;
		listItem = listItem->next ;
	}
}

bool nodeDataMatch(node* n1, node* n2) {
	if (!strcmp((char*)n1->data , (char*)n2->data)) return True ;
	else return false ;
}



void cleanList(node* self) {
	// Recursively frees up the momery from list
	if (self == nullptr) return;
	cleanList(self->next);
	free(self);
}