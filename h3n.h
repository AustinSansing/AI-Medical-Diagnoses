#ifndef H3N_H
#define H3N_H

#include <iostream>
#include "Sn.h"

using namespace std;

int h3n(int board[3][3], int h4nVal){
  int SnVal = Sn(board);
  int h3nVal = (2*h4nVal) + SnVal;
  return h3nVal;
}

#endif