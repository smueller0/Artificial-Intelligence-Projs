// TEAM MEMBERS:
// Jordan Finney, Mason Greenwell, Sarah Mueller

// Project 2: Implement A* algorithm 
// tasks ----
// 1. create an 8 sqaure puzzle game
// 2. Each team member must create his/her own heuristic function
// 3. Analyze the performance of the algorithm by running your program for three heuristic functions discussed in the class and the heuristic functions created by the team
// 4. print the following... 
//     * execution time (ET)
//     * number of nodes generated (NG)
//     * number of nodes expanded (NE)
//     * depth of the tree (D)
//     * effective branching factor b* (NG/D)
//     * Total path (TP)

// **note: two inital state are already given 
// the heuristic function outline is already given 
// run the program 12 times
// 6 functions + 2 tables each 
// outline for the inital state tables are given 
// input user input to run and call functions one at a time 
#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>
#include <iomanip>
//#include <bits/stdc++.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <chrono>
#include "Files.h"

using namespace std;
using namespace std::chrono;

void Up(vector<vector<vector<int>>> &NodeStorage, int x, int i, int j, int &moved);
void Down(vector<vector<vector<int>>> &NodeStorage, int x, int i, int j, int &moved);
void Left(vector<vector<vector<int>>> &NodeStorage, int x, int i, int j, int &moved);
void Right(vector<vector<vector<int>>> &NodeStorage, int x, int i, int j, int &moved);
int StoreNode(vector<vector<vector<int>>> &NodeStorage, int &x, int i, int j, int &moved, int &arrPos);
int NodeChildren(vector<vector<vector<int>>> &NodeStorage, vector<vector<vector<int>>> &Successor, int &x, int i, int j, int &moved, int &arrPos);
int NumOfChildren(vector<vector<vector<int>>> &NodeStorage, int &x, int i, int j);

//int HeuristicMason(vector<vector<int>> goalNode, vector<vector<vector<int>>> &NodeStorage, int &x, int i, int j);

typedef struct node node;
struct node 
{
  vector<node*> children;
  int data;
};

int main()
{
  
  priority_queue<int> OpenSorted; //open has to be a priority queue
  int moved;
  int arrPos = 1;
  int equalsGoal = 0;
  int x = 0; //THIS MUST STAY DECLARED SEPERATELY FROM i AND j OTHERWISE WE GET A SEGFAULT??????????
  int i, j = 0;
  int choice;
  int g_value = 0;
  int h_prime;
  int f_prime;
  bool goalReached = 0;
  
  
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
  //priority_queue<int, vector<int>, greater<int> > OpenSet;
  vector<vector<vector<int>>> ClosedSet;
  vector<vector<vector<int>>> OpenSet(arrPos+1,vector<vector<int>>(3, vector<int>(3)));
  vector<vector<vector<int>>> Successor(arrPos+1,vector<vector<int>>(3, vector<int>(3,0)));//[arrPos+1][3][3]
  vector<vector<vector<int>>> NodeStorage(arrPos,vector<vector<int>>(3, vector<int>(3)));
  vector<vector<int>> CurrentNode(vector<vector<int>>(3, vector<int>(3)));
  vector<vector<int>> hPairing;
  
  //----------------------------------------------------------
  // starting A*
   do{
    cout << "Please pick a function to run (numbers 1-6)" << endl;
    cin >> choice;
  }while(choice > 7 || choice < 0 );
  

  cout << endl << endl;

//cout << "Heuristic Val : " << HeuristicThree(goalNode, NodeStorage,x) << endl;
  auto start = high_resolution_clock::now();
  for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
          NodeStorage[x][i][j] = initialOne[i][j]; //Stores first node in NodeStorage
          OpenSet[x][i][j] = initialOne[i][j]; //Adds the initial node to the OpenSet
          CurrentNode[i][j] = NodeStorage[x][i][j]; //Sets the initial node as the current node
          }
    }
  while(!OpenSet.empty())
  {
    if(choice == 1){
      h_prime = HeuristicOne(NodeStorage, goalNode, x);
    }
    else if(choice == 2){
      h_prime = HeuristicTwo(goalNode, NodeStorage, x, i, j);
    }
    else if(choice == 3){
      h_prime = HeuristicThree(goalNode, NodeStorage, x);
    }
    else if(choice == 4){
      h_prime = HeuristicJordan(goalNode, NodeStorage, x, i, j);
    }
    else if(choice == 5){
      h_prime = HeuristicMason(goalNode, NodeStorage, x, i, j);
    }
    else if(choice == 6){
      h_prime = HeuristicSarah(NodeStorage,goalNode, x);
    }
    f_prime = h_prime + g_value;
    // find lowest f_value; 
    // this causes seg fault 
    StoreNode(NodeStorage, x, i, j, moved, arrPos);
    
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      if (CurrentNode[i][j] == goalNode[i][j]){ //Segfault happens here when testing HeuristicOne for the first two children
        equalsGoal++;
      }else{
        equalsGoal = 0;
        moved = NumOfChildren(NodeStorage, x, i, j);
        NodeChildren(NodeStorage, Successor, x, i, j, moved, arrPos); 
        //NodeChildren sucessfully exist within (Successor[x][i][j]) at this point.
      }
    }
    }
    int exists[x];
    // seg fault in here ****

    // for(x = 0; x < NumOfChildren(NodeStorage, x, i, j); x++){
    //         for(int i = 0; i < 3; i++){
    //           for(int j = 0; j < 3; j++){
    //               if(Successor[x][i][j] == OpenSet[x][i][j]){
    //                 exists[x] += 1;
    //               }else{
    //                 exists[x] = 0;
    //               }
    //             }
    //           cout << endl;
    //           }
    //         if(exists[x] < 8)
    //           exists[x] = 0;
    //       }

    int NumberOfChildren = NumOfChildren(NodeStorage, x, i, j);
  for(int x = 0; x < NumberOfChildren; x++){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
          if(exists[x] == 8){
              ClosedSet[x][i][j] = Successor[x][i][j];
            }
          else if(exists[x] == 0){
              OpenSet[x][i][j] = Successor[x][i][j];
            }
          else{
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by function: " << duration.count() << " ms" << endl;


  cout << "Initial State #1: " << endl;
  cout << "_________________________________________________" << endl;
  cout << "|Heuristic Function" << setw(4) << "ET" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  cout << "|_______________________________________________|" << endl;
    
  cout << "|6 entries" << setw(11) << duration.count() << "ms" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  cout << "|_______________________________________________|" << endl;
  cout << endl;
  cout << endl;
    cout << "Initial State #2: " << endl;
  cout << "_________________________________________________" << endl;
  cout << "|Heuristic Function" << setw(4) << "ET" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  cout << "|_______________________________________________|" << endl;
    cout << "|6 entries" << setw(11) << duration.count() << "ms" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  cout << "|_______________________________________________|" << endl;

            
            return 0;
            //break;
          }
        }
      } cout << endl;
    }
    int bestHValue = 0;
    int xOfBestH;
    for(int x = 0; x < NumberOfChildren; x++){
        for(int i = 0; i < 3; i++){
          for(int j = 0; j < 3; j++){
            if(HeuristicOne(Successor, goalNode, x) > bestHValue){
            bestHValue = HeuristicOne(Successor, goalNode, x);
            xOfBestH = x;
            }
          }
        }
      } 
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        CurrentNode[i][j] = Successor[xOfBestH][i][j];
      }
    }
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
cout << "Time taken by function: " << duration.count() << " ms" << endl;

  cout << "Initial State #1: " << endl;
  cout << "_________________________________________________" << endl;
  cout << "|Heuristic Function" << setw(4) << "ET" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  cout << "|_______________________________________________|" << endl;
    
  cout << "|6 entries" << setw(13) << duration.count() << "ms" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  cout << "|_______________________________________________|" << endl;
  cout << endl;
  cout << endl;
    cout << "Initial State #2: " << endl;
  cout << "_________________________________________________" << endl;
  cout << "|Heuristic Function" << setw(4) << "ET" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  cout << "|_______________________________________________|" << endl;
    cout << "|6 entries" << setw(13) << "ET" << setw(5) << "NG" << setw(5) << "NE" << setw(5) << "D" << setw(5) << "b*" << setw(5) << "TP" << "|" << endl;
  cout << "|_______________________________________________|" << endl;
  
    if(equalsGoal == 8){
      cout << "The goal state has been reached!" << endl;
      goalReached = 1;
    }

  }
  cout << "FAILURE" << endl;
  return 0;
}

//Code to move 0 around in the node
    void Up(vector<vector<vector<int>>>&NodeStorage, int x, int i, int j, int &moved){
    swap(NodeStorage[x][i][j], NodeStorage[x][i-1][j]); //Swaps two values.
      //The values above are 0, and one digit up from 0 respectively
}
    void Down(vector<vector<vector<int>>>&NodeStorage, int x, int i, int j, int &moved){
      swap(NodeStorage[x][i][j], NodeStorage[x][i+1][j]);
      //The values above are 0, and one digit down from 0, respectively
  }
    void Left(vector<vector<vector<int>>>&NodeStorage, int x, int i, int j, int &moved){
      swap(NodeStorage[x][i][j], NodeStorage[x][i][j-1]);
      //The values above are 0, and one digit to the left of 0, respectively
  }
    void Right(vector<vector<vector<int>>>&NodeStorage, int x, int i, int j, int &moved){
      swap(NodeStorage[x][i][j], NodeStorage[x][i][j+1]);
      //The values above are 0, and one digit to the right of 0, respectively
  }

  int StoreNode(vector<vector<vector<int>>> &NodeStorage, int &x, int i, int j, int &moved, int &arrPos){
    NodeStorage.resize(arrPos+1,vector<vector<int>>(3, vector<int>(3))); //resizes NodeStorage to accomodate a new node
    x+=1; //increments x so that the code now looks at the empty vector to store the next node
    arrPos+=1; //For some reason the .resize above that's supposed to resize NodeStorage doesn't add a new Node space, so this does that

    for(int i = 0; i < 3; i++)
      {
      for(int j = 0; j < 3; j++)
        {
          //cout << NodeStorage[x][i][j];
          //cout << NodeStorage[x-1][i][j] << "THIS IS NODE RN" << endl;
          NodeStorage[x][i][j] = NodeStorage[x-1][i][j];  //Stores the node in position x-1 (previous node) so that we can create children nodes
        }
      }
    return 0;
}
  int NodeChildren(vector<vector<vector<int>>> &NodeStorage, vector<vector<vector<int>>> &Successor,int &x, int i, int j, int &moved, int &arrPos){
    //Below code is used for generating all possible children based on 0's location 
    int y = 0;
int stop = 0;
    for(int i = 0; i < 3; i++)
      {
      for(int j = 0; j < 3; j++)
        {
          if(NodeStorage[x][i][j] == 0){ //This makes sure the program is currently looking at 0
              if(i > 0){ //move up
                if(stop < moved){
                    for(int i = 0; i < 3; i++)
                      {
                        for(int j = 0; j < 3; j++)
                        {
                          Successor[y][i][j] = NodeStorage[x][i][j];
                        }
                      }
                
                Up(Successor, y, i, j, moved);
                  stop++;
                  y++;
                  }
              }
              if(i < 2){ //move down
                if(stop < moved){
                    for(int i = 0; i < 3; i++)
                      {
                        for(int j = 0; j < 3; j++)
                        {
                          Successor[y][i][j] = NodeStorage[x][i][j];
                        }
                      }
                Down(Successor, y, i, j, moved);
                  stop++;
                  y++;
                  }
              }
              if(j < 2){ //move right
                if(stop < moved){
                    for(int i = 0; i < 3; i++)
                      {
                        for(int j = 0; j < 3; j++)
                        {
                          Successor[y][i][j] = NodeStorage[x][i][j];
                        }
                      }
                Right(Successor, y, i, j, moved);
                  stop++;
                  y++;
                  }
              }
              if(j > 0){ //move left
                if(stop < moved){
                    for(int i = 0; i < 3; i++)
                      {
                        for(int j = 0; j < 3; j++)
                        {
                          Successor[y][i][j] = NodeStorage[x][i][j];
                        }
                      }
                Left(Successor, y, i, j, moved);
                  stop++;
                  y++;
                  }
              }
            }
        }
        }
    return 0;
    }

  int NumOfChildren(vector<vector<vector<int>>> &NodeStorage, int &x, int i, int j){
      int childrenCount = 0;
        if(i > 0){ //move up
          childrenCount+=1;
        }
        if(i < 2){ //move down
          childrenCount+=1;
        }
        if(j < 2){ //move right
          childrenCount+=1;
        }
        if(j > 0){ //move left
          childrenCount+=1;
        }
    return childrenCount;
  };


/*
    {2, 8, 3}, //i = 0
    {1, 6, 4}, //i = 1
    {0, 7, 5}  //i = 2
  //j= 0  1  2
*/

/*
Mason's progress notes:
-I HAVE NOT IMPLEMENTED ANYTHING TO RETURN FAIL IF OPEN IS EMPTY
-Got the swap functions fully functional
-Found a bug in the swap functions that cause 0 to swap multiple places
  -Potential fix: variable moved set to 0, increments right after a 
  -Fix in progress, trying to figure out where to reset moved variable back to 0
-Started working on getting the code to automatically generate and store every node
  -Generation in works
    -Need movement implemented for full functionality
  -All generated nodes stored in a general location
    -can call a generated node by using NodeStorage[x][i][j]
      -x is the position the node is being stored at
      -i and j stores the values in the node
      -Assign g_value, h_prime, and f_prime in your function
    -Move nodes generated for the first time into OPEN (3D Vec - needs to be created)
      -Sort these nodes based on highest value (generated in heuristic functions)
    -Move nodes that have been generated (compare against OPEN nodes) into OLD (3D Vec - needs to be created)


____________________________________________________________________________________________________________________________--------------------------------------------------------
NodeStorage[x][i][j] holds all the generated nodes in an unsorted list.
-Create empty BestNode vector
  -Point BestNode vector to successor vector
    -Successor is found by adding g(BestNode) to the cost of getting from BestNode to successor
  -Need a vector to hold the current BestNode (vec needs to be 3D, but it only needs to hold one node).
    -Need to find the possible children nodes of BestNode
      -Check OPEN to see if any of the children nodes have been generated already
        -If a child node has been generated already put it into OLD
  -Need to move the nodes that have not been generated yet into a new vector (a.k.a OPEN as described in the project instructions) that is sorted by best value.


The movement function is not implemented yet
  -Need to create the stuff described above first
  -Find the position of 0 in the node (already done)
    -Generate children nodes of that node
  -Any child node that meets the appropriate conditions for movement (see above ^) find where the 0 is eligible to be moved to (Up, Down, Left, Right) based off of it's position.
  -Store any results from the previous step in a 3D vector used for the sole purpose of holding the current successors.
*/
//---------------------------------------------------------------
/*
    {2, 8, 3}, //i = 0
    {1, 6, 4}, //i = 1
    {0, 7, 5}  //i = 2
//j= 0  1  2
*/
//-------------------------------------------------------------
/*
  Jordan's Progress Notes 
  step 1: trying to get the children nodes to generate 
  ideas:
      #1 : using the fork() keyword. The fork keyword produces a parent and 3     children. which we can use to automatically generate. article posted in discord
          + pid_t id1 = fork();
          + actually I think this is just for the c language but im not sure...
      #2 : we can use a struct and a function to keep the structure of the child, like its value, and keep track of what the child num is... maybe like this
          template <class T>
          struct TreeNode
          {
              vector<TreeNode*> children;
               T value;
          };


      keep in mind... 
          + generating children all depend on where the 0 is in the sqaure 
          + keep in mind the blocks 
          + keep in mind movements of the Up, Down, Left, Right 
          + g(n) keeps track of each generation
          + root node starts at g(n) = 0 
          + open will be a priotity queue 
          + then a vector for closed 
*/
//------------------------------------------------------------------
//---------------------------------------------------------------
/*
      + For each run print the execution time (ET)          
            https://www.geeksforgeeks.org/measure-execution-time-function-cpp/
            THIS IS ALREADY DONE (:
      + the number of nodes generated (NG)
            we need a counter for this 
      + the number of nodes expanded (NE)
            number of children generated? 
      + depth of the tree (D)
            g(n) = depth of tree 
            THIS IS ALREADY DONE (: 
      + effective branching factor b* (NG, D)
            b* = NG^(1/D)
            N = Number of nodes generated (NG)
            d = depth that goal was found at (D or g value) 
              + pow(base,exponent)
      + the Total path (TP) 
            total path from initial node to goal node 
*/
/*
HOW TO MAKE A PRIORITY QUEUE 
  priority_queue<int> variable_name;  
    - this was top ()
    - This function is used to address the topmost element of a priority queue
        - priority queue will do sorting for you 
        - top looks like its sorts 
        - generate the children of the node youre expanding and add them to it 
        - COUSTUM COMPARBLE 
        - priority_queue <int, vector<int>, greater<int>> g = gq;
          - ^^ maybe this?? 
*/