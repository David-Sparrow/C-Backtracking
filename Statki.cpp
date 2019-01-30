#include "PathFinder.h"

#define DEBUG

#define ROW 10
#define COL 10
#define DEPTH_MIN 7

int SetTab( char* sFile, int **pTab, int nRow, int nCol )
{
	FILE* fin = NULL;
	if ((fin = fopen( sFile, "r" )) == NULL)
	{
		printf( "\nSetTab: Error open file!!\n" );
		return 0;
	}
	for (int i = 0; i < nRow; i++)
	{
		int* v = *pTab++;
		for (int j = 0; j < nCol; j++)
		{
			fscanf( fin, "%d", v++ );
		}
	}
	fclose( fin );
	return 1;
}
//-------------------
#ifdef DEBUG
void PrintTab( int **pTab, int nRow, int nCol )
{
	for (int i = 0; i < nRow; i++)
	{
		int *v = *pTab++;
		for (int j = 0; j < nCol; j++)
		{
			printf( "%d\t", *v++ );
		}
		printf( "\n" );
	}
}
#endif // DEBUG
//-------------------
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf( "\nUsage: <script name> <file name>\n" );
		return -1;
	}
	int** tabSea = NULL;
	int** tabVisit = NULL;

	if (!CreateMatrix( &tabSea, ROW, COL ))
	{
		printf( "\nERROR: CreateMatrix\n" );
		return -1;
	}
	if (!CreateMatrix( &tabVisit, ROW, COL ))
	{
		printf( "\nERROR: CreateMatrix\n" );
		return -1;
	}
	if (!SetTab( argv[1], tabSea, ROW, COL ))
	{
		return -1;
	}
#ifdef DEBUG
	PrintTab( tabSea, ROW, COL );
#endif // DEBUG
	if (root( tabSea, ROW, COL, DEPTH_MIN, 0, 0, tabVisit, ROW - 1, COL - 1 ))
	{
		printf( "\nDoplynieto do portu!\n" );
#ifdef DEBUG
		PrintTab( tabVisit, ROW, COL );
#endif // DEBUG
	}
	else
	{
		printf( "\nBrak odpowiedniej sciezki!\n" );
	}

	DeleteMatrix( &tabSea, ROW );
	DeleteMatrix( &tabVisit, ROW );
	return 0;
}