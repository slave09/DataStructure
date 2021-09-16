#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class Heap{
	vector<int>heap;
public:
	// using 1 indexed Heap
	Heap(){heap.push_back(INT_MAX);}
	Heap(vector<int>values);
	int size(){return heap.size();}
	void heapify(vector<int>values);
	void print();
};

int main(){
	Heap heap({-1,30,20,15,5,10,12,6,40});
	cout << "Heap using heapify: ";
	heap.print();
	return 0;
}

Heap :: Heap(vector<int>values){
	heap.push_back(INT_MAX);
	heapify(values);
}

void Heap :: heapify(vector<int>values){
	int size = values.size() - 1;
	int nodePtr = size / 2;
	while(nodePtr > 0){
		int childNodePtr = nodePtr * 2;
		if(values[childNodePtr] < values[childNodePtr + 1])
			childNodePtr = childNodePtr + 1;
		if(values[childNodePtr] > values[nodePtr])
			swap(values[childNodePtr], values[nodePtr]);
		nodePtr /= 2;
	}
	heap.swap(values);
	heap.front() = INT_MAX; // 0th index is useless here 
}

void Heap :: print(){
	for(int index = 1; index < size(); ++index){
		cout << heap[index] << " ";
	}
	cout << endl;
}