#ifndef MISRA_GRIES
#define MISRA_GRIES

#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include "AssociativeHeap.hpp"

using namespace std;

template <class T>
class MisraGries {
	typedef T 		stream_value;

private:
	size_t K;
	AssociativeHeap<stream_value,size_t,vector<pair<size_t,stream_value>>, greater<pair<size_t,stream_value>>> AH;

public:
	MisraGries(T* begin_stream, T* end_stream, double phi) { 
		K = ceil(1/phi)-1;
		for (auto it= begin_stream; it!=end_stream; it++) 
			update(*it);
	}
	MisraGries(double phi) { K = ceil(1/phi)-1; }
	MisraGries(size_t k) { K = k; }
	MisraGries(int k) { K = k; }

	void update(stream_value v);
	void update(stream_value v, size_t c);

	vector<pair<stream_value,size_t>> topK();
};

#include "misragries.cpp"

#endif