#include "SpaceSaving.hpp"

template<class T>
void SpaceSaving<T>::update(stream_value v) {
	if (AH.increment(v,1));
	else if (AH.size()<K) AH.push(v,1);
	else {
		size_t z = AH.top().first;
		AH.pop();
		AH.push(v,z+1);
	}
}

template<class T>
void SpaceSaving<T>::update(stream_value v, size_t c) {
	if (AH.increment(v,c));
	if (AH.size()<K) AH.push(v,c);
	else {
		size_t z = AH.top().first;
		AH.pop();
		AH.push(v,z+c);
	}
}

template<class T>
vector<pair<T,size_t>> SpaceSaving<T>::topK() {
	vector<pair<stream_value,size_t>> topk;

	for(auto it = AH.heap_cbegin(); it!=AH.heap_cend(); it++)
		topk.push_back(make_pair(it->second,it->first));

	return topk;
}





