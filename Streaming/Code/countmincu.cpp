#include "SpaceSaving.hpp"

template<class T, class C>
void CountMinCu<T,C>::update(stream_value v) {
	C** min_fr = (C**)malloc(d*sizeof(C*));
	int change = 1;
	int index = 0;

	// set the first minimum
	min_fr[index++] = &c[0][hash(v,hash_seed[0])%w];

	// save a pointer to all the minimums
	for (int j=1; j<d; j++) {
		min_fr[index] = &c[j][hash(v,hash_seed[j])%w];
		
		if (*min_fr[0]>*min_fr[index]) {
			change = 1;
			swap(min_fr[0],min_fr[index]);
			index = 1;
		}
		else if (*min_fr[0]==*min_fr[index]) {
			change++;
			index++;
		}
	}

	// update only the mins
	for (int j=0; j<change; j++)
		(*min_fr[j])++;
}

template<class T, class C>
void CountMinCu<T,C>::update(stream_value v, C c) {
	C** min_fr = (C**)malloc(d*sizeof(C*));
	int change = 1;
	int index = 0;

	// set the first minimum
	min_fr[index++] = &this->c[0][hash(v,hash_seed[0])%w];

	// save a pointer to all the minimums
	for (int j=1; j<d; j++) {
		min_fr[index] = &this->c[j][hash(v,hash_seed[j])%w];
		
		if (*min_fr[0]>*min_fr[index]) {
			change = 1;
			swap(min_fr[0],min_fr[index]);
			index = 1;
		}
		else if (*min_fr[0]==*min_fr[index]) {
			change++;
			index++;
		}
	}

	// update only the mins
	for (int j=0; j<change; j++)
		*min_fr[j] += c;

	// for (int j=0; j<d; j++)
	// 	this->c[j][hash(v,hash_seed[j])%w] += c;
}

template<class T, class C>
C CountMinCu<T,C>::estimate_frequency(stream_value v) {
	C esti_fr = c[0][hash(v,hash_seed[0])%w];

	for (int j=1; j<d; j++)
		esti_fr = min(esti_fr, c[j][hash(v,hash_seed[j])%w]);

	return esti_fr;
}


template<class T,class C>
void CountMinCu_HH<T,C>::update(stream_value v) {
	cm.update(v);
	auto fr = cm.estimate_frequency(v);

	if (AH.update(v, fr));
	else if (AH.size()<K) AH.push(v,fr);
	else if (AH.top().first < fr) {
		AH.pop();
		AH.push(v,fr);
	}
}

template<class T,class C>
void CountMinCu_HH<T,C>::update(stream_value v, C c) {
	cm.update(v, c);
	auto fr = cm.estimate_frequency(v);

	if (AH.update(v, fr));
	else if (AH.size()<K) AH.push(v,fr);
	else if (AH.top().first < fr) {
		AH.pop();
		AH.push(v,fr);
	}
}

template<class T,class C>
vector<pair<T,size_t>> CountMinCu_HH<T,C>::topK() {
	vector<pair<stream_value,size_t>> topk;
	topk.reserve(K);
	
	for(auto it = AH.heap_cbegin(); it!=AH.heap_cend(); it++)
		topk.push_back(make_pair(it->second,it->first));

	return topk;
}