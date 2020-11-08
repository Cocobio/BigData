#include "AssociativeHeap.hpp"

/*
Makes sures that the element ith in the heaps maintains the property compare to the parent
If not, it bubbles up and updates the keys to index hash.
*/
template<class K, class T, class Container, class Compare>
void AssociativeHeap<K,T,Container,Compare>::bubble_up(size_t i){
	_BUBBLE_UP_TR:
	// We identify the node and the children
	size_t child = i;
	size_t parent = (i-1)/2;

	// We select the node that preserves the max (or min) property of the heap
	if (parent<child && eval(heap[parent],heap[child])) child = parent;

	// If we have to make a swap, we recursively call heapify to maintain the property on swapped child
	if (child!=i) {
		keys_to_heap_i[heap[i].second] = child;
		keys_to_heap_i[heap[child].second] = i;
		swap(heap[i], heap[child]);

		i = child;
		goto _BUBBLE_UP_TR;
	}
}

/*
Makes sures that the element ith in the heaps maintains the property compare to its children
If not, it bubbles down until the heap property is true again
*/
template<class K,class T, class Container, class Compare>
void AssociativeHeap<K,T,Container,Compare>::bubble_down(size_t i){
	_BUBBLE_DOWN_TR:
	// We identify the node and the children
	size_t root = i;
	size_t lc = 2*i+1;
	size_t rc = 2*i+2;


	// We select the node that preserves the max (or min) property of the heap
	if (lc<heap.size() && eval(heap[root], heap[lc])) root = lc;
	if (rc<heap.size() && eval(heap[root], heap[rc])) root = rc;

	// If we have to make a swap, we recursively call heapify to maintain the property on swapped child
	if (root!=i) {
		keys_to_heap_i[heap[i].second] = root;
		keys_to_heap_i[heap[root].second] = i;
		swap(heap[i], heap[root]);

		i = root;
		goto _BUBBLE_DOWN_TR;
	}
}

template<class K, class T, class Container, class Compare>
void AssociativeHeap<K,T,Container,Compare>::heapify() {
	for (size_t i=heap.size()/2-1; i>=0; i--)
		bubble_down(i);
}


template<class K, class T, class Container, class Compare>
std::pair<typename AssociativeHeap<K,T,Container,Compare>::value_type,
		  typename AssociativeHeap<K,T,Container,Compare>::key_type> AssociativeHeap<K,T,Container,Compare>::top() {
	return heap[0];
}

template<class K, class T, class Container, class Compare>
void AssociativeHeap<K,T,Container,Compare>::pop() {
	// value_type M = heap[0].first;
	// size_t C = heap[0].second;

	keys_to_heap_i.erase(heap[0].second);
	keys_to_heap_i[heap[heap.size()-1].second] = 0;
	swap(heap[0],heap[heap.size()-1]);
	// heap[0] = heap[heap.size()-1];
	heap.pop_back();

	bubble_down(0);
}

template<class K, class T, class Container, class Compare>
void AssociativeHeap<K,T,Container,Compare>::push(key_type M, value_type C) {
	// if already added return
	if (keys_to_heap_i.find(M)!=keys_to_heap_i.end())
		return;

	keys_to_heap_i[M] = heap.size();
	heap.push_back(std::make_pair(C,M));

	bubble_up(heap.size()-1);
}

template<class K, class T, class Container, class Compare>
void AssociativeHeap<K,T,Container,Compare>::push(std::pair<value_type,key_type> MC) {
	// if already added return
	if (keys_to_heap_i.find(MC.second)!=keys_to_heap_i.end())
		return;

	keys_to_heap_i[MC.second] = heap.size();
	heap.push_back(MC);

	bubble_up(heap.size()-1);
}




template<class K, class T, class Container, class Compare>
const size_t AssociativeHeap<K,T,Container,Compare>::size() {
	return heap.size();
}

template<class K, class T, class Container, class Compare>
bool AssociativeHeap<K,T,Container,Compare>::update(key_type M, value_type C) {
	if (keys_to_heap_i.find(M)==keys_to_heap_i.end())
		return false;

	size_t i = keys_to_heap_i[M];
	heap[i].first = C;

	bubble_up(i);
	if (keys_to_heap_i[M]==i)
		bubble_down(i);

	return true;
}

template<class K, class T, class Container, class Compare>
bool AssociativeHeap<K,T,Container,Compare>::update(std::pair<value_type,key_type> MC) {
	if (keys_to_heap_i.find(MC.second)==keys_to_heap_i.end())
		return false;

	size_t i = keys_to_heap_i[MC.second];
	heap[i].first = MC.first;

	bubble_up(i);
	if (keys_to_heap_i[MC.second]==i)
		bubble_down(i);

	return true;
}



// #include <iostream>
// using namespace std;

// template<class K, class T, class Container, class Compare>
// void AssociativeHeap<K,T,Container,Compare>::print() {
// 	for (auto &h:heap)
// 		cout << h.first << " ";
// 	cout << endl;
// }
