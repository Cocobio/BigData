#ifndef ASSOCIATIVE_HEAP
#define ASSOCIATIVE_HEAP

#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

template<class K, class T = int, class Container = std::vector<std::pair<T,K>>, class Compare = std::less<typename Container::value_type>>
class AssociativeHeap {
	typedef T	value_type;
	typedef K	key_type;

private:
	std::unordered_map<key_type,value_type> keys_to_heap_i;
	Container heap;
	Compare eval;

	void bubble_up(size_t i);
	void bubble_down(size_t i);
	void heapify();

public:
	AssociativeHeap() {};

	std::pair<value_type,key_type> top();
	void pop();
	void push(key_type M, value_type C);
	void push(std::pair<value_type,key_type> MC);

	bool update(key_type M, value_type C);
	bool update(std::pair<value_type,key_type> MC);

	// find

	const size_t size();

	// const value_type& operator[] (key_type key) {

	// }
	// void print();

	bool increment(key_type k, value_type v) { 
		if (keys_to_heap_i.find(k)!=keys_to_heap_i.end()) {
			update(k,heap[keys_to_heap_i[k]].first+v); 
			return true;
		}
		return false;
	}
	void decrement_all(value_type v) { for (auto &pair:heap) pair.first -= v; }
	typename Container::const_iterator heap_cbegin() { return heap.cbegin(); }
	typename Container::const_iterator heap_cend() { return heap.cend(); }

	bool is_in(key_type k) { return keys_to_heap_i.find(k)!=keys_to_heap_i.end(); }
};

#include "AssociativeHeap.cpp"

#endif

