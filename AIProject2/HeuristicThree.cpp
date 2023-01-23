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
2x the number of tile reversals
H3: The number of direct tile reversals multiplied by 2 (a direct tile reversal is when two adjacent tiles must be swapped to match the goal order)
*/


int HeuristicThree(vector<vector<int>> &goalNode, vector<vector<vector<int>>> &NodeStorage, int &x){
 int hPrime = 0;
  int val;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int m = 0; m < 3; m++){
        for(int n = 0; n < 3; n++){
          if(NodeStorage[x][i][j] == goalNode[m][n]){
            swap(NodeStorage[x][i][j], NodeStorage[x][m][n]);
            hPrime++;
          }
        }
      }
    }
  }
  
  return (2 * hPrime);
}