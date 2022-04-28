#include <stdio.h>
#include <locale.h>

void getTelaTexto(char *texto)
{
		printf(" ***************************************************************************************************************************************\n");
		printf("\t\t\t\t\t\t\t   IMOBILIARIA XPTO                                 \n");
		printf("\n                                               \n\n");
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
		printf("                                  %s                   \n",texto);
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n\n");
}
void getMenulogin()
{
	getTelaTexto("\t\t AJUDA - LOGIN");
}
