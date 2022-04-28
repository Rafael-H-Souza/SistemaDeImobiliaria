#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Imoveis_Cadastro.c"
#define TAM 4
 int cont = 0;
 
// TELA DE RECUPEÇÃO DE SENHA 
Usuario getTelaRecuperarSenha()
{
	system("cls");	
	Usuario usuario;
	strcpy(usuario.statusTela,"\tRECUPERAÇÃO DE SENHA ");
	strcpy(usuario.statusCabecario,"\tCONTROLE IMOBILIÁRIO ");
	printf(" ***************************************************************************************************************************************\n");
	printf("                                		%s                                 \n",usuario.statusCabecario);
	printf(" ***************************************************************************************************************************************\n\n");
	printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
	printf("                                      		%s                                \n",usuario.statusTela);
	printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n\n");
	
	FILE* arq;
	arq = fopen("Cliente.txt","r");
	
													  
	printf("\n\t\t\t\t\t    		Nome Completo: ");
	gets(usuario.nome);

	
		
	while(!feof(arq))
	{
		fscanf(arq,"%s",usuario.consultaLogin);
		fscanf(arq,"%s",usuario.consultaSenha);
		fscanf(arq,"%s",usuario.consultanome);
		fscanf(arq,"%s",usuario.consultaCpf);
		fscanf(arq,"%s",usuario.consultaNasc);
		fscanf(arq,"%s",usuario.texto);
		fscanf(arq,"%s",usuario.telCel);
		fscanf(arq,"%s",statusUser);
		fscanf(arq,"%s",usuario.seguranca);
				
				
		ColocarEspacos(usuario.consultanome);
		
		if (strcmp(usuario.nome,usuario.consultanome)==0)
		{
			printf("\n\t\t\t\t\t    		CPF: ");
			scanf("%s",usuario.cpf);

						
			if (strcmp(usuario.cpf,usuario.consultaCpf)==0)
			{				
				printf("\n\t\t\t\t\t     		Data de Nascimento: ");
				setData(usuario.nasc,8);
				getEnter();
				
				
				if (strcmp(usuario.nasc,usuario.consultaNasc)== 0)
				{						
					printf("\n\n\t\t\t\t\t     		Email: %s\n\n\t\t\t\t\t     		Senha: %s\n",usuario.consultaLogin,usuario.consultaSenha); 
					
					getEnter();
					cont=5;
										
				}
			
			}
		}
   }
	   
	if( cont < TAM)
	{
		cont++;
 	    getTelaRecuperarSenha();

	}
	else if( cont == TAM)
	{
		printf("\n\n\t\t\t\t\t      		Tentativa errada excedidas\n");
		getEnter();
		system("cls");
		
   	}	
	else
	{
	    //sair
  	}
	fclose(arq);

}
//TELA BEM VINDO
Usuario getTelaUsuario()
{
	Usuario usuario;
	
	strcpy(usuario.statusTela,"\t      BEM VINDO ");
	strcpy(usuario.statusCabecario,"\t CONTROLE IMOBILIÁRIO ");
	printf(" ***************************************************************************************************************************************\n");
	printf("                                		%s                                 \n",usuario.statusCabecario);
	printf(" ***************************************************************************************************************************************\n");
	printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
	printf("                                      		     %s                                \n",usuario.statusTela);
	printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n\n");
	
	return usuario;
}
// ACESSO A LOGIN DE USUARIO 
Usuario getAcessarConta()
{	
	Usuario usuario;
	
	usuario = getTelaUsuario();
		
	printf("\t\t\t\t\t		Usuario: ");
	scanf("%s",usuario.Login);
	//strcpy(usuario.Login,"rafael@gmail.com");printf("rafael@gmail.com");
	
	FILE* arq;
	arq = fopen("Cliente.txt","r");
	
	while(!feof(arq))
	{

		fscanf(arq,"%s",usuario.consultaLogin);
		fscanf(arq,"%s",usuario.consultaSenha);
		fscanf(arq,"%s",usuario.consultanome);
		fscanf(arq,"%s",usuario.consultaCpf);
		fscanf(arq,"%s",usuario.consultaNasc);
		fscanf(arq,"%s",usuario.texto);
		fscanf(arq,"%s",usuario.telCel);
		fscanf(arq,"%s",statusUser);
		fscanf(arq,"%s",usuario.seguranca);
		
		if (strcmp(usuario.Login,usuario.consultaLogin)== 0 )
		{
			printf("\n\t\t\t\t\t		Senha: ");
		
					setSenhaOculta(usuario.senha,'*');
			if (strcmp(usuario.consultaSenha,usuario.senha)== 0)
			{
				ColocarEspacos(usuario.consultanome);
				statusNome == strcpy(statusNome,usuario.consultanome );
				fclose(arq);
				getMenu();
			}
			
			
		}
		
	}
		if( cont == TAM)
		{
			printf("\n\t\t\t\t\t		Tentativa errada excedidas\n");
			getEnter();
			system("cls");
			
	   	}else
		{
	 	    cont++;
	 	   	system("cls");
	 	    getAcessarConta();
	 	    system("pause");
	  	}
	fclose(arq);
	return usuario;
}
// TELA DE CADASTRO PARA NOVOS USUARIOS 
Usuario getTelaCadastro()
{
	Usuario usuario;
	strcpy(usuario.statusTela,"\tFAÇA SEU CADASTRO");
	strcpy(usuario.statusCabecario,"\tCONTROLE IMOBILIARIO ");
	printf(" ***************************************************************************************************************************************\n");
	printf("                                		%s                                 \n",usuario.statusCabecario);
	printf(" ***************************************************************************************************************************************\n");
	printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n");
	printf("                                      		     %s                                \n",usuario.statusTela);
	printf(" - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  \n\n");
	
	return usuario;	
}



