/*
	* Author : Fakhra Najm<fnajm09@gmail.com>
	* Topic  : Graph implementation
	* Operations:
		* BFS
		* DFS
*/

#include<iostream>
#include <vector>
#include <queue>
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
		for(int neighbour = 1; neighbour <= vertices; ++neighbour){
			if(is_vertex_visited[neighbour] == false && adjacency_matrix[row][neighbour] == 1){
				cout << neighbour << " ";
				queue.push(neighbour);
				is_vertex_visited[neighbour] = true;
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
		for(int neighbour = 1; neighbour < vertices; ++neighbour){
			if(adjacency_matrix[vertex][neighbour] == 1 && is_vertex_visited[neighbour] == false)
				DFS(adjacency_matrix, neighbour, vertices);
		}
	}
}

int main(){
	int G[7][7] = 
	{
		{0,0,0,0,0,0,0},
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