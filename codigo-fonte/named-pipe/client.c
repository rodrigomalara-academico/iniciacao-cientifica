#include "pipe.h"
#include <string.h>

void main( void )
{
PIPE *pipe;
char *teste;

pipe = open_pipe( "pipe.pp", 'i' );

teste = receive_message( pipe );
if ( strcmp( teste, "T" ) != 0 )
	printf( "erro !!!!!\n");
printf(teste);

close_pipe( pipe );
}
