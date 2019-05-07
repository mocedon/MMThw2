#pragma once
// social_network header file
#ifndef _SOC_NET_H_
#define _SOC_NET_H_

#include <string.h>
#include "user.h"
#include "defs.h"

Result addToNetwork(node* network, char* new_user, char* inviter);

Result addRelationship(node* network, char* user1, char* user2);

Result removeRelationship(node* network, char* user1, char* user2);

Result searchUser(node* network, char* username);

void printNetwork(node* network);

void deleteNetwork(node* network);

#endif