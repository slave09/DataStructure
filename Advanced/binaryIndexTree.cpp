/**
  Buid binary indexed tree using Array

  Use case: Range queries
    - finding sum from index i to j of an array.
  operations: 
    - update -> log(n)
    - read -> log(n)

  Reference: https://www.topcoder.com/community/competitive-programming/tutorials/range-minimum-query-and-lowest-common-ancestor/
*/
#include <iostream>
#include<vector>
using namespace std;

class BinaryIndexTree {
  vector<int> values;
  vector<int> binaryIndexTree;
  int maxIdx;

  // build tree using updates
  void build() {
    for(int i = 0; i < values.size(); i++) {
      update(values[i], i);
    }
  }
public:
  BinaryIndexTree(vector<int> values) {
    this -> values = values;
    this -> binaryIndexTree.resize(values.size() + 1);
    this -> maxIdx = binaryIndexTree.size();
    build();
  }
  // update binaryIndexTree after update in original array at index idx
  void update(int val, int idx) {
    values[idx] = val;
    idx++;
    while(idx <= maxIdx) {
      binaryIndexTree[idx] += val;
      idx += (idx & -idx); // toggle last set bit
    }
  }

  // returns sum from index 0 to idx
  int read(int idx) {
    int sum = 0;
    while(idx > 0) {
      sum += binaryIndexTree[idx];
      idx -= (idx & -idx); // mark last set bit to zero
    }
    return sum;
  }

  // print tree stored in array
  void show() {
    for(int i : binaryIndexTree) cout<<i<<',';
    cout<<endl;
  }
};

int main() {
  BinaryIndexTree tree(vector<int>{1,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2});
  cout<<"Sum of values from index 0 to index 13: "<< tree.read(13)<<endl;
  tree.show();
  tree.update(10,5);
  cout<<"Sum of values from index 0 to index 13: "<< tree.read(13)<<endl;
  tree.show();
  return 0;
}
