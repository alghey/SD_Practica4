/*
 * Este programa es el servidor para poder tener una conexión con el cliente y muestra los resultados que se obtienes de las variables tipo int 
 que el clinte ingresa por la consola. Mantiene la conexión abierta.
 */

#include "suma.h"

int *
suma_1_svc(dupla_int *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("Server is working\n");
	printf("Parameters: %d, %d\n",argp->a,argp->b);
	result = argp->a + argp->b;
	return &result;

}
