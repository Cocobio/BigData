#ifndef HYPERLOGLOG
#define HYPERLOGLOG

#include "loglog.hpp"

class HyperLogLog : public LogLog {
	unsigned int query();
};

#include "hyperloglog.cpp"

#endif

