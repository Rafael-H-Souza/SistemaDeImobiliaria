#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Perfil.c"

Imovel getProprietario()
{
	Imovel imoveis;
	Usuario usuario;
	FILE *arq;	
	arq = fopen("Proprietario.txt","a+");
	if(strcmp(statusUser,"Cliente")==0)
	{
		fprintf(arq,"\n%s\t",statusIm);
		fprintf(arq,"%s\t",statusTipo);
		fprintf(arq,"%s\t",usuario.seguranca);
		fprintf(arq,"%s%i",seguraTipo,imoveis.codImoveis);
	}
	
	fclose(arq);
	printf("\n");
}
