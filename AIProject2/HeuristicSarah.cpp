// TEAM MEMBERS:
// Jordan Finney, Mason Greenwell, Sarah Mueller

// Project 2: Implement A* algorithm 
/*
how many tiles are in the correct spot (subtract 1)
and how many are in the wrong (add 1)
this will show how far it is from the goal (where all 8 tiles are in the correct spot)
Goal state:
1 2 3
8 _ 4           h(n) = -8
7 6 5

Initial state 1:
2 8 3
1 6 4          h(n) = 3
_ 7 5

Initial state 2:
2 1 6
4 _ 8          h(n) = 8
7 5 3
*/
#include "Files.h"
#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>

using namespace std;

int HeuristicSarah(vector<vector<vector<int>>> &NodeStorage, vector<vector<int>> &goalNode, int &x){
  int hPrime = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(NodeStorage[x][i][j] == goalNode[i][j]){
        hPrime--;
      }
      else{
        hPrime++;
      }
    }
  }
  return hPrime;
}