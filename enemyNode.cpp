#include "enemyNode.h"


EnemyNode::EnemyNode(Enemy* theEnemyB)
{
	theEnemy = theEnemyB;
	nextEnemy = NULL;
}