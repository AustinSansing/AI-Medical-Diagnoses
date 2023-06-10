#ifndef HN_H
#define HN_H

#include <iostream>
#include "Sn.h"

using namespace std;


int Hn(int board[3][3], int h2nVal){
  int SnVal = Sn(board);
  int HnVal = h2nVal + (3*SnVal);
  return HnVal;
}

#endif