#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Proprietario.c"

void getDeleteRegistro()
{
	char delete[80];
	
	Imovel imoveis;
	char opcao[3];
	bool cond = 0;
	char numero[10];
	char preco[15];
	int indice = 0;
	FILE* arq;	
	FILE* excluir = fopen("Excluir.txt","a+");	
	FILE* aux = fopen("Auxiliar.txt","w"); 
	
	printf("\n\tDelete dado de imovel\n\n");
	
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
				
		if(strcmp(imoveis.codigoImoveis,imoveis.codigoImo)!=0)
		{
			if (!setArqExiste("Auxiliar.txt"))
			{
  		      printf("\n\nNenhum dado ainda foi cadastrado.\n");
				return;
   			}
   			
			TirarEspacos(imoveis.estado);
	    	TirarEspacos(imoveis.cidade);
			TirarEspacos(imoveis.bairro);
			TirarEspacos(imoveis.rua);
			TirarEspacos(imoveis.descricao);
			
			fprintf(aux,"%s\t",statusIm);
			fprintf(aux,"%s\t",statusTipo);
			fprintf(aux,"%s",seguraTipo);
			fprintf(aux,"%s\n",imoveis.codigoImo);
			fprintf(aux,"%s\t\t",imoveis.estado);
			fprintf(aux,"%s\t\t",imoveis.cidade);
			fprintf(aux,"%s\t\t",imoveis.bairro);
			fprintf(aux,"%s\t\t",imoveis.rua);
			fprintf(aux,"%i\t\t",imoveis.numero); 
			fprintf(aux,"%.2f\n",imoveis.reais);
			
			if(strcmp(statusIm,"APARTAMENTO")==0||strcmp(statusIm,"GALPÃO")==0)
			{
				//printf("Condominio R$: ");
				fprintf(aux,"%.2f\n",imoveis.condominio);
			}
		
			if(strcmp(statusIm,"CASA")==0 ||strcmp(statusIm,"APARTAMENTO")==0)	
			{				
				
				fprintf(aux,"%i\t",imoveis.dormitorios);
				fprintf(aux,"%i\t",imoveis.banheiro);
				fprintf(aux,"%i\t",imoveis.areaDeServico);
				fprintf(aux,"%i\t",imoveis.sala);
				fprintf(aux,"%i\t",imoveis.garagens);
				
				if(strcmp(statusIm,"APARTAMENTO")==0)
				{								
			//			printf("Numero do andar: ");	
			//			printf("Numeros de elevador: ");
					
					fprintf(aux,"%i\t",imoveis.andar);
					fprintf(aux,"%i\t",imoveis.elevador);
								
				}
			}
			if(strcmp(statusTipo,"ALUGAR")==0)
			{
				//printf("Contrato de aluguel para quantos anos: ");	
				fprintf(aux,"%i\t\t",imoveis.ano);
			}
		
			fprintf(aux,"\n%s",imoveis.descricao);
			fprintf(aux,"\n\n");
		}
		else
		{
			system("cls");
			getTelaTexto("\t\t\tImovel excluido");
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
			
		
			TirarEspacos(imoveis.estado);
	    	TirarEspacos(imoveis.cidade);
			TirarEspacos(imoveis.bairro);
			TirarEspacos(imoveis.rua);
			TirarEspacos(imoveis.descricao);
			
			fprintf(excluir,"%s\t",statusIm);
			fprintf(excluir,"%s\t",statusTipo);
			fprintf(excluir,"%s",seguraTipo);
			fprintf(excluir,"%s\n",imoveis.codigoImo);
			fprintf(excluir,"%s\t\t",imoveis.estado);
			fprintf(excluir,"%s\t\t",imoveis.cidade);
			fprintf(excluir,"%s\t\t",imoveis.bairro);
			fprintf(excluir,"%s\t\t",imoveis.rua);
			fprintf(excluir,"%i\t\t",imoveis.numero);
			fprintf(excluir,"%.2f\n",imoveis.reais);
			
			if(strcmp(statusIm,"APARTAMENTO")==0||strcmp(statusIm,"GALPÃO")==0)
			{
				//printf("Condominio R$: ");
				fprintf(excluir,"%.2f\n",imoveis.condominio);
			}
		
			if(strcmp(statusIm,"CASA")==0 ||strcmp(statusIm,"APARTAMENTO")==0)	
			{				
				
				fprintf(excluir,"%i\t",imoveis.dormitorios);
				fprintf(excluir,"%i\t",imoveis.banheiro);
				fprintf(excluir,"%i\t",imoveis.areaDeServico);
				fprintf(excluir,"%i\t",imoveis.sala);
				fprintf(excluir,"%i\t",imoveis.garagens);
				
				if(strcmp(statusIm,"APARTAMENTO")==0)
				{								
			//			printf("Numero do andar: ");	
			//			printf("Numeros de elevador: ");
					
					fprintf(excluir,"%i\t",imoveis.andar);
					fprintf(excluir,"%i\t",imoveis.elevador);
				}
			}
			if(strcmp(statusTipo,"ALUGAR")==0)
			{
				//printf("Contrato de aluguel para quantos anos: ");	
				fprintf(excluir,"%i\t\t",imoveis.ano);
			}
		
			fprintf(excluir,"\n%s",imoveis.descricao);
			fprintf(excluir,"\n\n");
			
				
		}
	}
	fclose(arq); 
	fclose(excluir); 
	fclose(aux); 


	if(strcmp(statusIm,"CASA")==0)
	{
		if(strcmp(statusTipo,"VENDA")==0)
		{
			system("del VenderCasas.txt");
			system("rename Auxiliar.txt VenderCasas.txt");
			
		}			
		else if(strcmp(statusTipo,"ALUGAR")==0)
		{
			system("del AlugarCasas.txt");
			system("rename Auxiliar.txt AlugarCasas.txt");
		}
	}
	else if(strcmp(statusIm,"APARTAMENTO")==0)
	{
		if(strcmp(statusTipo,"VENDA")==0)
		{
			system("del VenderApartamentos.txt");
			system("rename Auxiliar.txt VenderApartamentos.txt");
			
		}			
		else if(strcmp(statusTipo,"ALUGAR")==0)
		{
			system("del AlugarApartamentos.txt");
			system("rename Auxiliar.txt AlugarApartamentos.txt");
			
		}
	}
	
	else if(strcmp(statusIm,"TERRENO")==0)
	{
		if(strcmp(statusTipo,"VENDA")==0)
		{
			system("del VenderTerrenos.txt");
			system("rename Auxiliar.txt VenderTerrenos.txt");
			
		}			
		else if(strcmp(statusTipo,"ALUGAR")==0)
		{
			system("del AlugarTerrenos.txt");
			system("rename Auxiliar.txt AlugarTerrenos.txt");
		
		}
	}
	else if(strcmp(statusIm,"GALPÃO")==0)
	{
		if(strcmp(statusTipo,"VENDA")==0)
		{
			system("del VenderGalpoes.txt");
			system("rename Auxiliar.txt VenderGalpoes.txt");
			
		}			
		else if(strcmp(statusTipo,"ALUGAR")==0)
		{
			system("del AlugarGalpoes.txt");
			system("rename Auxiliar.txt AlugarGalpoes.txt");
		
		}
	}
}



	


