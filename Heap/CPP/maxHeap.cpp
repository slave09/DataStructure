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
	vector<int> getHeapArray(){return heap;}

	void push(int val);
	int pop();
	void print();
	vector<int> heapSort();
};

void print(vector<int>arr){
	for(int index = 0; index < arr.size(); ++index)
		cout << arr[index] << " ";
	cout << endl;
}

int main(){
	Heap heap({30,20,15,5,10,12,6,40});
	cout << "Heap:" << endl; 
	heap.print();
	cout << "Heap Sort:" << endl;
	print(heap.heapSort());
	return 0;
}

Heap :: Heap(vector<int>values){
	heap.push_back(INT_MAX);
	for(int index = 0; index < values.size(); ++index){
		push(values[index]);
	}
}

void Heap :: push(int val){
	heap.push_back(val);
	int index = size() - 1;
	int parentNodeIndex = index / 2;
	while(heap[parentNodeIndex] < heap[index]){
		swap(heap[parentNodeIndex], heap[index]);
		index = parentNodeIndex;
		parentNodeIndex /= 2;
	}
}

int Heap :: pop(){
	if(heap.size() == 1) return -1;
	int parentNodePtr = 1;
	int childNodePtr = 2 * parentNodePtr;
	int lastNodePtr = size() - 1;
	int top = heap[parentNodePtr];
	swap(heap[parentNodePtr], heap[lastNodePtr]);
	// lastNodePtr = size() - 1;
	heap.pop_back();

	while(childNodePtr + 1 < lastNodePtr){
		if(heap[childNodePtr] < heap[childNodePtr + 1])
			childNodePtr = childNodePtr + 1;
		if(heap[parentNodePtr] < heap[childNodePtr]){
			swap(heap[parentNodePtr], heap[childNodePtr]);
			parentNodePtr = childNodePtr;
			childNodePtr = 2*parentNodePtr;
		}
		else break;
	}

	return top;
}

vector<int> Heap :: heapSort(){
	int heapSize = Heap :: size();
	vector<int>sortedArray;
	while(heapSize > 0){
		int topValue = pop();
		if(topValue != -1) 
			sortedArray.push_back(topValue);
		heapSize--;
	}
	return sortedArray;
}

void Heap :: print(){
	for(int index = 1; index < size(); ++index){
		cout << heap[index] << " ";
	}
	cout << endl;
}