#ifndef SN_H
#define SN_H

#include <iostream>

using namespace std;

bool propperSuccessor(int, int[2], int[3][3]);
int getPropperSuccessor(int);
int getCurrSuccessor(int, int, int[3][3]);

//Objective is to get propper Successors
//Need to keep track of position in order to look in the proper direction

/*
top left corner: Needs to look right to (0, 1)
top middle needs to look right to (0, 2)
top right corner needs to look down: (1, 2)

middle left needs to look up (0, 0)
middle right needs to look down (2, 2)

bottom left corner needs to look up (1, 0)
bottom middle needs to look left (2, 0)
bottom right corner needs to look left (2, 1)
*/

int Sn(int board[3][3]){
  int currValue;
  int currPos[2];
  int sum = 0;
  
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      currValue = board[i][j];
      int currPos[2] = {i, j};
      if(currValue != board[1][1]) //don't count middle of board yet
        if(!propperSuccessor(currValue, currPos, board)) //add 2 for every value not with its propper successor
          sum += 2;
    }
  }
  if(board[1][1] != 0) //add 1 if center value is not blank
    sum += 1;

  return sum;
  
}

bool propperSuccessor(int currValue, int currPos[2], int board[3][3]){
  int currX = currPos[0];
  int currY = currPos[1];
  int propperSuccessor = getPropperSuccessor(currValue);
  int currSuccessor;
  
  if(currValue != 0){
    currSuccessor = getCurrSuccessor(currX, currY, board);
      if(currSuccessor != propperSuccessor){
        //cout<<"val: "<<currValue<<"had impropper successor: "<<currSuccessor<<endl;
        return false;
      }
      else  
        return true; 
  }
  else    
    return true;//dont count 0
}

int getCurrSuccessor(int currX, int currY, int board[3][3]){
  int currSuccessor;
  
  //top left
  if(currX == 0 && currY == 0)
    currSuccessor = board[0][1];
  //top middle
  if(currX == 0 && currY == 1)
    currSuccessor = board[0][2];
  //top right
  if(currX == 0 && currY == 2)
    currSuccessor = board[1][2];
  //middle left
  if(currX == 1 && currY == 0)
    currSuccessor = board[0][0];
  //miiddle right
  if(currX == 1 && currY == 2)
    currSuccessor = board[2][2];
  //bottom left
  if(currX == 2 && currY == 0)
    currSuccessor = board[1][0];
  //bottom middle
  if(currX == 2 && currY == 1)
    currSuccessor = board[2][0];
  //bottom right
  if(currX == 2 && currY == 2)
    currSuccessor = board[2][1];
  return currSuccessor;
}

int getPropperSuccessor(int value){
  int successor;
  if(value != 8 || value != 0){
    successor = value += 1; //in general successor is i + 1
  }
  else if(value == 8){ //8 at end of loop, so successor is 1
    successor = 1;
  }
  else{
    successor = 0; //We'll handle this later
  }

  return successor;
    
}

#endif