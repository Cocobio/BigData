#include "hyperloglog.hpp"


unsigned int HyperLogLog::query() {
	double sum = 0;

	for (int i=0; i<m; i++)
		sum += pow(2,-M[i]);

	return fc*m*m*pow(sum,-1);
}