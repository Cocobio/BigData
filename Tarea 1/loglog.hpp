#ifndef LOGLOG
#define LOGLOG

#include <cmath>
#include <cstring>
#include <algorithm>

template <class T>
class LogLog {
public:
	typedef T		element;
private:
	unsigned char* M;
	// hash<element> h;
	unsigned char b;
	unsigned int m; // 2^b
	float fc;

	void fc_table();

public:
	LogLog(int b=4);
	~LogLog();

	void update(element x_i);

	unsigned int query();
};

#include "loglog.cpp"

#ifndef

