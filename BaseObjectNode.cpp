#include "BaseObjectNode.h"



BaseObjectNode::BaseObjectNode(BaseObject* theObjectB)
{
	theObject = theObjectB;
	nextObject = NULL;
}


BaseObjectNode::~BaseObjectNode()
{
}
