#include "BoyerMoore.hpp"

template <class T>
std::pair<T,size_t> boyer_moore(T* begin_stream, T* end_stream) {
	T M;
	size_t count = 0;

	for (T* it=begin_stream; it!=end_stream; it++) {
		if (count==0) {
			M = *it;
			count = 1;
		}
		else if (*it==M)
			count++;
		else
			count--;
	}

	return std::make_pair(M,count);
}