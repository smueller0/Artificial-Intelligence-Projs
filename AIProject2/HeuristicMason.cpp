/*
Amount of numbers adjacent to their correct position

complete ex.
1 2 3
8 _ 4
7 6 5

ex.
3 1 2
4 8 _
7 6 5


h(n) =  4

*/
/*
How many tiles are in the correct corner spots ... 
    vector<vector<int>> goalNode{
    {1, 2, 3}, //i = 0
    {8, 0, 4}, //i = 1
    {7, 6, 5}  //i = 2
  //j= 0  1  2
};  
   vector<vector<int>> initialOne{
    {2, 8, 3}, //i = 0
    {1, 6, 4}, //i = 1
    {0, 7, 5}  //i = 2
  //j= 0  1  2
};
    vector<vector<int>> initialTwo{
    {2, 1, 6}, //i = 0
    {4, 0, 8}, //i = 1
    {7, 5, 3}  //i = 2
  //j= 0  1  2
};
*/
#include "Files.h"
#include <vector>
#include <iostream>

using namespace std;

int HeuristicMason(vector<vector<int>> &goalNode, vector<vector<vector<int>>> &NodeStorage, int &x, int i, int j){
  int hPrime = 0;
      if (NodeStorage[x][1][0] == goalNode[1][0])
  {
    hPrime += 1;
  }
  if(NodeStorage[x][1][2] == goalNode[1][2])
  {
    hPrime += 1;
  if(NodeStorage[x][2][1] == goalNode[2][1])
  {
    hPrime += 1;
  }
  if(NodeStorage[x][1][0] == goalNode[1][0])
  {
     hPrime += 1;
  }
  }
  return hPrime;
}