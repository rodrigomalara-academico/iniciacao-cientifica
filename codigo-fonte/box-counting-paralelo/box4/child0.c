#include <chan.h>
#include "cnts.h"

Dados Dat;

#include "pixel.h"

main ( int argc, char *argv[], char *envp[], CHAN *in_ports[], int ins, CHAN *out_ports[], int outs )
{
	int x, y, Total = 0;


	chan_in_message( sizeof( Dados ), &Dat, in_ports[0] );

	for ( y = 0; y < TVETOR; y += YDIM )
	{
		for ( x = 0; x < TVETOR; x += XDIM )
		{
			if ( tempixel ( y, x, y + YDIM, x + XDIM ) == TRUE )
			{
				Total++;
			}
		}
	}


	chan_out_message( sizeof( int ), &Total, out_ports[0] );

}
