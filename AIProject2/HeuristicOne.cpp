#include "Files.h"
#include <vector>
#include <iostream>


using namespace std;
/*
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
The simplest heuristic counts the tiles out of place in 
each state when it is compared with the goal.
*/


int HeuristicOne(vector<vector<vector<int>>> &NodeStorage, vector<vector<int>> &goalNode, int &x){
  int hPrime = 0; //Maybe make hPrime an array, so we can correlate the hPrime value to a node position through the x value. For example, hPrimeArr[1] would hold the hPrime value of the node stored in OpenNode[1][i][j]
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(NodeStorage[x][i][j] != goalNode[i][j]){
        if(NodeStorage[x][i][j] != 0)
        hPrime++;
      }
    }
  }
  
  return hPrime;
}