#pragma once
#include <concepts>

template<typename T>
concept Action = std::invocable<T>;
