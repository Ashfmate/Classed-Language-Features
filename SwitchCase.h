#pragma once
#include <unordered_map>
#include <functional>
#include <optional>

template<typename Ty>
class SwitchCase
{
public:
	SwitchCase& switchOn(const Ty& val, std::function<void()> fn = {})
	{
		if (auto it = m_switch_map.find(val); it != m_switch_map.end())
		{
			visited = true;
			it->second();
		}
		else
			fn();
		return *this;
	}
	SwitchCase& addCase(const Ty& val, std::function<void()> fn)
	{
		m_switch_map[val] = fn;
		return *this;
	}
	const size_t caseSize() const
	{
		return m_switch_map.size();
	}
	SwitchCase& ifVisited(std::function<void()> fn)
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