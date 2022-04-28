#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Avista.c"

// TELA COM DADOS DE USUARIO 

void setPerfil(char *user)
{	
	Usuario usuario;
	getTelaTexto("\t\t\t\tPerfil");
	char statususer[30];
	FILE* arq;
	arq = fopen("Cliente.txt","r");
	while(!feof(arq))											  
	{					
		fscanf(arq,"%s",usuario.consultaLogin);
		fscanf(arq,"%s",usuario.consultaSenha);
		fscanf(arq,"%s",usuario.consultanome);
		fscanf(arq,"%s",usuario.consultaCpf);
		fscanf(arq,"%s",usuario.consultaNasc);
		fscanf(arq,"%s",usuario.telCel);
		fscanf(arq,"%s",usuario.texto);
		fscanf(arq,"%s",statususer);
		fscanf(arq,"%s",usuario.seguranca);
		
		ColocarEspacos(usuario.consultanome);
		
		if(strcmp(statusNome,usuario.consultanome)==0)
		{
			printf("\n\t\t\t\t\t\t\t Nome: %s",usuario.consultanome);
			printf("\n\t\t\t\t\t\t\t Data Nascimento: %s",usuario.consultaNasc);
			printf("\n\t\t\t\t\t\t\t CPF: %s",usuario.consultaCpf);
			printf("\n\t\t\t\t\t\t\t Celular %s %s",usuario.telCel,usuario.texto);
			printf("\n\t\t\t\t\t\t\t Email: %s",usuario.consultaLogin);
			printf("\n\t\t\t\t\t\t\t Senha: %s",usuario.consultaSenha);
			printf("\n\t\t\t\t\t\t\t Codigo de Cliente: %s ",usuario.seguranca);
			printf("\n\t\t\t\t\t\t\t Tipo de Conta: %s",statususer);
			printf("\n\n");

		}
			
	}
	fclose(arq);
	
	getEnter();

}

void setContaExcluir(char *user)
{	
	Usuario usuario;
	
	FILE* arq = fopen("Cliente.txt","r");
	FILE* aux= fopen("ContaAuxiliar.txt","w");
	FILE* ExcluirConta= fopen("ExcluirConta.txt","a+");
	getTelaTexto("Excluir Perfil");
	while(!feof(arq))											  
	{	
				
		fscanf(arq,"%s",usuario.consultaLogin);
		fscanf(arq,"%s",usuario.consultaSenha);
		fscanf(arq,"%s",usuario.consultanome);
		fscanf(arq,"%s",usuario.consultaCpf);
		fscanf(arq,"%s",usuario.consultaNasc);
		fscanf(arq,"%s",usuario.telCel);
		fscanf(arq,"%s",usuario.texto);
		fscanf(arq,"%s",statusUser);
		fscanf(arq,"%s",usuario.seguranca);
		
			ColocarEspacos(usuario.consultanome);
		
		if(strcmp(statusNome,usuario.consultanome)!=0)
		{
			if (!setArqExiste("ContaAuxiliar.txt"))
			{
  		    	printf("\n\nNenhum conta foi excluido.\n");
				return;
				
   			}
			TirarEspacos(usuario.consultanome);
			
			fprintf(aux,"\n\n%s\t ",usuario.consultaLogin);
			fprintf(aux,"%s\t",usuario.consultaSenha);
			fprintf(aux,"%s\t",usuario.consultanome);
			fprintf(aux,"%s\t",usuario.consultaCpf);
			fprintf(aux,"%s\t",usuario.consultaNasc);
			fprintf(aux,"%s\t",usuario.telCel);
			fprintf(aux,"%s\t",usuario.texto);
			fprintf(aux,"%s\t",statusUser);
			fprintf(aux,"%s",usuario.seguranca);
		 	
		}
		else
		{
			printf("\n\tNome: %s",usuario.consultanome);
			printf("\n\tData Nascimento: %s",usuario.consultaNasc);
			printf("\n\tCPF: %s",usuario.consultaCpf);
			printf("\n\tCelular %s %s",usuario.telCel,usuario.texto);
			printf("\n\tEmail: %s",usuario.consultaLogin);
			printf("\n\tSenha: %s",usuario.consultaSenha);
			printf("\n\tCodigo de Cliente: %s ",usuario.seguranca);
			printf("\n\tTipo de Conta: %s",statusUser);
			printf("\n\n");
			
			TirarEspacos(usuario.consultanome);
			fprintf(ExcluirConta,"\n\n%s\t ",usuario.consultaLogin);
			fprintf(ExcluirConta,"%s\t",usuario.consultaSenha);
			fprintf(ExcluirConta,"%s\t",usuario.consultanome);
			fprintf(ExcluirConta,"%s\t",usuario.consultaCpf);
			fprintf(ExcluirConta,"%s\t",usuario.consultaNasc);
			fprintf(ExcluirConta,"%s\t",usuario.telCel);
			fprintf(ExcluirConta,"%s\t",usuario.texto);
			fprintf(ExcluirConta,"%s\t",statusUser);
			fprintf(ExcluirConta,"%s",usuario.seguranca);
			
			
		}
	}
    fclose(arq);
	fclose(ExcluirConta);
	fclose(aux);
	
	
    system("del Cliente.txt");
	system("rename ContaAuxiliar.txt Cliente.txt");
	getEnter();
			
	
}

