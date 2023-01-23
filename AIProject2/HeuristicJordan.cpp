#include "Files.h"
#include <vector>
#include <iostream>


using namespace std;
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


int HeuristicJordan(vector<vector<int>> &goalNode, vector<vector<vector<int>>> &NodeStorage, int &x, int i, int j){
  int hPrime;
  if (NodeStorage[x][0][0] == goalNode[0][0])
  {
    hPrime += 1;
  }
  if(NodeStorage[x][0][2] == goalNode[0][2])
  {
    hPrime += 1;
  if(NodeStorage[x][2][0] == goalNode[2][0])
  {
    hPrime += 1;
  }
  if(NodeStorage[x][2][2] == goalNode[2][2])
  {
     hPrime += 1;
  }
  }
  return hPrime;
}