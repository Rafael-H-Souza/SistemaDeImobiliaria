#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Usuario_Cadastro.c"


	float imovelPreco;
//DADO PARA IMOVEIS 
typedef struct 
{	
	int numero;
	int codigoImovel;
	int metros;
	int dormitorios;
	int sala;
	int banheiro;
	int areaDeServico;
	int elevador;
	int garagens;
	int andar;
	int ano;
	int codImoveis;
	char codigoImoveis[15];
	float condominio;
	float reais;
	char estado[50];
	char cidade[50];
	char bairro[50];
	char rua[50];
	char codigoImo[10];
	char descricao[500];
	
}Imovel;
//LER ARQUIVO TXT REFERENTE AS ESTATUS DE MOVEIS E SEU TIPO 
Imovel lerImoveis()
{
	Imovel imoveis;
	char numero[10];
	char preco[15];
	int indice = 0;
	FILE* arq;
	system("cls");
	
	if(strcmp(statusIm,"CASA")==0)
	{
		if(strcmp(statusTipo,"VENDA")==0)
			arq = fopen("VenderCasas.txt","r");
		
		else if(strcmp(statusTipo,"ALUGAR")==0)
			arq = fopen("AlugarCasas.txt","r");
		
	}
	else if(strcmp(statusIm,"APARTAMENTO")==0)
	{
		if(strcmp(statusTipo,"VENDA")==0)
			arq = fopen("VenderApartamentos.txt","r");
					
		else if(strcmp(statusTipo,"ALUGAR")==0)
			arq = fopen("AlugarApartamentos.txt","r");
			
	}
	else if(strcmp(statusIm,"TERRENO")==0)
	{
		if(strcmp(statusTipo,"VENDA")==0)
			arq = fopen("VenderTerrenos.txt","r");
			
		else if(strcmp(statusTipo,"ALUGAR")==0)
			arq = fopen("AlugarTerrenos.txt","r");
	}
	else if(strcmp(statusIm,"GALPÃO")==0)
	{
		
		if(strcmp(statusTipo,"VENDA")==0)
			arq = fopen("VenderGalpoes.txt","r");
			
		else if(strcmp(statusTipo,"ALUGAR")==0)
			arq = fopen("AlugarGalpoes.txt","r");
	}
												  
	while(!feof(arq))
	{
				
		fscanf(arq,"%s",statusIm);
		fscanf(arq,"%s",statusTipo);
		fscanf(arq,"%s\n",imoveis.codigoImo);
		fscanf(arq,"%s",imoveis.estado);
		fscanf(arq,"%s",imoveis.cidade);
		fscanf(arq,"%s",imoveis.bairro);
		fscanf(arq,"%s",imoveis.rua);
		fscanf(arq,"%i",&imoveis.numero);
		fscanf(arq,"%f",&imoveis.reais);
		
		ColocarEspacos(imoveis.estado);
		ColocarEspacos(imoveis.cidade);
		ColocarEspacos(imoveis.bairro);
		ColocarEspacos(imoveis.rua);
	
			printf("\n __________________________________________________________________________________________________________________________________________\n");
		printf("\n\tStatus: %s\t",statusIm);
		printf("\tTipo: %s\t",statusTipo);
		printf("\tCodigo: %s\n",imoveis.codigoImo);
		printf("\tEstado: %s\t\t",imoveis.estado);
		printf("\tCidade: %s\n",imoveis.cidade);
		printf("\tBairro: %s\t\n",imoveis.bairro);
		printf("\tRua: %s",imoveis.rua);
		printf("\tNumero: %i\n",imoveis.numero);
		printf("\tPreço R$: %.2f\n",imoveis.reais);
		
		if(strcmp(statusIm,"APARTAMENTO")==0 || strcmp(statusIm,"GALPÃO")==0)
		{
			fscanf(arq,"%f",&imoveis.condominio);
			printf("\tCondominio R$: %.2f",imoveis.condominio);
		}
		if(strcmp(statusIm,"CASA")==0 ||strcmp(statusIm,"APARTAMENTO")==0)	
		{				
			printf("\n\n\tDescrição do Imovel\n");
			fscanf(arq,"%i",&imoveis.dormitorios);
			printf("\tDormitorios: %i\t",imoveis.dormitorios);
			fscanf(arq,"%i",&imoveis.banheiro);
			printf("\tBanheiro: %i\t\n",imoveis.banheiro);
			fscanf(arq,"%i",&imoveis.areaDeServico);
			printf("\tArea de serviços: %i",imoveis.areaDeServico);
			fscanf(arq,"%i",&imoveis.sala);
			printf("\tSala: %i\t",imoveis.sala);
			fscanf(arq,"%i",&imoveis.garagens);
			printf("\tGaragens: %i\t",imoveis.garagens);
			
			if(strcmp(statusIm,"APARTAMENTO")==0)
			{								
				fscanf(arq,"%i",&imoveis.andar);
				printf("\tNumero do andar: %i",imoveis.andar);	
				fscanf(arq,"%i",&imoveis.elevador);
				printf("\tNumeros de elevador: %i",imoveis.elevador);
			}
		}
		
		if(strcmp(statusTipo,"ALUGAR")==0)
		{
			fscanf(arq,"%i",&imoveis.ano);
			printf("\n\tContrato de aluguel para quantos anos: ");	
			printf("%i",imoveis.ano);
		}	
		
		fscanf(arq,"%s",imoveis.descricao);
		ColocarEspacos(imoveis.descricao);
		printf("\n\tDescrição: ");
		setTamTexto(imoveis.descricao,75);
		printf("\n");
			printf("\n __________________________________________________________________________________________________________________________________________\n");
		fscanf(arq,"\n");
		
	}
			
	fclose(arq);	
			
	return imoveis;
}

Imovel getSeleImovel()
{
	char delete[80];
	
	Imovel imoveis;
	char opcao[3];
	bool cond = 0;
	char numero[10];
	char preco[15];
	int indice = 0;
	FILE* arq;	
	
	
	printf("\n\tEscolha o imovel\n\n");
	
	printf("\n\tInforme o codido do imovel: ");
	scanf("%s",imoveis.codigoImoveis);
		
	printf("\n __________________________________________________________________________________________________________________________________________\n");
		
	if(strcmp(statusIm,"CASA")==0)
	{
		if(strcmp(statusTipo,"VENDA")==0)
			arq = fopen("VenderCasas.txt","r");
		
		else if(strcmp(statusTipo,"ALUGAR")==0)
			arq = fopen("AlugarCasas.txt","r");
		
	}
	else if(strcmp(statusIm,"APARTAMENTO")==0)
	{
		if(strcmp(statusTipo,"VENDA")==0)
			arq = fopen("VenderApartamentos.txt","r");
					
		else if(strcmp(statusTipo,"ALUGAR")==0)
			arq = fopen("AlugarApartamentos.txt","r");
			
	}
	else if(strcmp(statusIm,"TERRENO")==0)
	{
		if(strcmp(statusTipo,"VENDA")==0)
			arq = fopen("VenderTerrenos.txt","r");
			
		else if(strcmp(statusTipo,"ALUGAR")==0)
			arq = fopen("AlugarTerrenos.txt","r");
	}
	else if(strcmp(statusIm,"GALPÃO")==0)
	{
		
		if(strcmp(statusTipo,"VENDA")==0)
			arq = fopen("VenderGalpoes.txt","r");
			
		else if(strcmp(statusTipo,"ALUGAR")==0)
			arq = fopen("AlugarGalpoes.txt","r");
	}
	
	while(!feof(arq))
	{
				
		fscanf(arq,"%s",statusIm);
		fscanf(arq,"%s",statusTipo);
		fscanf(arq,"%s\n",imoveis.codigoImo);
		fscanf(arq,"%s",imoveis.estado);
		fscanf(arq,"%s",imoveis.cidade);
		fscanf(arq,"%s",imoveis.bairro);
		fscanf(arq,"%s",imoveis.rua);
		fscanf(arq,"%i",&imoveis.numero);
		fscanf(arq,"%f",&imoveis.reais);
		
		ColocarEspacos(imoveis.estado);
		ColocarEspacos(imoveis.cidade);
		ColocarEspacos(imoveis.bairro);
		ColocarEspacos(imoveis.rua);
			
		if(strcmp(statusIm,"APARTAMENTO")==0 || strcmp(statusIm,"GALPÃO")==0)
		{
			fscanf(arq,"%f",&imoveis.condominio);
			
		}
		if(strcmp(statusIm,"CASA")==0 ||strcmp(statusIm,"APARTAMENTO")==0)	
		{				
			fscanf(arq,"%i",&imoveis.dormitorios);
			fscanf(arq,"%i",&imoveis.banheiro);
			fscanf(arq,"%i",&imoveis.areaDeServico);
			fscanf(arq,"%i",&imoveis.sala);
			fscanf(arq,"%i",&imoveis.garagens);
			
			if(strcmp(statusIm,"APARTAMENTO")==0)
			{								
				fscanf(arq,"%i",&imoveis.andar);
				fscanf(arq,"%i",&imoveis.elevador);
			}
		}
		
		if(strcmp(statusTipo,"ALUGAR")==0)
			fscanf(arq,"%i",&imoveis.ano);
			
		fscanf(arq,"%s",imoveis.descricao);
		ColocarEspacos(imoveis.descricao);
				
		if(strcmp(imoveis.codigoImoveis,imoveis.codigoImo)==0)
		{
			system("cls");
			getTelaTexto("\t\t\t IMOVEL SELECIONADO");
			printf("\n __________________________________________________________________________________________________________________________________________\n");
			printf("\n\tStatus: %s\t",statusIm);
			printf("\tTipo: %s\t",statusTipo);
			printf("\tCodigo: %s\n",imoveis.codigoImo);
			printf("\tEstado: %s\t\t",imoveis.estado);
			printf("\tCidade: %s\n",imoveis.cidade);
			printf("\tBairro: %s\t\n",imoveis.bairro);
			printf("\tRua: %s",imoveis.rua);
			printf("\tNumero: %i\n",imoveis.numero);
			printf("\tPreço R$: %.2f\n",imoveis.reais);
			imovelPreco =imoveis.reais;
			
			if(strcmp(statusIm,"APARTAMENTO")==0 || strcmp(statusIm,"GALPÃO")==0)
				printf("\tCondominio R$: %.2f",imoveis.condominio);
			
			if(strcmp(statusIm,"CASA")==0 ||strcmp(statusIm,"APARTAMENTO")==0)	
			{				
				printf("\n\tDescrição do Imovel\n\n");
				printf("\tDormitorios: %i\t",imoveis.dormitorios);
				printf("\tBanheiro: %i\t\n",imoveis.banheiro);
				printf("\tArea de serviços: %i",imoveis.areaDeServico);
				printf("\tSala: %i\t",imoveis.sala);
				printf("\tGaragens: %i\t",imoveis.garagens);
				
				if(strcmp(statusIm,"APARTAMENTO")==0)
				{								
					printf("\tNumero do andar: %i",imoveis.andar);
					printf("\tNumeros de elevador: %i",imoveis.elevador);
				}
			}
			
			if(strcmp(statusTipo,"ALUGAR")==0)
			{
				printf("\n\tContrato de aluguel para quantos anos: ");	
				printf("%i",imoveis.ano);
			}	
			
			ColocarEspacos(imoveis.descricao);
			printf("\n\tDescrição: ");
			setTamTexto(imoveis.descricao,75);
			printf("\n");
			printf("\n __________________________________________________________________________________________________________________________________________\n");

		}
	}
	getEnter();
	system("cls");
	fclose(arq);
	return imoveis;		
}


