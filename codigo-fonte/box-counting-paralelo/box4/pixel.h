bool tempixel( int Top, int Left, int Bott, int Right )
{
	int x,y;
	bool Answ = FALSE;

	for ( x = Left; x < Right; x++ )
	{
		for ( y = Top; y < Bott; y++ )
		{
			if ( Dat.matriz[x][y]  != WHITE )
			{
				Answ = TRUE;
			}
		}
	}
	return Answ;
}
