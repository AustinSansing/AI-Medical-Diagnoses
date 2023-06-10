#ifndef H1N_H
#define H1N_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int h1n(int[3][3]);
//bool is_misplaced(int, int[2]);

/* h1n is number of misplaced tiles
Goal state of 
1: 0,0
2: 0,1
3: 0,2
4: 1,2
5: 2,2
6: 2,1
7: 2,0
8: 1,0
*/

bool is_misplaced(int value, int currPos[2]){ // Checking for number of tiles that are out of place 

  int currX = currPos[0];
  int currY = currPos[1];
  int goalX;
  int goalY;

  if(value == 1){
    goalX = 0;
    goalY = 0;
  }
  if(value == 2){
    goalX = 0;
    goalY = 1;
  }
  if(value == 3){
    goalX = 0;
    goalY = 2;
  }
  if(value == 4){
    goalX = 1;
    goalY = 2;
  }
  if(value == 5){
    goalX = 2;
    goalY = 2;;
  }
  if(value == 6){
    goalX = 2;
    goalY = 1;
  }
  if(value == 7){
    goalX = 2;
    goalY = 0;
  }
  if(value == 8){
    goalX = 1;
    goalY = 0;
  }
  if(value == 0){ //we dont record data for, blank square
    return false;
  }

  int goalPos[2] = {goalX, goalY};
  
  if(currX!= goalX || currY != goalY){
    return true;
  }
  else
    return false;
}

//Need to look at this
int h1n(int board[3][3]){

  int num_misplaced = 0;
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      int currValue = board[i][j];
      int currPos[2] = {i, j};
      if(is_misplaced(currValue, currPos))
        num_misplaced += 1;
    }
  }
  //cout<<"Misplaced Tiles: "<<num_misplaced<<endl;
  return num_misplaced;
}

#endif