// social_network implementation
#include "social_network.h"

Result addToNetwork(node* network, char* new_user, char* inviter)
{

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
	while (network)
	{
		curr_user = (user*)network->data;
		if (strcmp(username, curr_user->name) == 0)
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