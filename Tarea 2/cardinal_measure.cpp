#include <iostream>
#include <fstream>
#include <string>

#include <unordered_set>
#include <ctime>

using namespace std;

void processDNA(string file, int k, bool print);

int main(int argn, char **argsv) {
	if (argn!=4) {
		cout << "Incorrect input. Expected: fastq_file_path k print=1" << endl;
		return -1;
	}

	// Filter basic options
	string file_path(argsv[1]);
	int k = atoi(argsv[2]);		// for k-mers
	bool p = atoi(argsv[3]);

	processDNA(file_path, k, p);

	return 0;
}


void processDNA(string file, int k, bool print) {
	unordered_set<string> cardinal;
	string tmp;

	fstream f(file);

	auto start = clock();

	f.ignore(10000, '\n');
	while(getline(f,tmp)) {
		for (int i=0; i<=tmp.size()-k; i++) {
			string subsequence = tmp.substr(i,k);
			cardinal.insert(subsequence);
		}

		f.ignore(10000, '\n');
		f.ignore(10000, '\n');
		f.ignore(10000, '\n');
	}
	f.close();

	cout << "Cardinal de " << file << " con kmers de " << k << ": " << cardinal.size() << endl;

	cout << "Time taken: " << ((double)clock() - start)/CLOCKS_PER_SEC << " [s]" << endl;

	if (!print)
		return;
	for(auto &kmer : cardinal)
		cout << kmer << endl;
}


