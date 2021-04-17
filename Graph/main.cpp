/*
	* Author : Fakhra Najm<fnajm09@gmail.com>
	* Topic  : Graph implementation
	* Operations:
		* BFS
		* DFS
*/

#include<bits/stdc++.h>
using namespace std;


void BFS (int adjacency_matrix[][7], int vertex, int vertices){

	queue<int>queue;
	vector<bool>is_vertex_visited(vertices, false);

	queue.push(vertex);
	is_vertex_visited[vertex] = true;
	cout << vertex << " ";

	while(!queue.empty()){
		int row = queue.front();
		queue.pop();

		for(int col = 1; col <= vertices; ++col){
			if(is_vertex_visited[col] == false && adjacency_matrix[row][col] == 1){
				cout << col << " ";
				queue.push(col);
				is_vertex_visited[col] = true;
			}
		}
	}
	cout << endl;
}

void DFS(int adjacency_matrix[][7], int vertex, int vertices){
	static vector<bool>is_vertex_visited(vertices, false);
	if(is_vertex_visited[vertex] == false){
		cout << vertex << " ";
		is_vertex_visited[vertex] = true;
		for(int col = 1; col < vertices; ++col){
			if(adjacency_matrix[vertex][col] == 1 && is_vertex_visited[col] == false)
				DFS(adjacency_matrix, col, vertices);
		}
	}
}

int main(){
	int G[7][7] = 
	{{0,0,0,0,0,0,0},
	{0,0,1,1,0,0,0},
	{0,1,0,0,1,0,0},
	{0,1,0,0,1,0,0},
	{0,0,1,1,0,1,1},
	{0,0,0,0,1,0,0},
	{0,0,0,0,1,0,0}
};
int vertex;
cout << "Enter vertex where to start : ";
cin >> vertex;
BFS(G, vertex, 7);
cout << "Enter vertex where to start : ";
cin >> vertex;
DFS(G, vertex, 7);
return 0;
}