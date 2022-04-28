#include <stdio.h> 
#include <stdlib.h> 	
#include "price.c"
	
	
	
Imovel getAvi()
{
	Imovel imoveis;
	getTelaTexto("\t\t\t   SIMULAÇÃO AVISTA");
		
	float valorAvista, descporcento, desc, avista;
	if(strcmp(statusOperador,"Consulta")==0&& strcmp(statusTipo,"VENDA")==0)
	{
		valorAvista = imovelPreco;
		printf("\n\tInforme o valor do Imovel: R$ %.2f",valorAvista);
		descporcento = 5;		
		printf("\n\tPorcentagem do Desconto : %f ",descporcento);
	}
	else
	{
	
		printf("\n\tInforme o valor do Imovel: R$ ");
		scanf("%f", &valorAvista);
		
		printf("\n\tPorcentagem do Desconto : ");
		scanf("%f", &descporcento);
	}
	
	
		desc =  descporcento * valorAvista / 100;
		avista = valorAvista - desc;
	
		printf("\n\tValor do desconto: R$ %.2f\n", desc);	
		printf("\n\tValor do imovel com desconto: R$ %.2f", avista);

 	getEnter();
 	return imoveis;
 	

}

