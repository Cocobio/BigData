#include <iostream>
#include <fstream>
#include <string>

#include <unordered_map>
#include <stdio.h>

#include "murmur3.h"
#include "loglog.hpp"
#include "hyperloglog.hpp"

#include <ctime>
#include <cstdlib>

using namespace std;


template<class C>
void processCardinalDNA(string file, C &estimator, int k);

int main(int argn, char **argsv) {
	cout << "Running!" << endl;
	// parse input
	string option(argsv[1]);
	string file_path(argsv[2]);
	int k = atoi(argsv[3]);
	int b = 4;

	// hash function!
	unsigned char buffer[16];
	auto h = [&buffer](string &v, unsigned &s) {
		MurmurHash3_x64_128(v.data(), v.size(), s, buffer);
		return *((unsigned long long*) buffer);
	};

	if (argn == 5)
		b = atoi(argsv[4]);

	unordered_map<string,int> filter;
	filter[string("-ll")] = 1;
	filter[string("-hll")] = 2;

	switch(filter[option]) {
		case 1: {
			cout << "LogLog" << endl;
			LogLog<string> loglog(h,b);
			processCardinalDNA<LogLog<string>>(file_path, loglog, k);
			break;
		}

		case 2: {
			cout << "HyperLogLog" << endl;
			HyperLogLog<string> hyperloglog(h,b);
			processCardinalDNA<HyperLogLog<string>>(file_path, hyperloglog, k);
			break;
		}

		default: {
			cout << "Error with option " << option << ". Must be -ll or -hll." << endl;
			break;
		}
	}
	

	return 0;
}

template<class C>
void processCardinalDNA(string file, C &estimator, int k) {
	string tmp;

	fstream f(file);


	auto start = clock();
	double update_t = 0;
	size_t cc = 0;

	f.ignore(10000, '\n');
	while(getline(f,tmp)) {
		for (int i=0; i<=tmp.size()-k; i++) {
			string subsequence = tmp.substr(i,k);
			auto start2 = clock();
			estimator.update(subsequence);
			update_t+= ((double)clock() - start2)/CLOCKS_PER_SEC;
		}

		cc += tmp.size()-k;

		f.ignore(10000, '\n');
		f.ignore(10000, '\n');
		f.ignore(10000, '\n');
	}
	f.close();

	cout << "Time taken: " << ((double)clock() - start)/CLOCKS_PER_SEC << " [s]" << endl;
	cout << "Average update time: " << update_t/cc*1000 << " [ms]" << endl;
	cout << "Cardinal estimated: " << estimator.cardinal() << endl;
}


