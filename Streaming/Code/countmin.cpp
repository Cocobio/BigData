#include "SpaceSaving.hpp"

template<class T, class C>
void CountMin<T,C>::update(stream_value v) {
	for (int j=0; j<d; j++)
		c[j][hash(v,hash_seed[j])%w]++;
}

template<class T, class C>
void CountMin<T,C>::update(stream_value v, size_t c) {
	for (int j=0; j<d; j++)
		this->c[j][hash(v,hash_seed[j])%w] += c;
}

template<class T, class C>
C CountMin<T,C>::estimate_frequency(stream_value v) {
	C esti_fr = c[0][hash(v,hash_seed[0])%w];

	for (int j=1; j<d; j++)
		esti_fr = min(esti_fr, c[j][hash(v,hash_seed[j])%w]);

	return esti_fr;
}




