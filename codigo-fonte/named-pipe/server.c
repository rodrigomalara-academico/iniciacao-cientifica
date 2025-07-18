#include "pipe.h"
#include <string.h>

void main( void )
{
PIPE *pipe;
char *teste;

teste = ( char * ) malloc( sizeof( char ) *20 );

printf("%c%c%c%c%c%c%c%c", teste[0], teste[1], teste[2], teste[3], teste[4], teste[5], teste[6], teste[7]);


pipe = open_pipe( "pipe.pp", 'o');


send_message( teste, pipe );

close_pipe( pipe );
}
