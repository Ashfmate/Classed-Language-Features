#pragma once
#include <concepts>

template<typename T>
concept Action = requires{std::invocable<T>; };
