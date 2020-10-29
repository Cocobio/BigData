#include "loglog.hpp"


void LogLog::fc_table() {
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


LogLog::LogLog(int b) {
	this->b = b;
	m = pow(2,b);

	M = new unsigned char[m];

	memset(M,0,m);

	fc_table();
}

~LogLog::LogLog() {
	// delete[] M[0];
	delete[] M;
}


void LogLog::update(element x_i) {
	unsigned int hx = h(x_i);
	size_t i = hx << (32-b);
	size_t w = hx & (unsigned(-1) >> b);

	unsigned char zeros = p(w) + 1;

	M[i] = max(M[i], zeros);
}

unsigned int LogLog::query() {
	unsigned sum = 0;

	for (int i=0; i<m; i++)
		sum += M[i];

	return fc*m*pow(2,(1.0/m)*sum);
}
