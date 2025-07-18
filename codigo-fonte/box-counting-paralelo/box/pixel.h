bool tempixel( int Top, int Left, int Bott, int Right )
{
	int x,y;
	bool Answ = FALSE;

	for ( x = Left; x < Right; x++ )
	{
		for ( y = Top; y < Bott; y++ )
		{
			if ( m( x,y ) != WHITE )
			{
				Answ = TRUE;
			}
		}
	}
	return Answ;
}
