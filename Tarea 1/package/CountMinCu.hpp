#ifndef COUNT_MIN_CU
#define COUNT_MIN_CU

#include <cmath>
#include <vector>
#include <utility>
#include "AssociativeHeap.hpp"
#include <functional>
#include <cstring>
#include <algorithm>

#include <cstdlib>
#include <ctime>

using namespace std;

// Frequent estimator
template <class T, class C=size_t>
class CountMinCu {
	typedef T 		stream_value;

private:
	size_t d;
	size_t w;
	C** c;
	function<size_t(stream_value,unsigned)> hash;
	unsigned* hash_seed;

public:
	CountMinCu(size_t hash_n, size_t table_width, function<size_t(stream_value,unsigned)> h) {
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

		hash = h;
	}

	CountMinCu(double epsilon, double delta, function<size_t(stream_value,unsigned)> h) {
		srand(time(0));
		d = log(1.0/delta);
		w = exp(1)/epsilon;

		hash_seed = (unsigned*)malloc(d*sizeof(unsigned));
		c = (C**)malloc(d*sizeof(C*));
		auto c_data = (C*)malloc(d*w*sizeof(C));
		memset(c_data, d*w*sizeof(C), 0);

		for (int j=0; j<d; j++) {
			c[j] = c_data+j*w;
			hash_seed[j] = rand();
		}

		hash = h;
	}

	~CountMinCu() {
		free(c[0]);
		free(c);
		free(hash_seed);
	}

	void update(stream_value v);
	void update(stream_value v, C c);

	C estimate_frequency(stream_value v);
};

// Heavy Hitters
template <class T, class C=size_t>
class CountMinCu_HH {
	typedef T 		stream_value;

private:
	size_t K;
	AssociativeHeap<stream_value,size_t,vector<pair<size_t,stream_value>>, greater<pair<size_t,stream_value>>> AH;
	CountMinCu<T,C> cm;

public:
	CountMinCu_HH(size_t k, size_t hash_n, size_t table_width, function<size_t(stream_value,unsigned)> h) : cm(hash_n, table_width, h) {
		K = k;
	}

	CountMinCu_HH(size_t k, double epsilon, double delta, function<size_t(stream_value,unsigned)> h) : cm(epsilon, delta, h) {
		K = k;
	}

	CountMinCu_HH(double phi, size_t hash_n, size_t table_width, function<size_t(stream_value,unsigned)> h) : cm(hash_n, table_width, h) {
		K = ceil(1/phi)-1;
	}

	CountMinCu_HH(double phi, double epsilon, double delta, function<size_t(stream_value,unsigned)> h) : cm(epsilon, delta, h) {
		K = ceil(1/phi)-1;
	}

	void update(stream_value v);
	void update(stream_value v, C c);

	C estimate_frequency(stream_value v) {
		return cm.estimate_frequency(v);
	}

	vector<pair<stream_value,size_t>> topK();
};

#include "countmincu.cpp"

#endif
