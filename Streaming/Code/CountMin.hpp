#ifndef COUNT_MIN
#define COUNT_MIN

#include <cmath>
#include <vector>
#include <utility>
#include "AssociativeHeap.hpp"
#include <functional>
#include <cstring>

#include <cstdlib>
#include <ctime>

using namespace std;

// Frequent estimator
template <class T, class C=size_t>
class CountMin {
	typedef T 		stream_value;

private:
	size_t d;
	size_t w;
	C** c;
	function<size_t(stream_value,unsigned)> hash;
	unsigned* hash_seed;

public:
	CountMin(size_t hash_n, size_t table_width) {
		srand(time(0));
		d = hash_n;
		w = table_width;

		hash_seed = (unsigned*)malloc(d*sizeof(unsigned));
		c = (C**)malloc(d*sizeof(C*));
		auto c_data = (C*)malloc(d*w*sizeof(C));
		memset(c_data, d*w*sizeof(C), 0);

		for (int j=0; j<d; j++) {
			c[j] = c_data+j*w;
			hash_seed[j] = rand();
		}
	}

	~CountMin() {
		free(c[0]);
		free(c);
		free(hash_seed);
	}

	void update(stream_value v);
	void update(stream_value v, size_t c);

	C estimate_frequency(stream_value v);
};

// Heavy Hitters
template <class T, class C=size_t>
class CountMin_HH {
	typedef T 		stream_value;

private:
	size_t K;
	AssociativeHeap<stream_value,size_t,vector<pair<size_t,stream_value>>, greater<pair<size_t,stream_value>>> AH;
	CountMin<T,C> cm;

public:
	CountMin_HH(size_t k, size_t hash_n, size_t table_width) : cm(hash_n, table_width) {
		K = k;
	}

	CountMin_HH(double phi, size_t hash_n, size_t table_width) : cm(hash_n, table_width) {
		K = ceil(1/phi)-1;
	}
};

#include "countmin.cpp"

#endif
