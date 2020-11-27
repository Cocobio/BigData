// nohup ./project -ss ../../../Database/ERR626209.fastq 20 64000 > ERR626208/mg_20mers_k64k.txt &
#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "AssociativeHeap.hpp"
#include <vector>

#include <unordered_set>
#include <stdio.h>
#include "MisraGries.hpp"
#include "SpaceSaving.hpp"
#include "CountMin.hpp"
#include "CountMinCu.hpp"

#include "murmur3.h"

#include <ctime>
#include <cstdlib>

using namespace std;

// 392400288    40-mers
// 423543168	30-mers
// 454686048	20-mers

template<class HHs>
void processDNA(string file, HHs &hh, int k);

template<class Sketch>
void time_fr_estimate(Sketch &s);

int main(int argn, char **argsv) {
	if (argn<4) {
		cout << "Incorrect input. Expected: -option fastq_file_path k" << endl;
		return -1;
	}

	// Filter basic options
	string option(argsv[1]);
	string file_path(argsv[2]);
	int k = atoi(argsv[3]);		// for k-mers
	unsigned long kmers = 3114288*(166-k);

	unordered_map<string,int> filter;
	filter[string("-mg")] = 0;
	filter[string("-ss")] = 1;
	filter[string("-cm")] = 2;
	filter[string("-cmcu")] = 3;

	if (filter.find(option)==filter.end()) {
		cout << "First argument (option) must be one of these \"-mg\", \"-ss\", \"-cm\" and \"-cmcu\"." << endl;
		return -1;
	}

	// Hash for countmin and countmincu
	auto h = [](string v, unsigned s) {
		unsigned char buffer[16];
		MurmurHash3_x64_128(v.data(), v.size(), s, buffer);
		return *((unsigned long long*) buffer);
	};

	void *HH;

	switch(filter[option]) {
		case 0: {
			cout << "Misra Gries" << endl;
			int K = atoi(argsv[4]);
				
			MisraGries<string> misra(K);
			processDNA<MisraGries<string>>(file_path, misra, k);
		
			for (auto &p:misra.topK())
				cout << p.first << "  " << p.second << endl;
			break;
		}

		case 1: {
			cout << "Space Saving" << endl;
			int K = atoi(argsv[4]);
				
			SpaceSaving<string> spacesa(K);
			processDNA<SpaceSaving<string>>(file_path, spacesa, k);
		
			for (auto &p:spacesa.topK())
				cout << p.first << "  " << p.second << endl;
			break;
		}

		case 2: {
			cout << "CountMin" << endl;
			int w = atoi(argsv[4]);
			int d = atoi(argsv[5]);
			int K = atoi(argsv[6]);
		
			CountMin_HH<string,unsigned int> cm(size_t(K),size_t(d),size_t(w), h);
			processDNA(file_path, cm, k);
		
			time_fr_estimate(cm);
		
			for (auto &p:cm.topK())
				cout << p.first << "  " << p.second << endl;
			break;
		}

		default: {
			cout << "CountMinCU" << endl;
			int w = atoi(argsv[4]);
			int d = atoi(argsv[5]);
			int K = atoi(argsv[6]);
		
			CountMinCu_HH<string,unsigned int> cmcu(size_t(K), size_t(d), size_t(w), h);
			processDNA(file_path, cmcu, k);
		
			time_fr_estimate(cmcu);
		
			for (auto &p:cmcu.topK())
				cout << p.first << "  " << p.second << endl;
			break;
		}
	}

	return 0;
}

template<class HHs>
void processDNA(string file, HHs &hh, int k) {
	string tmp;

	fstream f(file);

	map<string,size_t> fr;

	auto start = clock();
	double update_t = 0;
	size_t cc = 0;

	f.ignore(10000, '\n');
	while(getline(f,tmp)) {
		for (int i=0; i<=tmp.size()-k; i++) {
			string subsequence = tmp.substr(i,k);
			auto start2 = clock();
			hh.update(subsequence);
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
}


template<class Sketch>
void time_fr_estimate(Sketch &s) {
	int cc = 0;
	double t = 0;

	for (auto &p:s.topK()) {
		cc++;
		auto start = clock();
		s.estimate_frequency(p.first);
		t += ((double)clock() - start)/CLOCKS_PER_SEC;
	}

	cout << "Average time for frequency estimation: " << t/cc*1000 << " [ms]" << endl;
}

