// social_network implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "social_network.h"

Result addToNetwork(node* network, char* new_user, char* inviter)
{
	if (searchUser(network, new_user) != NULL)
	{
		return FAILURE;
	}
	user* u = createUser(new_user);
	if (u == NULL)
	{
		return FAILURE;
	}
	node* n = pushItem(network, u);
	if (n == NULL)
	{
		deleteUser(u);
		return FAILURE;
	}
	if (inviter == NULL)
	{
		network = n;
		return SUCCESS;
	}
	user* inv = searchUser(network, inviter);
	if (inv == NULL)
	{
		deleteUser(u);
		free(n);
		return FAILURE;
	}
	network = n;
	addFriend(u, inviter);
	addFriend(inv, new_user);
	return SUCCESS;
}

Result addRelationship(node* network, char* user1, char* user2)
{
	user* u1 = searchUser(network, user1);
	user* u2 = searchUser(network, user2);
	if (u1 == NULL || u2 == NULL)
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
	if (u1 == NULL || u2 == NULL)
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
	if(network == NULL){
		return NULL;
	}
	
	if (strcmp(username, getName((user*)network->data)) == 0){
		return (user*)network->data ;
	}
	return searchUser(network->next, username);
}

void printNetwork(node* network)
{
	if (network == NULL)
	{
		return;
	}
	printUser((user*)network->data);
	printf("\n");
	printNetwork(network->next);
}

void deleteNetwork(node* network)
{
	if (network == NULL)
	{
		return;
	}
	deleteNetwork(network->next);
	deleteUser((user*)network->data);
}