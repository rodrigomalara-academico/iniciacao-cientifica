#define bool int

#define TRUE 1
#define FALSE 0
#define L 128
#define WHITE 255
#define BLACK 0
#define GRIDSIZE 128


int *imagem;

int GRADE = GRIDSIZE / 4;
int XImag = L, YImag = L;

#include <stdio.h>
#include "child.c"
#include "inter.h"

void main( void )
{
   bool Err;
   int R0, R1, R2, R3,i;
   float DimFrac, Total;

   int *aux;

   /* Busca valor no pipe */

   imagem = interface( &Err );
   if (Err == TRUE)
   {
	printf("O valor nao conseguiu ser recebido");
	return;
   } 

   aux = imagem;
	for (i = 0; i < L * L; i++)
		printf("imagem[%i]: %i\n", i, *(aux++));


   /* Processamento da imagem */

   /* Cobegin */
	R0 = CountBox( 0, 0, YImag / 2, XImag / 2 );
	R1 = CountBox( 0, XImag / 2, YImag / 2, XImag );
	R2 = CountBox( YImag / 2, 0, YImag, XImag / 2 );
	R3 = CountBox( YImag / 2, XImag / 2, YImag, XImag );
   /* Coend */

   /* Inicia os calculos */

   Total = R0 + R1 + R2 + R3;
   printf("R0: %i\t R1: %i\t R2: %i\t R3: %i\n", R0, R1, R2, R3);
   printf("Numero de box com um pixel branco = %f\n", Total);
}  
