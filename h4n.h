#ifndef H4N_H
#define H4N_H

#include <iostream>
#include "Sn.h"

using namespace std;

/*Our heuristic, h4n is the sum of the numbr of tiles out of row, + the number of tiles out of column
Propper placements:
1: r0, c0
2: r0, c1
3: r0, c2
4: r1, c2
5: r2, c2
6: r2, c1
7: r2, c0
8: r1, c0
*/

bool outOfRow(int val, int row){
  int propperRow;
  if(val == 1 || val == 2 || val == 3)
    propperRow = 0;
  else if(val == 4 || val == 8)
    propperRow = 1;
  else
    propperRow = 2;

  if(row != propperRow)
    return true;
 
  return false;
}

bool outOfCol(int val, int col){
  int propperCol;
  if(val == 1 || val == 7 || val == 8)
    propperCol = 0;
  else if(val == 2 || val == 6)
    propperCol = 1;
  else
    propperCol = 2;

  if(col != propperCol)
    return true;

  return false;
}

int h4n(int board[3][3]){
  int sum = 0;
  int val;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      val = board[i][j];
      if(val != 0){
        if(outOfRow(val, i))
          sum += 1;
        if(outOfCol(val, j))
          sum += 1;
      }
    }
  }

  return sum;
}


#endif