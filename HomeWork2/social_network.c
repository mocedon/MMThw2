// social_network implementation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "social_network.h"

Result addToNetwork(node** network, char* new_user, char* inviter)
{
	if (*network == NULL)
	{
		*network = (node*) malloc(sizeof(node));
		if (*network == NULL)
		{
			return FAILURE;
		}
		(*network)->data = createUser(new_user);
		if ((*network)->data = NULL)
		{
			deleteUser(*network);
			return FAILURE;
		}
		(*network)->next = NULL;
		return SUCCESS ;
	}
	if (searchUser(*network, new_user) == NULL && searchUser(*network , inviter) != NULL)
	{
		node* n = (node*)malloc(sizeof(node));
		if (n == NULL)
		{
			return FAILURE;
		}
		user* u = createUser(new_user) ;
		if (u == NULL)
		{
			free(n);
			return FAILURE;
		}
		n->data = u ;
		n->next = *network ;
		if (addRelationship(n, new_user, inviter) == FAILURE)
		{
			deleteUser(u);
			free(n);
			return FAILURE;
		}
		*network = n;
		return SUCCESS;
	}
	return FAILURE;
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
	
	if (addFriend(u2, user1) == FAILURE)
	{
		removeFriend(u1, user2);
		return FAILURE;
	}
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
	if (removeFriend(u1, user2) == FAILURE || removeFriend(u2, user1) == FAILURE)
	{
		return FAILURE;
	}
	return SUCCESS;
}

user* searchUser(node* network, char* username)
{
	if (network == NULL || network->data == NULL)
	{
		return NULL;
	}
	if (strcmp(username, getName((user*)network->data)) == 0)
	{
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
	free(network);

}