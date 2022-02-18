#include<iostream>
#include<vector>
#include <climits>
using namespace std;

#define inf INT_MAX

class DisjointSet{
protected:
  // size : no of vertices
  vector<int>set; // detect cycle 
  void Union(int node, int candidate);
  int Find(int node);
public:
  DisjointSet(){}
  DisjointSet(int size);
};

class Kruskalas : public DisjointSet{
private:
  int minCost; // Cost of edges of spanning tree
  int vertices; // Number of vertices in Graph
  // Number of edges in spanning tree = |Vertices - 1|
  int edges;
  vector<vector<int>>edgesCostArray; // size : no of edges
  // keeps track of visited edges
  vector<int>visited; // size : no of edges
  vector<vector<int>>minCostArray; // size : no of vertices - 1
public:
  Kruskalas();
  Kruskalas(vector<vector<int>>edgesCostArray, int vertices);
  int getMinimumCost(){return minCost;}
  vector<int> findMinEdge();
  void generateMinCostSpanningTree();
  void printSpanningTree();
};

int main(){
  vector<vector<int>>edges = {{1,2,25},{1,6,5},{2,3,12},{2,7,10},{3,4,8},{4,5,16},{4,7,14},{5,6,20},{5,7,18}};
  Kruskalas algo(edges, 7);
  cout << "Minimum Cost : " << algo.getMinimumCost() << endl;
  algo.printSpanningTree();
  return 0;
}

DisjointSet :: DisjointSet(int size){
  for(int index = 0; index <= size; ++index){
    set.push_back(-1);
  }
}

void DisjointSet :: Union(int node, int candidate){
  if(set[node] < set[candidate]){
    set[node] = set[node] + set[candidate];
    set[candidate] = node;
  }
  else{
    set[candidate] = set[candidate] + set[node];
    set[node] = candidate;
  }
}

int DisjointSet :: Find(int node){
  int index = node;
  int currRoot = 0;
  while(set[index] > 0){
    index = set[index];
  }
  // updating the parent's value in the set 
  while(node != index){
    currRoot = set[node];
    set[node] = index;
    node = currRoot;
  }
  return index;
}

Kruskalas :: Kruskalas(){
  this -> edges = 0;
  this -> minCost = 0;
}

Kruskalas :: Kruskalas(vector<vector<int>>edgesCostArray,int vertices) 
  :DisjointSet(vertices + 1){
  this -> vertices = vertices;
  this -> minCost = 0;
  this -> edges = edgesCostArray.size() - 1;
  this -> edgesCostArray = edgesCostArray;
  for(int index = 0; index <= edges; ++index){
    visited.push_back(0);
  }
  generateMinCostSpanningTree();
}

vector<int> Kruskalas :: findMinEdge(){
  if(edges == 0) return {-1,-1,-1};
  int minCostSoFar = inf;
  vector<int> minEdgeVertex(3,0);
  for(int index = 0; index <= edges; ++index){
    if(visited[index] !=  1 && minCostSoFar > edgesCostArray[index][2]){
      minEdgeVertex[0] = edgesCostArray[index][0];
      minEdgeVertex[1] = edgesCostArray[index][1];
      minEdgeVertex[2] = index;
      minCostSoFar = edgesCostArray[index][2];
    }
  }
  return minEdgeVertex;
}

void Kruskalas :: generateMinCostSpanningTree(){
  int node1, node2, parent1, parent2, minIndex;
  for(int index = 0; index < vertices - 1; ){
    vector<int>minEdge = findMinEdge();
    node1 = minEdge[0];
    node2 = minEdge[1];
    minIndex = minEdge[2];
    parent1 = Find(node1);
    parent2 = Find(node2);
    if(parent1 != parent2){
      minCost += edgesCostArray[minIndex][2];
      minCostArray.push_back({node1,node2});
      Union(parent1, parent2);
      index = index + 1;
    }
    visited[minIndex] = 1;
  }
}

void Kruskalas :: printSpanningTree(){
  for(int index = 0; index < minCostArray.size(); ++index){
    cout << "[" << minCostArray[index][0] << "]";
    cout << "------> ";
    cout << "[" << minCostArray[index][1] << "]";
    cout << endl;
  }
}