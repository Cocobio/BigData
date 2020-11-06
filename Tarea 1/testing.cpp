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

#include <ctime>
#include <cstdlib>

using namespace std;

// 392400288    40-mers

void readDNA(string file);
void kmers(map<string,size_t> &fr, string &chain, int k);

int main(int argn, char **argsv) {
	// srand(time(0));
	// string test = "AAATC";

	// unsigned char buffer[16];

	// unsigned seed = rand();

	// MurmurHash3_x64_128(test.data(), test.size(), seed, buffer);

	// for (int i=0; i<16; i++)
	// 	cout << buffer[i] << " ";
	// cout << endl;	MurmurHash3_x64_128(test.data(), test.size(), seed, buffer);
	// cout << *((unsigned long long*) buffer) << endl;

	// for (int i=0; i<16; i++)
	// 	cout << buffer[i] << " ";
	// cout << endl;	MurmurHash3_x64_128(test.data(), test.size(), seed, buffer);
	// cout << *((unsigned long long*) buffer) << endl;
	// test[0] = 'T';
	// for (int i=0; i<16; i++)
	// 	cout << buffer[i] << " ";
	// cout << endl;	MurmurHash3_x64_128(test.data(), test.size(), seed, buffer);
	// cout << *((unsigned long long*) buffer) << endl;

	// for (int i=0; i<16; i++)
	// 	cout << buffer[i] << " ";
	// cout << endl;

	// cout << *((unsigned long long*) buffer) << endl;
	
	for (int i=1; i<argn; i++) {
		cout << argsv[i] << endl;
		readDNA(string(argsv[i]));
	}

	// AssociativeHeap<string,size_t,vector<std::pair<size_t,string>>, greater<pair<size_t,string>>> test;

	// unordered_set<int>s;
	// srand(time(0));
	// for (int i=0; i<10; i++) {
	// 	s.insert(rand()%300);
	// }

	// for (auto &d:s) {
	// 	// cout << d << endl;
	// 	test.push(to_string(d),d);
	// }

	// for (auto it=test.heap_cbegin(); it!=test.heap_cend(); it++)
	// 	cout << it->first << " ";
	// cout << endl;

	// test.update(to_string(*s.begin()),rand()%300);

	// while (test.size()) {
	// 	// test.print();
	// 	auto tmp = test.top();
	// 	cout << tmp.first << "\t" << tmp.second << endl;
	// 	test.pop();
	// }

	// test

	return 0;
}

void readDNA(string file) {
	int k=20;
	string tmp;

	fstream f(file);

	map<string,size_t> fr;
	auto h = [](string v, unsigned s) {
		unsigned char buffer[16];
		MurmurHash3_x64_128(v.data(), v.size(), s, buffer);
		return *((unsigned long long*) buffer);
	};
	// CountMinCu_HH<string,unsigned> mg_topk(size_t(300u), size_t(5u), size_t(1000u), h);
	MisraGries<string> mg_topk(size_t(150000u));

	auto start = clock();
	unsigned counter = 0;
	unsigned cc = 0;
	size_t cc2 = 0;
	double t2 = 0;

	f.ignore(10000, '\n');
	while(getline(f,tmp)) {
		// kmers(fr,tmp,k);
		for (int i=0; i<tmp.size()-k; i++) {
			string subsequence = tmp.substr(i,k);
			auto start2 = clock();
			mg_topk.update(subsequence);
			t2+= ((double)clock() - start2)/CLOCKS_PER_SEC;
			cc2++;
		}

		// for (int i=0; i<tmp.size()-k; i++) {

		// 	if (strncmp(tmp.data()+i,"TTTTTTTTTTTTTTTTTTTT",k)==0) cc++;
		// }
		// counter += tmp.size()-k;
		f.ignore(10000, '\n');
		f.ignore(10000, '\n');
		f.ignore(10000, '\n');
	}
	f.close();

	// cout << "counter: " << counter << endl;
	// cout << "cc2: " << cc2 << endl;
	// cout << "cc: " << cc << endl;

	cout << "time taken: " << ((double)clock() - start)/CLOCKS_PER_SEC << endl;

	// cout << "Real:" << endl;
	// vector<pair<string,size_t>> fr_v(fr.begin(),fr.end());
	// sort(fr_v.begin(),fr_v.end(),[](pair<string,size_t> a, pair<string,size_t> b){ return a.second > b.second; });
	// // if (fr_v.size() > 200) fr_v.resize(200);
	// for (auto &p:fr_v)
	// 	cout << p.first << "  " << p.second << endl;

	cout << "MisraGries" << endl;
	vector<pair<string,size_t>> fr_v2(mg_topk.topK());
	sort(fr_v2.begin(),fr_v2.end(),[](pair<string,size_t> a, pair<string,size_t> b){ return a.second > b.second; });
	for (auto &p:fr_v2)
		cout << p.first << "  " << p.second << endl;
	cout << "update time: " << t2/cc2 << endl;

	cout << "done" << endl;
}

void kmers(map<string,size_t> &fr, string &chain, int k) {
	for (int i=0; i<chain.size()-k; i++) {
		fr[chain.substr(i,k)]++;
	}
}

