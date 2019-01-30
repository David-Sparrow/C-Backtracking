#include "PathFinder.h"

int CreateMatrix( int *** pTab, int nRow, int nCol )
{
	int ** p = *pTab = (int **)malloc( nRow * sizeof( int* ) );
	if (!p)
	{
		perror( "ERROR: CreateMatrix!" );
		return 0;
	}
	memset( p, 0, nRow * sizeof( int* ) );

	for (int i = 0; i < nRow; i++)
	{
		*p = (int *)malloc( nCol * sizeof( int ) );
		if (!*p)
		{
			perror( "ERROR: CreateMatrix!" );
			return 0;
		}
		memset( *p++, 0, nCol * sizeof( int ) );
	}
	return 1;
}
//-------------------
void DeleteMatrix( int *** pTab, int nRow )
{
	int ** v = *pTab;
	for (int i = 0; i < nRow; i++)
	{
		free( *v++ );
	}
	free( *pTab );
	*pTab = NULL;
}
//-------------------
int move( int** pTab, int nRow, int nCol, int nDepth, int move_nr, int x, int y, int* px, int* py, int** pRoot )
{
	switch (move_nr)
	{
	case UP: *px = --x;
		*py = y;
		break;
	case LEFT: *px = x;
		*py = --y;
		break;
	case DOWN: *px = ++x;
		*py = y;
		break;
	case RIGHT: *px = x;
		*py = ++y;
		break;
	}

	if (*px >= 0 && *py >= 0 && *px < nRow && *py < nCol)
	{
		if (pTab[*px][*py] > nDepth && pRoot[*px][*py] == 0) return 1;
		return 0;
	}
	return 0;

}
//-------------------
int root( int** pTab, int nRow, int nCol, int nDepth, int x, int y, int** pRoot, int x_dest, int y_dest ) 
{
	pRoot[x][y] = 1;

	if (x == x_dest && y == y_dest)
	{
		printf( "(%d,%d) <-  ", y, x );
		return 1;
	}

	int nx = x;
	int ny = y;

	for (int i = UP; i <= LEFT; i++)
	{
		if (move( pTab, nRow, nCol, nDepth, i, x, y, &nx, &ny, pRoot ))
		{
			if (root( pTab, nRow, nCol, nDepth, nx, ny, pRoot, x_dest, y_dest ))
			{
				printf( "(%d,%d) <-  ", y, x );
				return 1;
			}
		}
	}
	pRoot[x][y] = -1;
	return 0;
}
//-------------------