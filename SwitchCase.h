#pragma once
#include <unordered_map>
#include <functional>
#include "CustomConcepts.h"

template<typename Ty>
class SwitchCase
{
public:
	SwitchCase& operator()(const Ty& val, std::function<void()> def = {})
	{
		if (auto it = m_switch_map.find(val); it != m_switch_map.end())
		{
			visited = true;
			it->second();
		}
		else if (def)
			def();
		return *this;
	}
	SwitchCase& add(const Ty& val, Action auto fn)
	{
		m_switch_map[val] = fn;
		return *this;
	}
	const size_t size() const
	{
		return m_switch_map.size();
	}
	SwitchCase& ifVisited(Action auto fn)
	{
		if (visited)
		{
			visited = false;
			fn();
		}
		return *this;
	}
private:
	std::unordered_map<Ty, std::function<void()>> m_switch_map;
	bool visited = false;
};