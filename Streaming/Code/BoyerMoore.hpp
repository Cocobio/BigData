#ifndef BOYERMOORE
#define BOYERMOORE

#include <cstddef>
#include <utility>

template <class T>
std::pair<T,size_t> boyer_moore(T* begin_stream, T* end_stream);

#include "boyermoore.cpp"

#endif