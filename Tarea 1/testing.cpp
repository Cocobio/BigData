#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "../Streaming/Code/AssociativeHeap.hpp"
#include <vector>

#include <unordered_set>
#include <stdio.h>
#include <algorithm>
#include "../Streaming/Code/MisraGries.hpp"
#include "../Streaming/Code/SpaceSaving.hpp"
#include "../Streaming/Code/CountMin.hpp"
#include "../Streaming/Code/CountMinCu.hpp"

#include "murmur3.h"
#include "loglog.hpp"
#include "hyperloglog.hpp"

#include <ctime>
#include <cstdlib>

using namespace std;

// 392400288    40-mers
// 423543168	30-mers
// 454686048	20-mers
#include <unordered_set>

template<class HHs>
void processDNA(string file, HHs &hh, int k);

int main(int argn, char **argsv) {

	auto h = [](int v, unsigned s) {
		unsigned char buffer[16];
		MurmurHash3_x64_128(&v, 4, s, buffer);
		return *((unsigned long long*) buffer);
	};

	int precission = 18;

	auto ll = LogLog<int>(h, precission);
	auto hll = HyperLogLog<int>(h,precission);
	unordered_set<int> measuring_set;

	cout << "Everything ready" << endl;

	for (int i=0; i<10000000; i++) {
		int x = rand();
		measuring_set.insert(x);
		// cout << "updating " << x << endl;
		ll.update(x);
		hll.update(x);
		// cout << "---------------------\n\n";
	}

	cout << "Data inserted" << endl;

	auto ll_cardinal = ll.cardinal();
	auto hll_cardinal = hll.cardinal();
	auto real_cardinal = measuring_set.size();

	auto err_ll = ((int)real_cardinal)-((int)ll_cardinal);
	auto err_ll_pr = err_ll/((float)real_cardinal);
	auto err_hll = ((int)real_cardinal)-((int)hll_cardinal);
	auto err_hll_pr = err_hll/((float)real_cardinal);

	cout << "Estimated LogLog: " << ll.cardinal() << " Error: " << err_ll << " " << err_ll_pr*100 << "%"<< endl;
	cout << "Estimated HyperLogLog: " << hll_cardinal << " Error: " << err_hll << " " << err_hll_pr*100 << "%" << endl;
	cout << "Real: " << real_cardinal << endl;

	return 0;
}

// #include <unordered_map>
// #include <vector>
// #include <utility>
// #include <list>

// int main() {

// 	int d = 8;
// 	int w = 64000;

// 	// cout << sizeof(unsigned) << endl;
// 	// cout << (d*sizeof(unsigned) + d*sizeof(size_t*)+ d*w*sizeof(size_t))/1024.0 << endl;

// 	int K = 64000;
// 	int kmer = 40;

// 	vector<pair<string,size_t>> heap;
// 	unordered_map<string,size_t> hash;

// 	hash.reserve(K);

// 	cout << (sizeof(size_t) + K*(sizeof(string)+kmer+sizeof(size_t)))/1024.0 << endl;
// 	cout << (sizeof(size_t) + sizeof(heap) + 2*K*(sizeof(string)+kmer+sizeof(size_t)) + hash.bucket_count()*sizeof(list<pair<string,size_t>>) + sizeof(hash))/1024.0 << endl;

// 	return 0;
// }