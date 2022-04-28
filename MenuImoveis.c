#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Login_Cadastro.c"


// FUNÇÃO MENU PARA ACESSAR O PROGRAMA
Usuario getMenuInicial()
{
	int opcao; 
	Usuario usuario;
	usuario = getTelaUsuario();
	while( opcao <= 0 || 3 < opcao)
	{
		printf("\t\t\t\t\t\t\t\tLOGIN  \n\n");
		printf("\t\t\t\t\t\t\t(1) - Acessar conta \n");
		printf("\t\t\t\t\t\t\t(2) - Cadastrar Usuarios \n");
		printf("\t\t\t\t\t\t\t(3) - Esqueci a senha\n");
		printf("\t\t\t\t\t\t\t(0) - Ajuda \n"); 
		printf("\n\t\t\t\t\t\t\tSELECIONE A OPÇÃO DESEJADA: ");
	
		scanf("%i", &opcao);
	
			switch(opcao){
			case 1: 
				system("cls");
				getAcessarConta();
				system("cls");
				getMenuInicial();
			break;
			case 2: 
				system("cls");
				getcliente();
				system("cls");
				getMenuInicial();
			case 3:
				system("cls");
				getTelaRecuperarSenha();
				system("cls");
				getMenuInicial();
			break;
				case 0:
				system("cls");
				getMenulogin();
				getEnter();
				system("cls");
				getMenuInicial();
			break;
			
			default: 
				system("cls");
				getTelaUsuario();
				system("cls");
				getMenuInicial();
			break;			
		}
	}

}
// ACESSO AO PERFIL COM DADOS DA CONTA E SERVIÇOS 
getPerfil() 
{
	system("cls");
	Usuario usuario;
	
	int opcao = 0;	
	
	while( opcao < 1 || opcao > 8) 
	{
		printf(" ***************************************************************************************************************************************\n");
		printf("\t\t\t\t\t\t\t   IMOBILIARIA XPTO                                 \n");
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
		printf(" Usuario: %s                                                   \t\t\t\t\t\t   %s \n",statusNome,statusUser);
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n\n");
		
		printf("\t\t\t\t\t\t\t\tPERFIL  \n\n");
		printf("\t\t\t\t\t\t\t(1) - Alterar Email\n");
		printf("\t\t\t\t\t\t\t(2) - Alterar senha\n");
		printf("\t\t\t\t\t\t\t(3) - Alterar telefone\n");
		printf("\t\t\t\t\t\t\t(4) - Ver dados do financiamento\n");
		printf("\t\t\t\t\t\t\t(5) - VOLTAR\n");
		printf("\t\t\t\t\t\t\t(6) - SAIR\n");					  
		printf("\t\t\t\t\t\t\t(0) - AJUDA\n");	
		printf("\t\t\t\t\t\t\t(7) - Excluir Conta\n");
		printf("\n\t\t\t\t\t\t\tINFORME A OPÇÃO DESEJADA: ");
		scanf("%i", &opcao);
		
		switch (opcao)
		{
			case 1:
				system("cls");
				setPerfil(statusNome);
			break;
			case 2:
				system("cls");
				setPerfil(statusNome);
				
			break;
			case 3:
				system("cls");
				setPerfil(statusNome);
				
			break;
			case 4:
				printf("SIMULAÇÃO DE FINANCIAMENTO");
				system("pause");
				system("cls");
				setPerfil(statusNome);
			break;
			case 5:
				//VOLTA
				system("cls");
				getMenu();
			
			break;
			case 6:
				//SAIR
				system("cls");
				getMenuInicial();
			break;
			case 7:
				//
				system("cls");
				setContaExcluir(statusNome);
				system("cls");
				
				getMenuInicial();
			break;
			
		}
	
	system("cls");
		
	}
}
getMenuDelete()
{
	Usuario usuario;
	int opcao;
	while( opcao < 1 || opcao > 5) 
	{
		printf(" ***************************************************************************************************************************************\n");
		printf("\t\t\t\t\t\t\t   IMOBILIARIA XPTO                                 \n");
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
		printf("Usuario: %s                                                   \t\t\t\t\t\t   %s \n",statusNome,statusUser);
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n\n");
		
		printf("\t\t\t\t\t\t\t   APAGAR IMOVEIS  \n\n");
		printf("\t\t\t\t\t\t\t(1) - ALUGUÉIS\n");
		printf("\t\t\t\t\t\t\t(2) - VENDAS\n");
		printf("\t\t\t\t\t\t\t(3) - VOLTAR\n");
		printf("\t\t\t\t\t\t\t(4) - SAIR\n");					  
		printf("\t\t\t\t\t\t\t(0) - AJUDA\n");	
		printf("\n\t\t\t\t\t\t\tSELECIONE A OPÇÃO DESEJADA: ");
		scanf("%i", &opcao);
		switch (opcao)
		{
			
			case 1:
				system("cls");
				strcpy(statusTipo,"ALUGAR");
				strcpy(statusFunc,"DELETE");
				getTipoImoveis();
				break;
			case 2:
				system("cls");
				strcpy(statusTipo,"VENDA");
				strcpy(statusFunc,"DELETE");
				getTipoImoveis();
				break;
				
			case 3:
				//VOLTA
				system("cls");
				getMenu();
			
			break;
			
			case 4:
				//SAIR
				system("cls");
				getMenuInicial();
				break;
					
			case 0:
				//AJUDA
				system("cls");
				getMenuInicial();
				break;				
		}
	
	}
}
// TELA DO PROPRIETARIO DE IMOVEIS 
getPropietario()
{
	Usuario usuario;
	int opcao;
	while( opcao < 1 || opcao > 7) 
	{
		printf(" ***************************************************************************************************************************************\n");
		printf("\t\t\t\t\t\t\t   IMOBILIARIA XPTO                                 \n");
		printf("\n\n");
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
		printf("Usuario: %s                                                   \t\t\t\t\t\t   %s \n",statusNome,statusUser);
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n\n");
		printf("\t\t\t\t\t\t\t  CADASTRO DE IMOVEIS  \n\n");
		printf("\t\t\t\t\t\t\t(1) - ALUGAR IMOVEIS\n");
		printf("\t\t\t\t\t\t\t(2) - VENDA DE IMOVEIS\n");
		printf("\t\t\t\t\t\t\t(3) - VOLTAR\n");
		printf("\t\t\t\t\t\t\t(4) - SAIR\n");					  
		printf("\t\t\t\t\t\t\t(0) - AJUDA\n");	
		printf("\n\t\t\t\t\t\t\tSELECIONE A OPÇÃO DESEJADA: ");
		scanf("%i", &opcao);
		switch (opcao) {
			
			case 1:
				system("cls");
				strcpy(statusTipo,"ALUGAR");
				strcpy(statusOperador, "Proprietario");
				getTipoImoveis();
				break;
			case 2:
				system("cls");
				strcpy(statusTipo,"VENDA");
				strcpy(statusOperador, "Proprietario");
				getTipoImoveis();
				break;
			case 3:
				//VOLTA
				system("cls");			
				getMenu();
				break;
			case 4:
				//SAIR
				system("cls");
				getMenuInicial();
				break;
			
			case 0:
				//AJUDA
				system("cls");
				getMenuInicial();
				break;	


		}
	system("cls");
	}
	
}
void getFinanciamento()
{
	int opcao; 
	Usuario usuario;
	while( opcao <= 0 || opcao > 7)
	{
		printf(" ***************************************************************************************************************************************\n");
		printf("\t\t\t\t\t\t\t   IMOBILIARIA XPTO                                 \n");
		printf("\n\n");
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
		printf("Usuario: %s                                                   \t\t\t\t\t\t   %s \n",statusNome,statusUser);
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n\n");
		printf("\t\t\t\t\t\t\t    CONTABILIDADE  \n\n");
		printf("\t\t\t\t\t\t\t(1) - AVISTA \n");
		printf("\t\t\t\t\t\t\t(2) - TABELA PRICE \n");
		printf("\t\t\t\t\t\t\t(3) - TABELA SAC\n");
		printf("\t\t\t\t\t\t\t(4) - VOLTAR\n");
		printf("\t\t\t\t\t\t\t(5) - SAIR\n");
		printf("\t\t\t\t\t\t\t(0) - AJUDA \n"); 
		printf("\n\t\t\t\t\t\t\tSELECIONE A OPÇÃO DESEJADA: ");
	
		scanf("%i", &opcao);
	
		switch(opcao)
		{
			case 1: 
				// avista
				if(strcmp(statusOperador,"Consulta")==0)
				{
					system("cls");
					getAvi();
					system("cls");
					getFinanciamento();
				}
				else
				{
					system("cls");
					getAvi();
					system("cls");
					getFinanciamento();	
				}
				
			break;
			case 2: 
				//TABELA PRICE
				if(strcmp(statusOperador,"Consulta")==0)
				{
					system("cls");
					getPrice();
					system("cls");
					getFinanciamento();
				}
				else
				{
					system("cls");
					getPrice();
					system("cls");
					getFinanciamento();	
				}
			case 3:
				//TABELA SAC
					if(strcmp(statusOperador,"Consulta")==0)
				{
					system("cls");
					getsac();
					system("cls");
					getFinanciamento();
				}
				else
				{
					system("cls");
					getsac();
					system("cls");
					getFinanciamento();	
				}
			break;
			case 4: 
				//VOLTAR
				system("cls");
				getMenu();
				
			break;	
			case 5:
				//SAIR
				system("cls");
				getMenuInicial();
			break;
			case 6:

			break;
			case 0:
				//AJUDA
			break;		
		}
		system("cls");
	}

}
// TELA DE ACESSAR SERVIÇOS
getMenu() 
{
	system("cls");
	Usuario usuario;
	
	int opcao = 0;	
	
	while( opcao < 1 || opcao > 9) 
	{
		printf(" ***************************************************************************************************************************************\n");
		printf("\t\t\t\t\t\t\t   IMOBILIARIA XPTO                                 \n");
		printf("\n\n");
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
		printf("Usuario: %s                                                   \t\t\t\t\t\t   %s \n",statusNome,statusUser);
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n\n");
		printf("\t\t\t\t\t\t\t\tMENU  \n\n");
		printf("\t\t\t\t\t\t\t(1) - ALUGUEL DE IMOVEL\n");
		printf("\t\t\t\t\t\t\t(2) - COMPRAR IMOVEL\n");
		printf("\t\t\t\t\t\t\t(3) - PROPRIETÁRIOS\n");
		printf("\t\t\t\t\t\t\t(4) - SIMULAR FINANCIAMENTO\n");		
		printf("\t\t\t\t\t\t\t(5) - PERFIL\n");
			
		if(strcmp(statusUser,"Administrador")==0||strcmp(statusUser,"Consultor")==0)
		{
			printf("\t\t\t\t\t\t\t(6) - DELETAR IMOVEIS\n");
			
			if(strcmp(statusUser,"Administrador")==0)
			{
				printf("\t\t\t\t\t\t\t(7) - CRIAR CONTA\n");		
			}
		}
		printf("\t\t\t\t\t\t\t(8) - SAIR\n");			
		printf("\t\t\t\t\t\t\t(0) - AJUDA\n");
		printf("\n\t\t\t\t\t\t\tSELECIONE A OPÇÃO DESEJADA: ");
		scanf("%i", &opcao);
		
		switch (opcao) {
			
			case 1:
				system("cls");
				strcpy(statusTipo,"ALUGAR");
				strcpy(statusOperador,"Consulta");
				getTipoImoveis();
				getMenu();
			break;
			case 2:
				system("cls");
				strcpy(statusTipo,"VENDA");
				strcpy(statusOperador,"Consulta");
				getTipoImoveis();
				getMenu();
			break;
			case 3:
				system("cls");
				getPropietario();
				getMenu();
			break;				
			case 4:
				//FINANCIAMENTO
				system("cls");
				getFinanciamento();
				break;					
				
				//PERFIL
			case 5:
				system("cls");
				getPerfil();
				getMenu();
			break;
			
			break;
			case 6:
				if(strcmp(statusUser,"Administrador")==0||strcmp(statusUser,"Consultor")==0)
				{
					system("cls");
					strcpy(statusFunc,"DELETE");
					getMenuDelete();
				}
				else
				{
					system("cls");
					getMenu();
					
				}
			break;
			case 7:
				if(strcmp(statusUser,"Administrador")==0)
				{
					system("cls");
					getcliente();
				}
				else
				{
					system("cls");
					getMenu();
					
				}
				
			break;
			case 8:
				//SAIR
				system("cls");
				getMenuInicial();
				break;

			case 0:
				//SAIR
				system("cls");
				getMenuInicial();
				break;				
			
		}
	
	system("cls");
		
	}
}

getTelaCadastroImoveis()
{
	Usuario usuario;
	system("cls");
		printf(" ***************************************************************************************************************************************\n");
		printf("\t\t\t\t\t\t\t   IMOBILIARIA XPTO                                 \n");
		printf("\n\n");
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
		printf("Usuario: %s                                                   \t\t\t\t\t\t   %s \n",statusNome,statusUser);
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n\n");
	salvarImoveis();
}
// TELA COM TIPO SDE IMOVEIS 
getTipoImoveis()
{
	
	int opcao = 0;	
		
	while( opcao < 1 || opcao > 8) 
	{
		Usuario usuario;	
		printf(" ***************************************************************************************************************************************\n");
		printf("\t\t\t\t\t\t\t   IMOBILIARIA XPTO                                 \n");
		printf("\n\n");
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
		printf("Usuario: %s                                                   \t\t\t\t\t\t   %s \n",statusNome,statusUser);
		printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n\n");
		printf("\t\t\t\t\t\t\t   TIPO DE IMOVEL  \n\n");		
		printf("\t\t\t\t\t\t\t(1) - APARTAMENTO\n");
		printf("\t\t\t\t\t\t\t(2) - CASA\n");
		printf("\t\t\t\t\t\t\t(3) - GALPÃO\n");
		printf("\t\t\t\t\t\t\t(4) - TERRENO\n");
		printf("\t\t\t\t\t\t\t(5) - VOLTAR\n");
		printf("\t\t\t\t\t\t\t(6) - SAIR\n");
		printf("\n\n\t\t\t\t\t\t\tSELECIONE A OPÇÃO DESEJADA: ");
		scanf("%i", &opcao);
		
		switch (opcao) 
		{
			
		case 1:
			system("cls");
			strcpy(statusIm,"APARTAMENTO");
			if(strcmp(statusFunc,"DELETE")==0&&(strcmp(statusUser,"Administrador")==0||strcmp(statusUser,"Consultor")==0))
			{
				lerImoveis();
				getDeleteRegistro();
			}
			else if(strcmp(statusOperador,"Consulta")==0)
			{
				lerImoveis();
				getSeleImovel();
				if(strcmp(statusOperador,"Consulta")==0&& strcmp(statusTipo,"VENDA")==0)
					getFinanciamento();
			}		
			else if(strcmp(statusOperador,"Proprietario")==0)
			{
				getTelaCadastroImoveis();
			}
			getEnter();
			strcpy(statusOperador, "");
			system("cls");
			getTipoImoveis();
		break;
		case 2:
			system("cls");
			strcpy(statusIm,"CASA");
			if(strcmp(statusFunc,"DELETE")==0&&(strcmp(statusUser,"Administrador")==0||strcmp(statusUser,"Consultor")==0))
			{
				lerImoveis();
				getDeleteRegistro();
			}
			else if(strcmp(statusOperador,"Consulta")==0)
			{
				lerImoveis();
				getSeleImovel();
				if(strcmp(statusOperador,"Consulta")==0&& strcmp(statusTipo,"VENDA")==0)
					getFinanciamento();
				
			}		
			else if(strcmp(statusOperador,"Proprietario")==0)
			{
				getTelaCadastroImoveis();
			}
			getEnter();
			strcpy(statusOperador, "");
			system("cls");
			getTipoImoveis();
		break;
		case 3:
			system("cls");
			strcpy(statusIm,"GALPÃO");
			if(strcmp(statusFunc,"DELETE")==0&&(strcmp(statusUser,"Administrador")==0||strcmp(statusUser,"Consultor")==0))
			{
				lerImoveis();
				getDeleteRegistro();
			}
			else if(strcmp(statusOperador,"Consulta")==0)
			{
				lerImoveis();
				getSeleImovel();
				if(strcmp(statusOperador,"Consulta")==0&& strcmp(statusTipo,"VENDA")==0)
					getFinanciamento();
				
			}		
			else if(strcmp(statusOperador,"Proprietario")==0)
			{
				getTelaCadastroImoveis();
			}
			getEnter();
			strcpy(statusOperador, "");
			system("cls");
			getTipoImoveis();
		break;
		case 4:		
				system("cls");
				strcpy(statusIm,"TERRENO");
			if(strcmp(statusFunc,"DELETE")==0&&(strcmp(statusUser,"Administrador")==0||strcmp(statusUser,"Consultor")==0))
			{
				lerImoveis();
				getDeleteRegistro();
			}
			else if(strcmp(statusOperador,"Consulta")==0)
			{
				lerImoveis();
				getSeleImovel();
				if(strcmp(statusOperador,"Consulta")==0&& strcmp(statusTipo,"VENDA")==0)
					getFinanciamento();
				
			}		
			else if(strcmp(statusOperador,"Proprietario")==0)
			{
				getTelaCadastroImoveis();
			}
			getEnter();
			strcpy(statusOperador, "");
			system("cls");
			getTipoImoveis();
		break;
		case 5:
			system("cls");
			getMenu();
		break;
		case 6:
			system("cls");
			getMenuInicial();
		break;
		case 7:
		break;
		}
		system("cls");
		getTipoImoveis();
	}

}


