#ifndef IDK_WHAT_THIS_DOES
#define IDK_WHAT_THIS_DOES

#include <vector>
#include <iostream>

using namespace std;

int HeuristicSarah(vector<vector<vector<int>>> &NodeStorage, vector<vector<int>> &goalNode, int &x);
int HeuristicMason(vector<vector<int>> &goalNode, vector<vector<vector<int>>> &NodeStorage, int &x, int i, int j);
int HeuristicJordan(vector<vector<int>> &goalNode, vector<vector<vector<int>>> &NodeStorage, int &x, int i, int j);
int HeuristicOne(vector<vector<vector<int>>> &NodeStorage, vector<vector<int>> &goalNode, int &x);
int HeuristicTwo(vector<vector<int>> &goalNode, vector<vector<vector<int>>> &NodeStorage, int &x, int i, int j);
int HeuristicThree(vector<vector<int>> &goalNode, vector<vector<vector<int>>> &NodeStorage, int &x);
#endif





  // cout << "Initial State #1: " << endl;
  // cout << "_________________________________________________" << endl;
  // cout << "|Heristic Function" << setw(4) << "ET" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  // cout << "|_______________________________________________|" << endl;
    
  // cout << "|6 entries" << setw(13) << "ET" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  // cout << "|_______________________________________________|" << endl;
  // cout << endl;
  // cout << endl;
  //   cout << "Initial State #2: " << endl;
  // cout << "_________________________________________________" << endl;
  // cout << "|Heristic Function" << setw(4) << "ET" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  // cout << "|_______________________________________________|" << endl;
  //   cout << "|6 entries" << setw(13) << "ET" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  // cout << "|_______________________________________________|" << endl;

  // cout << endl << endl;