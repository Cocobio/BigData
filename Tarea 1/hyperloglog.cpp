#include "hyperloglog.hpp"


template <class T>
unsigned int HyperLogLog<T>::cardinal() {
	double Z = 0;

	for (int i=0; i<this->m; i++)
		Z += pow(2,-this->M[i]-1);
	Z = 1/Z;

	cout << "fc " << this->fc << endl;
	cout << "m " << this->m << endl;
	cout << "Z " << Z << endl;

	return this->fc*this->m*this->m*Z;
}