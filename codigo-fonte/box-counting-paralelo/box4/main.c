#include <stdio.h>
#include <chan.h>
#include <math.h>

#include "cnts.h"

int *imagem;

#include "inter.h"	
#include "matrix.h"	


main( int argc, char *argv[], char *envp[], CHAN *in_ports[], int ins, CHAN *out_ports[], int outs )
{

   bool Erro;
   int R0, R1, R2, R3;	
   int i, j;

   Dados P0, P1, P2, P3;

   double DimFrac, Total;	

   int *aux;	



   imagem = interface( &Erro );


   if (Erro == TRUE)
   {
	printf("\nThe value can't be received\n");
	return;
   } 



 
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


   chan_out_message ( sizeof( Dados ), &P0, out_ports[0] );
   chan_out_message ( sizeof( Dados ), &P1, out_ports[1] );
   chan_out_message ( sizeof( Dados ), &P2, out_ports[2] );
   chan_out_message ( sizeof( Dados ), &P3, out_ports[3] ); 





 

   chan_in_message ( sizeof( int ), &R0, in_ports[0] );
   chan_in_message ( sizeof( int ), &R1, in_ports[1] );
   chan_in_message ( sizeof( int ), &R2, in_ports[2] );
   chan_in_message ( sizeof( int ), &R3, in_ports[3] );


    

   Total = R0 + R1 + R2 + R3;
   DimFrac = log( Total ) / log( 1 / sqrt ( GRIDSIZE ) );

   printf("R0: %i\t R1: %i\t R2: %i\t R3: %i\n", R0, R1, R2, R3);
   printf("Numero de box com um pixel branco = %f\n", Total);

   printf("Dimensao fractal = %f\n", DimFrac);



}  
