// social_network implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "social_network.h"

Result addToNetwork(node** network, char* new_user, char* inviter)
{
	if (searchUser(*network, new_user) != nullptr)
	{
		return FAILURE;
	}
	user* u = createUser(new_user);
	if (u == nullptr)
	{
		return FAILURE;
	}
	node* n = (node*)malloc(sizeof(node));
	if (n == nullptr)
	{
		deleteUser(u);
		return FAILURE;
	}
	n->data = u;
	n->next = *network;
	*network = n;
	if (inviter == nullptr)
	{
		return SUCCESS;
	}
	user* inv = searchUser(network, inviter);
	if (inv == nullptr)
	{
		deleteUser(u);
		free(n);
		return FAILURE;
	}
	addFriend(u, inviter);
	addFriend(inv, new_user);
	return SUCCESS;
}

Result addRelationship(node* network, char* user1, char* user2)
{
	user* u1 = searchUser(network, user1);
	user* u2 = searchUser(network, user2);
	if (u1 == nullptr || u2 == nullptr)
	{
		return FAILURE;
	}
	if (addFriend(u1, user2) == FAILURE)
	{
		return FAILURE;
	}
	addFriend(u2, user1);
	return SUCCESS;
}

Result removeRelationship(node* network, char* user1, char* user2)
{
	user* u1 = searchUser(network, user1);
	user* u2 = searchUser(network, user2);
	if (u1 == nullptr || u2 == nullptr)
	{
		return FAILURE;
	}
	if (getFriendNum(u1) == 1 || getFriendNum(u2) == 1)
	{
		return FAILURE;
	}
	if (removeFriend(u1, user2) == FAILURE)
	{
		return FAILURE;
	}
	removeFriend(u2, user1);
	return SUCCESS;
}

user* searchUser(node* network, char* username)
{
	user* curr_user;
	for (node* u = network; u != nullptr; u = u->next)
	{
		curr_user = (user*)u->data;
		if (strcmp(username, getName(curr_user)) == 0)
		{
			return curr_user;
		}
	}
	return nullptr;
}

void printNetwork(node* network)
{
	user* curr_user;
	for (node* u = network; u != nullptr; u = u->next)
	{
		curr_user = (user*)u->data;
		printUser(curr_user);
		printf("\n");
	}
}

void deleteNetwork(node* network)
{
	user* curr_user;
	node* nxt;
	for (node* u = network; u != nullptr; u = nxt)
	{
		curr_user = (user*)u->data;
		deleteUser(curr_user);
		nxt = u->next;
		free(u);
	}
}