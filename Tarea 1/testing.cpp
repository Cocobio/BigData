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

	auto ll = LogLog<int>(h, 7);
	auto hll = HyperLogLog<int>(h,5);
	unordered_set<int> measuring_set;

	cout << "Everything ready" << endl;

	for (int i=0; i<1000000; i++) {
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

	cout << "Estimated LogLog: " << ll.cardinal() << " Error: " << ((int)real_cardinal)-((int)ll_cardinal) << endl;
	cout << "Estimated HyperLogLog: " << hll_cardinal << " Error: " << ((int)real_cardinal)-((int)hll_cardinal) << endl;
	cout << "Real: " << real_cardinal << endl;

	return 0;
}