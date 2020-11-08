#include "SpaceSaving.hpp"

template<class T, class C>
void CountMin<T,C>::update(stream_value v) {
	for (int j=0; j<d; j++)
		c[j][hash(v,hash_seed[j])%w]++;
}

template<class T, class C>
void CountMin<T,C>::update(stream_value v, C c) {
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


template<class T,class C>
void CountMin_HH<T,C>::update(stream_value v) {
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
void CountMin_HH<T,C>::update(stream_value v, C c) {
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
vector<pair<T,size_t>> CountMin_HH<T,C>::topK() {
	vector<pair<stream_value,size_t>> topk;
	topk.reserve(K);

	for(auto it = AH.heap_cbegin(); it!=AH.heap_cend(); it++)
		topk.push_back(make_pair(it->second,it->first));

	auto comp = [](pair<stream_value,size_t> a, pair<stream_value,size_t> b){ 
		return a.second > b.second;
	};
	sort(topk.begin(),topk.end(), comp);

	return topk;
}