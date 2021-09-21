#include<iostream>
#include <vector>
#include <climits>
using namespace std;

#define inf INT_MAX

class spanningTree{
	// Matrix[row][col] = x is sthe cost of edge between row and col
	vector<vector<int>>adjacencyMatrix; 
	// Represents minimum cost edge between two vertex 
	vector<vector<int>>minCostArray;
	// Used to keep track of visited vertices and near edges of visited vertices
	vector<int>nearEdges;
	// Size of the adjacency matrix
	int vertices;
	// First minimum cost between vertex1 and vertex2
	int vertex1;
	int vertex2;
public:
	spanningTree(vector<vector<int>>adjacencyMatrix);
	// Filling initial near edges at infinity
	void fillNearEdges();
	// Finds first minimum edge and store vertex into this -> vertex1 and this -> vertex2
	void findMin();
	// Updates the nearEdges of vertex1 and vertex2 int nearEdges Array
	void updateEdgeCost();
	// Finds minimum of nearEdges and store it in the minCostArray one by one
	// Visited vertices are marked zero in the nearEdges Array 
	void generateMinCostSpanningTree();
	void printMinCostSpanningTree();
};

spanningTree :: spanningTree(vector<vector<int>>adjacencyMatrix){
	this -> vertices = adjacencyMatrix.size();
	this -> adjacencyMatrix = adjacencyMatrix;
	fillNearEdges();
	findMin();
	updateEdgeCost();
	generateMinCostSpanningTree();
}

void spanningTree :: fillNearEdges(){
	for(int index = 0; index < vertices - 1; ++index){
		nearEdges.push_back(inf);
	}
}

void spanningTree :: findMin(){
	// guard condition
	if(vertices == 0) return;
	// checking upper triangular matrix
	// upper triangular and lower triangular represent same edges
	int minCostEdge = inf;
	for(int row = 1; row < vertices; ++row){
		for(int col = row; col < vertices; ++col){
			if(adjacencyMatrix[row][col] < minCostEdge){
				// updating minimum cost so far
				minCostEdge = adjacencyMatrix[row][col];
				// updating vertex having minimum cost so far
				vertex1 = row; 
				vertex2 = col;
			}
		}
	}
}

void spanningTree :: updateEdgeCost(){
	if(vertices == 0) return;
	// Mark vertex1 Nand vertex2 position 0 as it is visited
	// No need to visit again
	nearEdges[vertex1] = nearEdges[vertex2] = 0; 
	// Push first minimum cost Edge in the minCostArray
	minCostArray.push_back({vertex1, vertex2});
	// dividing the vertex int two parts
	// Nearer to vertex1 is Marked as the vertex1 in nearEdges 
	// Nearer to vertex2 is Marked as the vertex2 in nearEdges
	for(int row = 1; row < vertices; ++row){
		if(nearEdges[row] == 0) continue; // already visited
		if(adjacencyMatrix[row][vertex1] < adjacencyMatrix[row][vertex2])
			nearEdges[row] = vertex1; // nearEdges of row is nearer to vertex1
		else nearEdges[row] = vertex2; // nearEdges of row is nearer to vertex2
	}
}

void spanningTree :: generateMinCostSpanningTree(){
	// guard conditions
	if(vertices == 0) return;
	int minEdge = inf, row;
	for(int vertex = 1; vertex < vertices; ++vertex){
		for(int index = 1; index < vertices; ++index){
			if(nearEdges[index] == 0) continue;
			if(adjacencyMatrix[index][nearEdges[index]] < minEdge){
				minEdge = adjacencyMatrix[index][nearEdges[index]];
				row = index;
			}
		}
		// Next minimum cost edge is found at adjacencyMAtrix[row][nearEdges[index]]
		//	Update the minCostArray
		minCostArray.push_back({row, nearEdges[row]});
		// Marking vertex as visited
		nearEdges[row] = 0;
		// Update the nearEdges
		for(int edges = 1; edges < vertices; ++edges){
			if(nearEdges[edges] == 0) continue;
			if(adjacencyMatrix[edges][row] < adjacencyMatrix[edges][nearEdges[edges]]){
				nearEdges[edges] = row; 
			}
		}
	}
}

void spanningTree :: printMinCostSpanningTree(){
	if(vertices == 0) return;
	for(int row = 0; row < vertices - 1; ++row){
		for(auto vertex : minCostArray[row])
			cout << vertex << " ";
		cout << endl;
	}
}

int main(){
	vector<vector<int>>matrix = {
		{inf, inf, inf, inf, inf, inf, inf, inf},
		{inf, inf, 25, inf, inf, inf, 5, inf},
  	{inf, 25, inf, 12, inf, inf, inf, 10},
    {inf, inf, 12, inf, 8, inf, inf, inf},
  	{inf, inf, inf, 8, inf, 16, inf, 14},
    {inf, inf, inf, inf, 16, inf, 20, 18},
    {inf, 5, inf, inf, inf, 20, inf, inf},
    {inf, inf, 10, inf, 14, 18, inf, inf},
	};
	spanningTree spanning(matrix);
	spanning.printMinCostSpanningTree();
	return 0;
}