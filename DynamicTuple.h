#pragma once
#include <tuple>

#include "MutableTuple.h"

template<typename ...Types>
class DynamicTuple
{
public:
	DynamicTuple(Types... args) : MutableTuple(args)
	{
		
	}
	~DynamicTuple();
};
