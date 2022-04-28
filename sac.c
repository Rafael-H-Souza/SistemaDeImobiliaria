#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <locale.h>
#include "MostraImoveis.c"

typedef struct
{
	int mes;
	float valorFinanciado;
	float taxa;
	float sacAmortiz;
	float valorEntrada;
	float valorJuros ;
	float amortizacao;
	float saldoDevedor;
	float parcela;
	
}SAC;


SAC getsac() 
{
    SAC sac;
	Imovel imoveis;
   	int i;
   	getTelaTexto("\t\t\t    TABELA SAC");
   	
   	if(strcmp(statusOperador,"Consulta")==0&& strcmp(statusTipo,"VENDA")==0)
	{
		sac.valorFinanciado = imovelPreco;
	   	
	   	printf("\tEntre com os valores do financiamento\n");
	 	printf("\tValor financiado R$ %.2f", sac.valorFinanciado);
		printf("\tValor da entrada R$ "); 
		scanf("%f", &sac.valorEntrada);
		printf("\tQuantidade de parcelas: "); 
		scanf("%i", &sac.mes);
		sac.taxa = 0.65;
		printf("\tTaxa de juros em %.2f", sac.taxa);
	}
	else
	{
		
	   	printf("\tEntre com os valores do financiamento\n");
	 	printf("\tValor financiado R$ "); 
		scanf("%f", &sac.valorFinanciado);
		printf("\tValor da entrada R$ "); 
		scanf("%f", &sac.valorEntrada);
		printf("\tQuantidade de parcelas: "); 
		scanf("%i", &sac.mes);
		printf("\tTaxa de juros em %% "); 
		scanf("%f", &sac.taxa);
	}
 	
 	sac.valorJuros = 0, sac.amortizacao = 0, sac.saldoDevedor = sac.valorFinanciado - sac.valorEntrada;
 	sac.valorFinanciado = sac.valorFinanciado - sac.valorEntrada;
 	
	sac.parcela = 1;
	
 	printf("\n\n\tSaldo Devedor R$ %.2f \n\n", sac.saldoDevedor); 
	for (i = 1; i <= sac.mes; i++) 
	{
		
		sac.valorJuros = sac.saldoDevedor * sac.taxa / 100;
		sac.sacAmortiz = sac.valorFinanciado / sac.mes;
 	
	 	if (sac.sacAmortiz>sac.saldoDevedor)
 			sac.sacAmortiz=sac.saldoDevedor;
 			
		sac.parcela =  sac.valorJuros + sac.sacAmortiz; 
		sac.saldoDevedor -= sac.sacAmortiz ;
		printf("\n\tParcela %i\t|Prestação R$ %.2f\t\t|Juros R$ %.2f \t|Amortização R$ %.2f \t|Saldo Devedor R$ %.2f\n", i, sac.parcela, sac.valorJuros, sac.sacAmortiz, sac.saldoDevedor);
    }
	getEnter();
}
