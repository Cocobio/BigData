#ifndef HYPERLOGLOG
#define HYPERLOGLOG

#include "loglog.hpp"

template<class T>
class HyperLogLog : public LogLog<T> {
public:
	typedef T							element;
	typedef typename LogLog<T>::hashed	hashed;

	HyperLogLog(std::function<hashed(element&,unsigned&)> h, int b=4) : LogLog<T>{ h, b } {}
	
	unsigned int cardinal();
};

#include "hyperloglog.cpp"

#endif

