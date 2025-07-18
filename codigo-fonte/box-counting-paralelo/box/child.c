#include "matrix.h"
#include "pixel.h"

int CountBox( int Top, int Left, int Bott, int Right )
{
	int XSum = XImag/GRADE, YSum = YImag/GRADE;
	int x, y;
	int Total = 0;

	y = Top;
	while ( y < Bott )
	{ 
		x = Left;
		while ( x < Right )
		{
			if ( tempixel ( y,x, y + YSum, x + XSum ) == TRUE )
			{
				Total++;
			}
			x = x + XSum;
		}
		y = y + YSum;
	}
	return Total;
}
