/*
	* Author : Fakhra Najm<fnajm09@gmail.com>
	* Topic  : Graph implementation
	* Operation :
		* BFS
		* DFS
*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
	int vertices;
	vector<vector<int>> adjacency_matrix;
public:
	Graph(int vertices){this -> vertices = vertices;}
	void BFS(int vertex);
	void DFS(int vertex);
};

void Graph :: BFS (int vertex){

	queue<int>queue;
	vector<bool>is_vertex_visited(vertices, false);

	queue.push(vertex);
	is_vertex_visited[vertex] = true;
	cout << vertex << " ";

	while(!queue.empty()){
		int row = queue.front();
		queue.pop();

		for(int col = 1; col < vertices; ++col){
			if(is_vertex_visited[col] == false && adjacency_matrix[row][col] == 1){
				cout << col << " ";
				queue.push(col);
				is_vertex_visited[col] = true;
			}
		}
	}
}

int main(){
	return 0;
}