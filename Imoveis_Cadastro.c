#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "DeleteImoveis.c"

// CADASTRO DE TODOS O TIPOS DE IMOVEIS 
Imovel getCadastroImovel()
{
	Imovel imoveis;
	char opcao;
	
	printf("Status: %s\n",statusIm);
	printf("Tipo: %s\n",statusTipo);
	
	getchar();
	printf("Estado: ");
	gets(imoveis.estado);
	printf("Cidade: ");
	gets(imoveis.cidade);	
	printf("Bairro: ");	
	gets(imoveis.bairro);
	printf("Rua: ");	
	gets(imoveis.rua);
	printf("Numero: ");
	scanf("%i",&imoveis.numero);
	
	if(strcmp(statusTipo,"ALUGAR")==0)
	{
		printf("Valor Aluguel R$: ");
		scanf("%f",&imoveis.reais);	
	}
	else if(strcmp(statusTipo,"VENDA")==0)
	{
		
		printf("Valor da Venda R$: ");
		scanf("%f",&imoveis.reais);
		//setValorReal(imoveis.reais);
	}
	
	if(strcmp(statusIm,"APARTAMENTO")==0||strcmp(statusIm,"GALPÃO")==0)
	{
		printf("Condominio R$: ");
		scanf("%f",&imoveis.condominio);
	}
	
	if(strcmp(statusIm,"CASA")==0 ||strcmp(statusIm,"APARTAMENTO")==0)
	{
    	// Informação de Status de Imoveis
		printf("\nDescrição do Imovel\n");	
		printf("\nInforme a quantidade referente ao Imovel\n");	
		printf("Dormitorios: ");
		scanf("%i",&imoveis.dormitorios);
		printf("Sala: ");
		scanf("%i",&imoveis.sala);
		printf("Banheiros: ");
		scanf("%i",&imoveis.banheiro);
		printf("Area de Serviços: ");
		scanf("%i",&imoveis.areaDeServico);
		printf("Garagens & Vagas: ");
		scanf("%i",&imoveis.garagens);
	}
	
	if(strcmp(statusIm,"APARTAMENTO")==0)
	{								
		printf("Numero do andar: ");
		scanf("%i",&imoveis.andar);	
		printf("Numeros de elevador: ");
		scanf("%i",&imoveis.elevador); 			
	}
	if(strcmp(statusTipo,"ALUGAR")==0)
	{
		printf("Contrato de aluguel para quantos anos: ");	
		scanf("%i",&imoveis.ano);
	}
	getchar();
	printf("Deseja incluir descrição do imovel(S/N): ");	
	scanf("%c",&opcao);
	
	if(opcao== 's' || opcao== 'S' )
	{
		getchar();
		printf("Descrição: ");
		gets(imoveis.descricao);
	}
	return imoveis;
}
Imovel getcodigoDeSegurImovel()
{
	Imovel imoveis;
	imoveis=getCadastroImovel();
	srand(time(NULL) );
    imoveis.codImoveis = rand();
    printf("Codigo de seguraça: %d\n", imoveis.codImoveis);
    getEnter();
    return imoveis;
       
}
// SALVAR TODOS OS TIPOS DE IMOVEIS
salvarImoveis()
{
	Imovel imoveis;
	imoveis = getcodigoDeSegurImovel();
		
	FILE * arq;
		if(strcmp(statusIm,"CASA")==0)
		{
			if(strcmp(statusTipo,"VENDA")==0){
				
				strcpy(seguraTipo,"CAV");
				arq = fopen("VenderCasas.txt","a+");
				
			}else if(strcmp(statusTipo,"ALUGAR")==0){
				strcpy(seguraTipo,"CAA");
				arq = fopen("AlugarCasas.txt","a+");
			}
		}
		else if(strcmp(statusIm,"APARTAMENTO")==0)
		{
			if(strcmp(statusTipo,"VENDA")==0){
				strcpy(seguraTipo,"APV");
				arq = fopen("VenderApartamentos.txt","a+");
				
			}else if(strcmp(statusTipo,"ALUGAR")==0){
			
				strcpy(seguraTipo,"APA");
				arq = fopen("AlugarApartamentos.txt","a+");
			}
		}
		else if(strcmp(statusIm,"TERRENO")==0)
		{
			if(strcmp(statusTipo,"VENDA")==0){
				strcpy(seguraTipo,"TEV");
				arq = fopen("VenderTerrenos.txt","a+");
				
			}else if(strcmp(statusTipo,"ALUGAR")==0){
				strcpy(seguraTipo,"TEA");
				arq = fopen("AlugarTerrenos.txt","a+");
			}
		}
		else if(strcmp(statusIm,"GALPÃO")==0)
		{
			
			if(strcmp(statusTipo,"VENDA")==0){
				strcpy(seguraTipo,"GAA");
				arq = fopen("VenderGalpoes.txt","a+");
			}else if(strcmp(statusTipo,"ALUGAR")==0){
				
				strcpy(seguraTipo,"GAV");
				arq = fopen("AlugarGalpoes.txt","a+");
			}
		}
	    	
    	TirarEspacos(imoveis.estado);
    	TirarEspacos(imoveis.cidade);
		TirarEspacos(imoveis.bairro);
		TirarEspacos(imoveis.rua);
		TirarEspacos(imoveis.descricao);
		
		fprintf(arq,"%s\t",statusIm);
		fprintf(arq,"%s\t",statusTipo);
		fprintf(arq,"%s",seguraTipo);
		fprintf(arq,"%i\n",imoveis.codImoveis);
		fprintf(arq,"%s\t\t",imoveis.estado);
		fprintf(arq,"%s\t\t",imoveis.cidade);
		fprintf(arq,"%s\t\t",imoveis.bairro);
		fprintf(arq,"%s\t\t",imoveis.rua);
		fprintf(arq,"%i\t\t",imoveis.numero);
		fprintf(arq,"%.2f\n",imoveis.reais);
		
		if(strcmp(statusIm,"APARTAMENTO")==0||strcmp(statusIm,"GALPÃO")==0)
		{
			//printf("Condominio R$: ");
			fprintf(arq,"%.2f\n",imoveis.condominio);
		}
	
		if(strcmp(statusIm,"CASA")==0 ||strcmp(statusIm,"APARTAMENTO")==0)	
		{				
			
			fprintf(arq,"%i\t",imoveis.dormitorios);
			fprintf(arq,"%i\t",imoveis.banheiro);
			fprintf(arq,"%i\t",imoveis.areaDeServico);
			fprintf(arq,"%i\t",imoveis.sala);
			fprintf(arq,"%i\t",imoveis.garagens);
			
			if(strcmp(statusIm,"APARTAMENTO")==0)
			{								
		//			printf("Numero do andar: ");	
		//			printf("Numeros de elevador: ");
				
				fprintf(arq,"%i\t",imoveis.andar);
				fprintf(arq,"%i\t",imoveis.elevador);
							
			}
		}
		if(strcmp(statusTipo,"ALUGAR")==0)
		{
			//printf("Contrato de aluguel para quantos anos: ");	
			fprintf(arq,"%i\t\t",imoveis.ano);
		}
		
		fprintf(arq,"\n%s\t",imoveis.descricao);
		fprintf(arq,"\n\n");
		
	fclose(arq);
	printf("\n");
	 getProprietario();
	
}

