#ifndef H2N_H
#define H2N_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int h2n_distance(int, int[2]);
int h2n(int[3][3]);

/* h2n distance of misplaced tiles from their goal position
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

int h2n(int board[3][3]){
  int currValue;
  int currPos[2];
  int sum = 0;
  vector<int> heuristicValues;
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      currValue = board[i][j];
      int currPos[2] = {i, j};
      int dist = h2n_distance(currValue, currPos);
      heuristicValues.push_back(dist);
    }
  }

  for(int i = 0; i < heuristicValues.size(); i++){
    sum += heuristicValues[i];
  }
  
  return sum;
}

int h2n_distance(int value, int currPos[2]){ 
  int currX = currPos[0];
  int currY = currPos[1];
  int hX;
  int hY;
  int heuristicValue = 0;
  int goalX = 0;
  int goalY = 0;
  
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
  if(value ==5){
    goalX = 2;
    goalY = 2;
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
  if(value == 0){ //We dont record data for 0, its the empty spot
    currX = 0;
    currY = 0;
    goalX = 0;
    goalY = 0;
  }


  hX = abs(currX - goalX);
  hY = abs(currY - goalY);
  heuristicValue = hX + hY;

  return heuristicValue;
}

#endif