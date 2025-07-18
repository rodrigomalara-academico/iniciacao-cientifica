#include "pipe.h"
#include <stdio.h>

/* O envio de dados deve ser feito da seguinte forma:

1 - o processo deve receber um flag dizendo que o processo 
servidor esta enviando. Este sinal e T
2 - o processo recebe o ponteiro.
3 - o processo recebe outro flag dizendo que a mensagem acabou.
Este sinal e T  */

int *interface( bool *err )
{
	PIPE *pipe;
	char *message;
	int i, valor, size = L * L;
	int *img, *grd;

	*err = FALSE;

	pipe = open_pipe( "pipe.pp", 'i' );

	img = ( int * ) calloc( size, sizeof( int ));

	grd = img;	

	for (i = 0; i < size; i++)
	{
	   message = receive_message( pipe );
	   printf("%s\n", message);
	   valor = atoi(message);
	   printf("%i\t", valor);
	   *(img++) = valor;	
	}

	close_pipe( pipe );

	img = grd;

/*	for (i = 0; i < size; i++)
		printf("img[%i]: %i  -  imag[%i]: %i\n", i, *(img++), i, imag[i]);
*/
	return img;
}
