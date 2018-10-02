#pragma once
#include "baseObject.h"


//not used in the game yet
class BaseObjectNode
{
public:
	//data
	BaseObject* theObject;
	BaseObjectNode* nextObject;

	 
	BaseObjectNode(BaseObject* theObjectB);
	~BaseObjectNode();
};

