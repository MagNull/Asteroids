#include "Entity.h"


Entity::Entity()
{
	static int nextId = 0;
	m_id = nextId++;
}

Entity::~Entity()
{

}
