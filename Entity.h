#pragma once


class Entity
{
	friend class EntityPool;
public:
	~Entity();

	int GetId() const
	{
		return m_id;
	}

private:
	Entity();
	int m_id;
};
