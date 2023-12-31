#pragma once
#include <vector>
#include <functional>
#include <utility>
#include "CustomConcepts.h"

class IfElse
{
public:
	IfElse& operator()(std::function<void()> def = {})
	{
		for (auto& if_item : m_if_array)
		{
			if (if_item.first())
			{
				visited = true;
				if_item.second();
				break;
			}
		}
		if (!visited && def) 
			def();
		return *this;
	}
	IfElse& add(Action auto pred, Action auto fn)
	{
		m_if_array.emplace_back(std::pair{ pred,fn });
		return *this;
	}
	const size_t size() const
	{
		return m_if_array.size();
	}
	IfElse& ifVisited(Action auto fn)
	{
		if (visited)
		{
			visited = false;
			fn();
		}
		return *this;
	}
private:
	std::vector<std::pair<std::function<bool()>, std::function<void()>>> m_if_array;
	bool visited = false;
};