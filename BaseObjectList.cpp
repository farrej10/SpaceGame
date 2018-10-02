#include "BaseObjectList.h"



BaseObjectList::BaseObjectList()
{
	head = NULL;
	tail = NULL;
}


BaseObjectList::~BaseObjectList()
{
}


void BaseObjectList::addNode(BaseObject * object)
{
	if (head == NULL)//list empty
	{
		head = new BaseObjectNode(object);
		tail = head;
		tail->nextObject = NULL;
	}
	else
	{
		BaseObjectNode* temp = new BaseObjectNode(object);
		tail->nextObject = temp;
		tail = temp;

	}
}

void BaseObjectList::removeNode(BaseObjectNode * node)
{
	BaseObjectNode* temp = head;

	BaseObjectNode* prev = head;
	while (temp != node)
	{
		prev = temp;
		temp = temp->nextObject;
		
	}
	if (node == head)
	{
		head = node->nextObject;
		delete node;
	}

	else if (node == tail)
	{
		tail = prev;
		prev->nextObject = NULL;
		delete node;
	
	}

	else
	{
		prev->nextObject = node->nextObject;
		delete node;
	}

}