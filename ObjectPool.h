#pragma once
#include <functional>
#include <vector>

template <typename T>
class ObjectPool
{
public:
	ObjectPool(const std::function<T&()> create, int startSize) : m_CreateMethod(create)
	{
		for (int i = 0; i < startSize; i++)
		{
			auto obj = &m_CreateMethod();
			obj->Disable();
			m_Objects.push_back(obj);
		}
	}

	~ObjectPool()
	{
	}

	T& GetObject()
	{
		T* object = nullptr;
		if (m_Objects.empty())
		{
			object = &(m_CreateMethod());
		}
		else
		{
			object = m_Objects.back();
			m_Objects.pop_back();
		}

		object->Enable();
		object->RegisterAtPool(this);
		return *object;
	}

	void ReturnObject(T* object)
	{
		object->Disable();
		m_Objects.push_back(object);
	}

private:
	const std::function<T&()> m_CreateMethod;
	std::vector<T*> m_Objects;
};
