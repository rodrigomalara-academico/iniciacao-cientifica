#include <stdio.h>
#include <stdlib.h>

#define PIPE FILE

PIPE *open_pipe( char *name, char mode);
void close_pipe( PIPE *name );
void send_message( char *message, PIPE *pipe );
char *receive_message(PIPE *pipe );


PIPE *open_pipe( char *name, char mode )
{
PIPE *pipe;

if ( mode == 'o' )
	pipe = fopen( name, "w" );
else
	pipe = fopen( name, "r" );
return pipe;
}


void close_pipe( PIPE *name )
{
	fclose ( name );
}


void send_message( char *message, PIPE *pipe )
{
	char *xmessage;
	int size = 10;

	xmessage = message;

	fwrite( message, sizeof( char ) * size, 1, pipe );
	fflush( pipe );
}

char *receive_message(PIPE *pipe )
{
	char *message;
	int size = 10;

	message = ( char * ) malloc( sizeof( char ) * size);

	fread( message, sizeof( char ) * size, 1, pipe );

	// sscanf( message, "%d", valor);

	return message;
}
