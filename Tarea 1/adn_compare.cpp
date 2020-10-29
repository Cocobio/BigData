#include <iostream>
#include "kmers.hpp"

using namespace std;


#include <bitset>         // std::bitset



int main(int argc, char **argv) {
	// cout << argc << endl;
	// if (argc == 1) {
	// 	cout << "No adn files added. Run the code followed by the document paths." << endl;
	// 	return -1;
	// }

	// for (int i=1; i<argc; i++) {

	// }

	// unsigned h = -1;

	// bitset<32> b_map(h);

	// cout << b_map << endl;
	// cout << b_map.size() << endl;

	// bitset<32> test((b_map.to_ulong() >> 10));
	// cout << test << endl;

	for(char i=0; i<127; i++) {
		if (i=='A') 	cout << 0 << ",";
		else if(i=='C') cout << 1 << ",";
		else if(i=='G') cout << 2 << ",";
		else if(i=='T') cout << 3 << ",";
		else cout << -1 << ",";
	}

	return 0;
}