/*
 * Este es un programa correspondiente al cliente con las funciones necesarias para identificar las variables que se le mandan por consola
 y realizar la operacioón de suma de dos numeros y si no se mandan los parametros correctos para poder realizar esta función, se manda 
 mensaje al cliente "Invalid value" para que sepa que tuvo un error al ingresar los parametros.
 */

#include "suma.h"


void
suma_prog_1(char *host,int a, int b) // las variables del programa son comprensibles, puedo interpretar a lo que se refiere cada una de ellas
{										//se  pueden idenntificar muy bien en el código 
	CLIENT *clnt;
	int  *result_1;
	dupla_int  suma_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, SUMA_PROG, SUMA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	suma_1_arg.a = a;
	suma_1_arg.b = b;
	result_1 = suma_1(&suma_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		printf("Result = %d\n", *result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[]) //Esta es la función main 
{
	char *host;
	int a,b;

	if (argc != 4) {
		printf ("usage: %s server_host num1 num2\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	if((a = atoi(argv[2])) == 0 && *argv[2] != '0'){
		fprintf(stderr, "invalid value: %s\n",argv[2]);
		exit(1);
	}
	if((b = atoi(argv[3])) == 0 && *argv[3] != '0'){
		fprintf(stderr, "invalid value: %s\n",argv[3]); //Errores
		exit(1);
	}
	suma_prog_1 (host,a,b);
exit (0);
}
