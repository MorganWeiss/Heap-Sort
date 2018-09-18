//
//  main.cpp
//  Heap Sort
//
//  Created by Morgan Weiss on 8/15/2018
//  Copyright © 2018 Morgan Weiss. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <ostream>


template <class T>
void heapify(std::vector<T>& data, int n, int i) {
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	// Case 1: check if left > largest, if it is set largest = left
	if ( left < n && data[left] > data[largest]) {
		largest = left;
	}

	// Case 2: check if right > largest, if it is set largest = right
	if ( right < n && data[right] > data[largest]) {
		largest = right;
	}

	// Case 3: repeat case 1 and 2 for every exisitng subtree
	if (largest != i) {
		std::swap(data[i], data[largest]); // swap so that the root node will be the largest after each check of the child nodes

		heapify(data, n, largest);
	}
}

template <class T>
void maxHeap(std::vector<T>& data) {
	int n = data.size();
	for (int i = n / 2; i >= 0; i--) {
		heapify(data, n, i);
	}
}

template <class T>
void heapSort(std::vector<T>& data) {
	int n = data.size() - 1;
	maxHeap(data);
	for (int i = n; i >= 0; i--) {
		std::swap(data[0], data[i]);
		heapify(data, i, 0); // this is to ensure that we get the largest element as the root
	}
}

template <class T>
void print(std::vector<T>& data) {
	int n = data.size();
	for (int i = 0; i < n; i++) {
		std::cout << data[i] << " ";
	}
}

int main() {

	std::vector<int> a = { 4,10,3,5,1 };
	heapSort(a);
	print(a);

	
	std::cin.get();
}