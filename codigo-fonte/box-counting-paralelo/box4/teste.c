#include <stdio.h>
#include "idl_rpc.h"
#include "pipe.h"

int main()
{
   PIPE     *pipe;
   char     *message;
   CLIENT   *pClient;
   char      cmdBuffer[512],c;
   int       result;
   UCHAR     *imag;
   IDL_VPTR  v;

/*
 * Connect to the server.
 */
   if((pClient = IDL_RPCInit(0, (char*)NULL)) == (CLIENT*)NULL){
      fprintf(stderr, "Can't register with IDL server\n");
      exit(1);
   }
   IDL_RPCExecuteStr(pClient, "A=READ_BMP('/home/ro/boxcnt.bmp')");
   IDL_RPCExecuteStr(pClient, "TV, A");
 
   scanf(&c);
   v=IDL_RPCGetVariable(pClient, "A");
   imag = v->value.arr->data;


   printf(" %i",(int)*imag+4);



   open_pipe( "pipe.pp", 'o');

   message = ( char * ) malloc( sizeof( char ) *20 );

   message = ( char *) &imag;

   /* send_message( "T", pipe); */

   send_message( message, pipe );

   /* send_message( "T", pipe); */

   close_pipe( pipe );


  
/*
 * Now disconnect from the server and kill it.
 */
   if(!IDL_RPCCleanup(pClient, 1))
     fprintf(stderr, "IDL_RPCCleanup: failed\n");
   exit(0);

   

}
