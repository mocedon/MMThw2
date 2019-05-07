// social_network implementation
#include "social_network.h"

Result addToNetwork(node* network, char* new_user, char* inviter)
{
	if (searchUser(network, new_user)!=NULL)
	{
		return FAILURE;
	}
	user* u = createUser(new_user);
	if (u == NULL)
	{
		return FAILURE;
	}
	//needs to add user to list
	if (inviter != NULL && addRelationship(network, new_user, inviter) == FAILURE)
	{
		deleteUser(u);
		return FAILURE;
	}

}

Result addRelationship(node* network, char* user1, char* user2)
{

}

Result removeRelationship(node* network, char* user1, char* user2)
{

}

user* searchUser(node* network, char* username)
{
	user* curr_user;
	for (node* u = network; u != NULL; u = u->next)
	{
		curr_user = (user*)u->data;
		if (strcmp(username, getName(curr_user)) == 0)
		{
			return curr_user;
		}
	}
	return NULL;
}

void printNetwork(node* network)
{

}

void deleteNetwork(node* network)
{

}