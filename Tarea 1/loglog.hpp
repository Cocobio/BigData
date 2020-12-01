#ifndef LOGLOG
#define LOGLOG

#include <cmath>
#include <cstring>
#include <algorithm>

#include <functional>
#include <ctime>
#include <cstdlib>

template <class T>
class LogLog {
public:
	typedef T		element;
	
protected:
	unsigned char* M;
	// hash<element> h;
	std::function<unsigned(element&,unsigned&)> hash;
	unsigned hash_seed;
	unsigned char b;
	unsigned int m; // 2^b
	float fc;

	void fc_table();

public:
	LogLog(std::function<unsigned(element&,unsigned&)> h, int b=4);
	~LogLog() {
		delete[] M;
	}

	void update(element x_i);

	unsigned int cardinal();
};

#include "loglog.cpp"

#endif

