#pragma once
// user header file
#ifndef _USER_H
#define _USER_H

#include "def.h"

typedef struct _user {

	char* name ;
	node* friend_list ;
	int friend_num ;

} user;

user* createUser(char* newName);

void deleteUser(user* self);

Result addFriend(user* self , char* add);

Result removeFriend(user* self, char* remove);

char* getName(user* self);

node* getFriendList(user* self);

int getFriendNum(user* self);

void printUser(user* self);

#endif
