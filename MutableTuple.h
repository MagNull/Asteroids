#pragma once
#include <tuple>

template <typename... Types>
class MutableTuple
{
public:
	MutableTuple() : m_values{}
	{
	}

	MutableTuple(Types ... args) : m_values{args...}
	{
	}

	template <std::size_t i>
	auto& Get() const
	{
		static_assert(i < sizeof...(Types), "index out of range");
		return std::get<i>(m_values);
	}

	template <std::size_t i>
	void Set(const typename std::tuple_element<i, std::tuple<Types...>>::type& value)
	{
		static_assert(i < sizeof...(Types), "index out of range");
		std::get<i>(m_values) = value;
	}

	template <std::size_t i>
	void Set(const std::variant<Types...> value)
	{
		static_assert(i < sizeof...(Types), "index out of range");
		std::get<i>(m_values) = std::get<std::tuple_element_t<i, decltype(m_values)>>(value);
	}


protected:
	std::tuple<Types...> m_values;
};
