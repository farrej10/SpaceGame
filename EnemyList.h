#pragma once
#include "enemyNode.h"
class EnemyList
{

public:
	EnemyNode* head;
	EnemyNode* tail;




	EnemyList();
	void addNode(Enemy* object);
	void removeNode(EnemyNode* node);
};

