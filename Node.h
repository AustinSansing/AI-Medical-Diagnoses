#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "h1n.h"
#include "h2n.h"
#include "Hn.h"
#include "Sn.h"
#include "h3n.h"
#include "h4n.h"

using namespace std;

class Node{
public:
  int board_state[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  Node* parent = NULL;
  int depth = 0; //g
  int h1Val = 1; // H1 start value
  int h2Val = 1; // H2 start value
  int h3Val = 1; // H3 start value
  int h4Val = 1; // H4 start value
  int HnVal = 1; // Hn start value
  int SnVal = 1; // Sn start value
  //Heuristics
  int hVal = 1; //Current heuristic we're using 
  int f = hVal + depth;
  int possibleMoves;
  vector<Node*> successors = {};
};


void populate_board(Node *A, int board[3][3]){ // Print board function to show progress
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      A->board_state[i][j] = board[i][j];
    }
  } 
}

void setHeuristic(Node* board, int choice){ // Heuristic choice's based on use user input
  switch(choice) {
    case 1: //h1n
      board->hVal = h1n(board->board_state);
      break;

    case 2: //h2n
      board->hVal = h2n(board->board_state);
      break;

    case 3: //Hn
      board->hVal = Hn(board->board_state, board->h2Val);
      break;

    case 4: //Sn
      board->hVal = Sn(board->board_state);
      break;

    case 5: //h3n
      board->h4Val = h4n(board->board_state);
      board->hVal = h3n(board->board_state, board->h4Val);
      break;

    case 6: //h4n
      board->hVal = h4n(board->board_state);
      break;
  }
}

string getHeuristic(int h){
  if(h == 1)
    return "h1n";
  if(h == 2)
    return "h2n";
  if(h == 3)
    return "Hn";
  if(h == 4)
    return "Sn";
  if(h == 5)
    return "h3n";
  if(h == 6)
    return "h4n";
}

string getHeuristicString(int h){ // This is used to explain the output more efficiently
  if(h == 1)
    return "Number of Missplaced Tiles";
  if(h == 2)
    return "Sum of Tile Distances From Their Goal State";
  if(h == 3)
    return "Sum of Tile Distances From Their Goal State + 3(Sequence Score from tiles away from their propper successor)";
  if(h == 4)
    return "Sequence Score from tiles away from their propper successor";
  if(h == 5)
    return "2(Sum generated from the number of tiles out of row + out of column) + Sequence Score from tiles away from their propper successor";
  if(h == 6)
    return "Sum generated from the number of tiles out of row + out of column";
}

#endif