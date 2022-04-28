#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <locale.h>
#include "sac.c"

typedef struct
{
	int mes;
	float PMT;
	float PV; 
	float taxa; 
	float valorEntrada; 
	float valorJuros;
	float amortizacao;
	float saldoDevedor;
    float sac_amortiz;
}PRICE;

PRICE getPrice() 
{
	
	PRICE price;
	Imovel imoveis;
	int i; 
	getTelaTexto("\t\t\t    TABELA PRICE");
	
	if(strcmp(statusOperador,"Consulta")==0&& strcmp(statusTipo,"VENDA")==0)
	{
		price.PV = imovelPreco;
		
	 	printf("\tEntre com os valores do financiamento\n");
	 	printf("\tValor financiado: R$ %.2f", price.PV);
		printf("\tValor da entrada: R$ "); 
		scanf("%f", &price.valorEntrada);
		printf("\tQuantidade de parcelas: "); 
		scanf("%d", &price.mes);
		price.taxa = 0.65;
		printf("\tTaxa de juros em: %.2f", price.taxa);
 	}
 	else
 	{
 			
	 	printf("\tEntre com os valores do financiamento\n");
	 	printf("\tValor financiado: R$ "); 
		scanf("%f", &price.PV);
		printf("\tValor da entrada: R$ "); 
		scanf("%f", &price.valorEntrada);
		printf("\tQuantidade de parcelas: "); 
		scanf("%d", &price.mes);
		printf("\tTaxa de juros em %%: "); 
		scanf("%f", &price.taxa);
	}
 	price.valorJuros = 0, price.amortizacao = 0, price.saldoDevedor = price.PV - price.valorEntrada;
 	price.PV = price.PV - price.valorEntrada;
 	
	price.taxa /= 100; //converter em decimal

 	//calcula os dados do fin. tabela Price
 	price.PMT = price.PV *((price.taxa*pow(1+price.taxa, price.mes))/(pow(1+price.taxa, price.mes)-1));


 
 	printf("\n\n\tSaldo Devedor R$ %.2f | Valor da Parcela R$ %.2f\n\n", price.saldoDevedor, price.PMT);
 
 	for (i = 1; i <= price.mes; i++)
	{
 		price.valorJuros = price.saldoDevedor * price.taxa;
		price.amortizacao = price.PMT - price.valorJuros;
		if (price.amortizacao>price.saldoDevedor)
			price.amortizacao=price.saldoDevedor;
		price.saldoDevedor -= price.amortizacao;
		printf("\n\tParcela %i \t|Prestação R$ %.2f \t|Juros R$ %.2f \t|Amortização R$ %.2f \t|Saldo Devedor R$ %.2f \n", i, price.PMT,  price.valorJuros, price.amortizacao, price.saldoDevedor);
 	}
 		
 	getEnter();
return price;
}


