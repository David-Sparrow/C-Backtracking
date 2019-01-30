#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef enum { UP, RIGHT, DOWN, LEFT } direction;

int CreateMatrix( int *** pTab, int nRow, int nCol );
void DeleteMatrix( int *** pTab, int nRow );
int move( int** pTab, int nRow, int nCol, int nDepth, int move_nr, int x, int y, int* px, int* py, int** pRoot );
int root( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest );
