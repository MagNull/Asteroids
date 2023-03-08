#pragma once
#include <unordered_map>
#include <vector>

#include "IComponentObserver.h"

namespace Components
{
	class ComponentPool
	{
	public:
		ComponentPool();
		~ComponentPool();

		template <typename T>
		void AddComponent(int entityId)
		{
			T newComponent = new T(entityId);

			if (m_componentsById[T::ID] != nullptr)
			{
				m_componentsById[T::ID]->push_back(newComponent);
				return;
			}
			m_componentsById[T::ID] = new std::vector<void*>{newComponent};
		}

		template <typename T>
		std::vector<T*>& GetComponents()
		{
			if (m_componentsById[T::ID] == nullptr)
				m_componentsById[T::ID] = new std::vector<void*>{};

			return *reinterpret_cast<std::vector<T*>*>(m_componentsById[T::ID]);
		}

	private:
		std::unordered_map<int, std::vector<void*>*> m_componentsById;
		std::vector<IComponentObserver*> m_componentObservers;
	};
}
