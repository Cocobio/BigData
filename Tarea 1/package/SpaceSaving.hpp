#ifndef SPACE_SAVING
#define SPACE_SAVING

#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include "AssociativeHeap.hpp"

using namespace std;

template <class T>
class SpaceSaving {
	typedef T 		stream_value;

private:
	size_t K;
	AssociativeHeap<stream_value,size_t,vector<pair<size_t,stream_value>>, greater<pair<size_t,stream_value>>> AH;

public:
	SpaceSaving(T* begin_stream, T* end_stream, double phi) { 
		K = ceil(1/phi)-1;
		for (auto it= begin_stream; it!=end_stream; it++) 
			update(*it);
	}
	SpaceSaving(double phi) { K = ceil(1/phi)-1; }
	SpaceSaving(size_t k) { K = k; }
	SpaceSaving(int k) { K = k; }

	void update(stream_value v);
	void update(stream_value v, size_t c);

	vector<pair<stream_value,size_t>> topK();
};

#include "spacesaving.cpp"


#endif

