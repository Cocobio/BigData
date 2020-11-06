#include "MisraGries.hpp"

template<class T>
void MisraGries<T>::update(stream_value v) {
	if (AH.increment(v,1));
	else if (AH.size()<K) AH.push(v,1);
	else if(AH.top().first == 0) {
		AH.pop();
		AH.push(v,1);
	}
	else
		AH.decrement_all(1);
}

template<class T>
void MisraGries<T>::update(stream_value v, size_t c) {
	if (AH.size()<K)
		AH.push(v,c);
	else if (AH.increment(v,c));
	else if(AH.top().first < c) {
		size_t smallest = AH.top().first;
		AH.pop();
		AH.decrement_all(smallest);
		AH.push(v,c-smallest);
	}
	else
		AH.decrement_all(c);
}

template<class T>
vector<pair<T,size_t>> MisraGries<T>::topK() {
	vector<pair<stream_value,size_t>> topk;
	topk.reserve(K);

	for(auto it = AH.heap_cbegin(); it!=AH.heap_cend(); it++)
		if (it->first!=0)
			topk.push_back(make_pair(it->second,it->first));

	auto comp = [](pair<stream_value,size_t> a, pair<stream_value,size_t> b) { return a.second>b.second; };
	sort(topk.begin(), topk.end(), comp);

	return topk;
}

