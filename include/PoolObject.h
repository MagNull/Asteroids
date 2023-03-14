#pragma once
#include "ObjectPool.h"

template <typename T>
class PoolObject
{
	friend class ObjectPool<T>;

protected:
	PoolObject()
	{
	}

	void RegisterAtPool(ObjectPool<T>* pool)
	{
		m_OwnerPool = pool;
	}

	virtual void Enable();
	virtual void Disable();

	void OnDestroyed()
	{
		m_OwnerPool->ReturnObject(static_cast<T*>(this));
	}

private:
	ObjectPool<T>* m_OwnerPool;
};
