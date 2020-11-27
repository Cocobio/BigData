#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void build_set() {
	unordered_set<string> kmers;

	string kmer;
	int discard;

	while (cin >> kmer >> discard) 
		kmers.insert(kmer);

	for (auto &e:kmers)
		cout << e << endl;
}

void count_from(string file, int k) {
	unordered_map<string,unsigned> fr;
	string tmp;

	while (cin >> tmp)
		fr[tmp];

	fstream f(file);

	f.ignore(10000, '\n');
	while(getline(f,tmp)) {
		for (int i=0; i<=tmp.size()-k; i++) {
			string subsequence = tmp.substr(i,k);

			auto element = fr.find(subsequence);

			if (element!=fr.end())
				element->second++;
		}

		f.ignore(10000, '\n');
		f.ignore(10000, '\n');
		f.ignore(10000, '\n');
	}
	f.close();

	for(auto &kmer : fr)
		cout << kmer.first << " " << kmer.second << endl;
}

int main(int argn, char** argv){
	if (strcmp(argv[1], "-c") == 0)
		build_set();
	else if (strcmp(argv[1],"-fr")==0)
		count_from(string(argv[2]), atoi(argv[3]));

	return 0;
}