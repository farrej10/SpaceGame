#pragma once
#include "BaseObjectNode.h"


//this wasnt used in the game yet
class BaseObjectList
{
public:
	BaseObjectNode* head;
	BaseObjectNode* tail;




	BaseObjectList();
	void addNode(BaseObject* object);
	void removeNode(BaseObjectNode* node);
	~BaseObjectList();
};

