#include "loglog.hpp"


template <class T>
void LogLog<T>::fc_table() {
	switch(m) {
		case 16:
		fc = 0.673;
		break;

		case 32:
		fc = 0.697;
		break;

		case 64:
		fc = 0.709;
		break;

		default:
		fc = 0.7213 / (1+1.079/m);
	}
}


template <class T>
LogLog<T>::LogLog(std::function<hashed(T&,unsigned&)> h, int b) {
	srand(time(0));
	hash = h;
	hash_seed = rand();
	this->b = b;
	
	m = pow(2,b);
	M = new unsigned char[m];
	memset(M,0,m);

	fc_table();
}

// #include <iostream>
// using namespace std;

template <class T>
void LogLog<T>::update(element x_i) {
	hashed hx = hash(x_i, hash_seed);
	// cout << "input: " << x_i << endl << "hashed: " << hx << endl;
	size_t i = hx & (m-1);
	// cout << "i: " << i << endl;
	hashed w = hx >> b;
	// cout << "w: " << w << endl;
	unsigned char zeros = __builtin_clzll(w) - b;
	// cout << "leading zeros: " << (int)zeros << endl;

	M[i] = std::max(M[i], zeros);
}

template <class T>
unsigned int LogLog<T>::cardinal() {
	double sum = 0;

	for (int i=0; i<m; i++)
		sum += M[i];

	return fc * pow(2,(1.0/m)*sum) * m;
}

template<class T>
size_t LogLog<T>::size_in_bytes() {
	size_t s = sizeof(this);

	s += sizeof(unsigned char)*m;

	return s;
}
