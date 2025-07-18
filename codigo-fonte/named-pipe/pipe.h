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
	pipe = fopen( name, "wb" );
else
	pipe = fopen( name, "rb" );
return pipe;
}


void close_pipe( PIPE *name )
{
	fclose ( name );
}


void send_message( char *message, PIPE *pipe )
{
	char *xmessage;
	int size = 8;

	xmessage = message;
	fwrite( &size, sizeof( int ), 1, pipe);
	fflush( pipe );

	fwrite( message, sizeof( char ) * size, 1, pipe );
	fflush( pipe );
}

char *receive_message(PIPE *pipe )
{
	char *message, *xmessage;
	int *size;

	fread( size, sizeof( int ), 1, pipe);

	xmessage = ( char * ) malloc( sizeof( char ) * *size);
	message = xmessage;
	fread( message, sizeof( char ) * *size, 1, pipe );

	return message;
}
