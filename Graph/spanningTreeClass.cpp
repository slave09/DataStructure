#include<iostream>
#include <vector>
#include <climits>
using namespace std;

#define inf INT_MAX

class spanningTree{
	vector<vector<int>>adjacencyMatrix;
	vector<vector<int>>minCostArray;
	vector<int>nearEdges;
	int vertices;
	int vertex2;
	int vertex1;
public:
	spanningTree(vector<vector<int>>adjacencyMatrix);
	void findMin();
	void updateEdgeCost();
	void generateMinCostSpanningTree();
	void printMinCostSpanningTree();
};

spanningTree :: spanningTree(vector<vector<int>>adjacencyMatrix){
	this -> vertices = adjacencyMatrix.size();
	this -> adjacencyMatrix = adjacencyMatrix;
	fill(nearEdges.begin(),nearEdges.begin() + vertices,inf);
	findMin();
	updateEdgeCost();
}

void spanningTree :: findMin(){
	if(vertices == 0) return;
	int minCostEdge = inf;
	// checking upper triangular matrix
	// upper triangular and lower triangular represent same edges
	for(int row = 1; row < vertices; ++row){
		for(int col = row; col < vertices; ++col){
			if(adjacencyMatrix[row][col] < minCostEdge){
				minCostEdge = adjacencyMatrix[row][col];
				vertex1 = row;
				vertex2 = col;
			}
		}
	}
}

void spanningTree :: updateEdgeCost(){
	if(vertices == 0) return;
	nearEdges[vertex1] = nearEdges[vertex2] = 0;
	minCostArray.push_back({vertex1, vertex2});
	for(int row = 1; row < vertices; ++row){
		if(nearEdges[row] == 0) continue;
		if(adjacencyMatrix[row][vertex1] < adjacencyMatrix[row][vertex2])
			nearEdges[row] = vertex1;
		else nearEdges[row] = vertex2;
	}
}

void spanningTree :: generateMinCostSpanningTree(){
	if(vertices == 0) return;
	int minEdge = inf, row;
	for(int vertex = 1; vertex < vertices - 1; ++vertex){
		for(int index = 1; index < vertices; ++index){
			if(nearEdges[index] == 0) continue;
			if(adjacencyMatrix[index][nearEdges[index]] < minEdge){
				minEdge = adjacencyMatrix[index][nearEdges[index]];
				row = index;
			}
		}
		minCostArray.push_back({row, nearEdges[row]});
		nearEdges[row] = 0;
	}
}

void spanningTree :: printMinCostSpanningTree(){
	if(vertices == 0) return;
	for(int row = 0; row < vertices; ++row){
		for(auto vertex : minCostArray[row])
			cout << vertex << " ";
	}
	cout << endl;
}

int main(){
	spanningTree spanning({});
	return 0;
}