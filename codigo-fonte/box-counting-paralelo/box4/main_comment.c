/* Calculum of Fractal Dimension using the Box Counting method
   Rodrigo Daniel Malara - 14239-5 - Computer Engineering - UFSCar 
   Prof.Dr. Marcos Luiz Mucheroni */

#include <stdio.h>
#include <chan.h>
#include <math.h>

#include "inter.h"	// The file that contains the procedures to comunicate
			// with the C communication task through "pipes"

#include "matrix.h"	// Allows to treat the pointer as a matrix



#define bool int

#define TRUE 1
#define FALSE 0
#define WHITE 255
#define BLACK 0

#define NPROCS 4

#define GRIDSIZE 64
#define L 128
#define TVETOR 64
#define XDIM 16
#define YDIM 16

typedef struct {
   int matriz[GRIDSIZE][GRIDSIZE]
} DATA;


/* #include "cnts.h"     	Constats needed to the calculus */


int *imagem;		// The pointer to the image received from IDL


main( int argc, char *argv[], char *envp[], CHAN *in_ports[], int ins, CHAN *out_ports[], int outs )
{

   bool Erro;
   int R0, R1, R2, R3;	// The variables that holds the results of counting
   int i, j;

   DATA P0, P1, P2, P3		// The structures that are to be sent
 				// to the processors

   double DimFrac, Total;	// The variables that holds the final 
				// result itself

   int *aux;		// An auxiliary pointer to the image


   /* Takes the image from the "pipe" */

   imagem = interface( &Erro );


   if (Err == TRUE)
   {
	printf("\nThe value can't be received\n");
	return;
   } 



   /* Dividing and sending the image through the channels  */

   for ( i = 0; i < L; i++ )
   {
	for ( j = 0; j < L; j++ )
	{
		if ( ( i < L / 2 ) && ( j < L / 2 ) )
			P0.matriz[i][j] = m( i,j );

		if ( ( i < L / 2 ) && ( j >= L / 2 ) )
			P1.matriz[i][j-L / 2] = m( i,j );

		if ( ( i >= L / 2 ) && ( j < L / 2 ) )
			P2.matriz[i-L / 2][j] = m( i,j );

		if ( ( i >= L / 2 ) && ( j >= L / 2 ) )
			P3.matriz[i-L / 2][j - L / 2] = m( i,j );
	}
   }


   chan_out_message ( sizeof( DATA ), P0, out_ports[0] );
   chan_out_message ( sizeof( DATA ), P1, out_ports[1] );
   chan_out_message ( sizeof( DATA ), P2, out_ports[2] );
   chan_out_message ( sizeof( DATA ), P3, out_ports[3] ); 





   /* Image Processing */



   // Receiving the results


   chan_in_message ( sizeof( int ), &R0, in_ports[0] );
   chan_in_message ( sizeof( int ), &R1, in_ports[1] );
   chan_in_message ( sizeof( int ), &R2, in_ports[2] );
   chan_in_message ( sizeof( int ), &R3, in_ports[3] );


   // Calculating the Fractal Dimension
   

   Total = R0 + R1 + R2 + R3;
   DimFrac = log( Total ) / log( 1 / sqrt ( GRIDSIZE ) );

   printf("R0: %i\t R1: %i\t R2: %i\t R3: %i\n", R0, R1, R2, R3);
   printf("Numero de box com um pixel branco = %f\n", Total);

   printf("Dimensao fractal = %f\n", DimFrac);



}  
