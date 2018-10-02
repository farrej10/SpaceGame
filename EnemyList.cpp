#include "EnemyList.h"



EnemyList::EnemyList()
{
	head = NULL;
	tail = NULL;
}


void EnemyList::addNode(Enemy * object)
{
	if (head == NULL)//list empty
	{
		head = new EnemyNode(object);
		tail = head;
		tail->nextEnemy = NULL;
	}
	else
	{
		EnemyNode* temp = new EnemyNode(object);
		tail->nextEnemy = temp;
		tail = temp;

	}
}

void EnemyList::removeNode(EnemyNode * node)
{
	EnemyNode* temp = head;

	EnemyNode* prev = head;
	while (temp != node)
	{
		prev = temp;
		temp = temp->nextEnemy;

	}
	if (node == head)
	{
		head = node->nextEnemy;
		delete node;
	}

	else if (node == tail)
	{
		tail = prev;
		prev->nextEnemy = NULL;
		delete node;

	}

	else
	{
		prev->nextEnemy = node->nextEnemy;
		delete node;
	}

}