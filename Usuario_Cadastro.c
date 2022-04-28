#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "Ajuda.c"

	char statusTipo[30];//DADOS DE ALUGUEL OU VENDA   
	char statusIm[30];//DADOS COMO CASA, APARTAMENTO; TERRENO E OUTROS
	char statusUser[30];// DADOS DO COMPRADOR OU VENDEDOR 
	char statusNome[30];// NOME DO USUARIO	
	char statusFunc[30];// NOME DO USUARIO	
	char seguraTipo[10];// NOME DO USUARIO	
	char Tipologin[15];// NOME DO USUARIO	
	char TipoArqTxt[25];// NOME DO USUARIO	
	char statusOperador[30];// NOME DO USUARIO
	int indice = 0;
	int tamanho;
	int opcao = 0;	
	
typedef struct
{
	char nome[50];
	char consultanome[50];
	char consultaLogin[50];
	char Login[50];
	char nasc[10];
	char consultaNasc[10];
	char senha[15];
	char consultaSenha[15];
	char cpf[10];
	char texto [20];
	char consultaCpf[10];
	int conscpfNum[10];
	char statusTela[30];
	char statusCabecario[30];
	char seguranca[12];
	char verificaCod[2];
	int codigoSeg;
	int codCliente;
	bool Vadidacaocpf;
	int ddd;
	int celular;
	char telCel[9];
	char data[10];
	int cpfnum[11];

}Usuario;
int setArqExiste(char nome[]) {
	FILE* arq = fopen(nome, "r");
    if (arq) {
        fclose(arq);
        return 1;
    }
    return 0;
}
char *getStrDel(char * texto,char *novoTexto)
{
	int i,j = 0;
	for( i = 0; texto[i] != '\0'; i++)
	{
		if (texto[i] != novoTexto[i])
		{
			texto[j++] = novoTexto[i];
		}
	}
	texto[j] = '\0';
	return 0;
}
//FUNÇÃO PEGA SÓ ENTER
void getEnter()
{
	char caractere;
	int c = 0;
    while((caractere = getch())!=13)
    {
        c++;
    }
    
    caractere = '\0';
}
Usuario setTamTexto (char * texto, int tam)
{
	Usuario usuario;
	int tamanho,i, j =1;
	tamanho =strlen(texto);
	
	for(i = 0; i<=tamanho;i++)
	{
		if(i <= tam)
		{
			printf("%c",texto[i]);
		}
		else
		{
			if((texto[i]!=32))
			{
				
				printf("\n\t%c",texto[i]);
			}
			else
			{
				printf("\n\t");
			}
			j++;
			tam= tam*j;
			
		} 
		
		
	}
	return usuario;
}
void setSenhaOculta(char *senha, char caractere)
{
	Usuario usuario;
    int i = 0, tamanho;
 	tamanho = strlen(senha);
 	usuario.texto[tamanho];
    while((senha[i] = getch())!=13)
    {
		if(i > 0 &&senha[i] == 8 )
		{
			i--;
			printf("%c", senha[i]	= 8 );
			printf("%c", 32);
			printf("%c", senha[i]	= 8 );
		
		}
		 else if( senha[i] != 8)
		{	
		
			printf("%c", caractere);
			i++;
		}
	
        
    }
    senha[i] = '\0';
    printf("\n");
    return ;
}
void setTextoABC(char *contador,int tamanho)
{

 	int i = 0;
 	  
    while(i <tamanho && (contador[i] = getch())!=13)
    {   
 	 
		if(i >= 0 &&contador[i] == 8 )
		{
			i--;
			printf("%c", contador[i]= 8 );
			printf("%c", contador[i]= 32 );
			printf("%c", contador[i]= 8 );
			contador[i]	=getch();
		}
		 else if(contador[i] != 8 && contador[i] != 13&& contador[i] != '\0')
		{	
		
			if( contador[i] >= 65 && contador[i] <= 90)
			{
			    printf("%c", contador[i]);
				i++;			
			}
			if( contador[i] >= 97 && contador[i] <= 122)
			{
			    printf("%c", contador[i]);
				i++;			
			}
			if( contador[i] >= 126 && contador[i] <= 122)
			{
			    printf("%c", contador[i]);
				i++;			
			}
		}
	}
	contador[i] = '\0';
}
int setverificarCaracter(char *texto)
{
	int tamanho,i,j;
	bool condi;
	tamanho =strlen(texto);
	for(i = 33; i<=255;i++)
	{
		for(j = 0; j<=tamanho;j++)
		{
			if((i == texto[j] )!= 0)
			{
				if(texto[j] >= 33 && texto[j] <= 44 || texto[j] == 47 )
				{
					condi = true;
					//printf("\n\t401 Caracter não permitido ");
				}
				else if(texto[j] >= 164 && texto[j] <=255 )
				{
					condi = true;
					
					//printf("\n\t402 Caracter não permitido %c", texto[j]);
				}
				else if(texto[j] >= 145 && texto[j] <=159 )
				{
					condi = true;
					printf("\nfalse\t");
					printf("3 Caracter não permitido %c", texto[j]);
				}
				else if(texto[j] >= 58 && texto[j] <= 63 )
				{
					condi = true;
					printf("\nfalse\t");
					printf("4 Caracter não permitido %c", texto[j]);
				}
				else if(texto[j] == 91 || texto[j] == 92 ||texto[j]== 93  ||texto[j] == 95|| texto[j] == 123 || texto[j] == 124 || texto[j] == 125 )
				{
					condi = true;
					printf("\nfalse\t");
					printf("5 Caracter não permitido %c", texto[j]);
				}		
				
				
			}
			
		}
	}
	
//	printf("\ncondi: %i", condi);
	return condi;
}
int setverificarNum(char *texto)
{
	int tamanho,i,j;
	bool condi;
	tamanho =strlen(texto);
	for(i = 48; i<=57;i++)
	{
		for(j = 0; j<=tamanho;j++)
		{
			if((i == texto[j] )!= 0)
			{
				condi = true;
//				printf("\nfalse\t");
//				printf("\tCaracter não permitido %c\n", texto[j]);
				
			}
			
		}
	}
	
//	printf("\ncondi: %i", condi);
	return condi;
}
void getEsc()
{
	char caractere;
	int c = 0;
    while((caractere = getch())!=27)
    {
        c++;
    }
    
    caractere = '\0';
}	
void TirarEspacos(char *texto)
{
    int i;
    for(i=0;i<strlen(texto);i++)
    {
        if(texto[i]==' ')
        {
            texto[i] = '+';
        }
    }
    
}
void ColocarEspacos(char *texto)
{
   int i;
    for(i=0;i<strlen(texto);i++)
    {
        if(texto[i]=='+')
        {
            texto[i] = ' ';
        }
    }
}
Usuario setBackspace(char *contador)
{	
	Usuario usuario;
 	int i = 0, tamanho;
 	tamanho = strlen(contador);
 	usuario.texto[tamanho];
   
    while((contador[i] = getch())!=13)
    {   
		if(i >= 0 &&contador[i] == 8 )
		{
			if(i > 0)
				i--;
				
			printf("%c",8);
			printf("%c",32 );
			printf("%c",8 );
			
		}
		 else if( contador[i] != 8)
		{	
		     
			printf("%c", contador[i]);
			i++;
		}
	}
	contador[i] = '\0';
	printf("\n");
	return usuario;
}
void setNumero(char *contador,int tamanho)
{

 	int i = 0;
 	  
    while(i <tamanho && (contador[i] = getch())!=13)
    {   
 	 	
		if(i >= 0 &&contador[i] == 8 )
		{
			if(i > 0)
				i--;
				
			printf("%c",8);
			printf("%c",32 );
			printf("%c",8 );
			
		}
		 else if(contador[i] != 8 && contador[i] != 13&& contador[i] != '\0')
		{	
		
			if( contador[i] >= 48 && contador[i] <= 57)
			{
			    printf("%c", contador[i]);
				i++;			
			}
		}
	}
	contador[i] = '\0';

	
	
}
void setData(char *contador,int tamanho)
{

 	int i = 0;
 	  
    while(i <tamanho && (contador[i] = getch())!=13)
    {   
 	 	 if(i >= 0 &&  contador[i] == 8)
		{
			if(i == 2)
			{
				printf("%c",8);
				printf("%c",32 );
				printf("%c",8 );	
			}
			else if(i == 4)
			{
				printf("%c",8);
				printf("%c",32 );
				printf("%c",8 );	
			}
			if(i > 0)
			{
				i--;
				
				printf("%c",8);
				printf("%c",32 );
				printf("%c",8 );
			}
			
		}
		
		 else if(contador[i] != 8 && contador[i] != 13 && contador[i] != '\0')
		{	
				//dia = d				
				if(i == 0 && contador[i] >= 48 && contador[i] <= 51)
				{
					printf("%c", contador[i]);
					i++;
				}
				//dia = dd
				if(i == 1 && contador[i] >= 48 && contador[i] <= 57 && contador[0] < 51)
				{
					printf("%c", contador[i]);
					printf("%c",47 );
					i++;
				}
				else if(i == 1 && contador[i] >= 48 && contador[i] <= 49 && contador[0] == 51)
				{
					printf("%c", contador[i]);
						printf("%c",47 );
						i++;
				}
				//mes m
				if (i == 2 && contador[i] == 48)
				{
					printf("%c", contador[i]);
				
					i++;
				}
				else if(i == 2 && contador[i] == 49)
				{
					printf("%c", contador[i]);
				
					i++;
				}
				//mes mm
				else if(i == 3 && contador[i] >= 49 && contador[i] <= 57 && contador[2] == 48)
				{
					printf("%c", contador[i]);
					printf("%c",47 );
					i++;
				}
				else if(i == 3 && contador[i] >= 48 && contador[i] <= 50 && contador[2] == 49)
				{
					printf("%c", contador[i]);
					printf("%c",47 );
					i++;
				}	
				//ano a
				if(i == 4 && contador[i] == 50)
				{
					printf("%c", contador[i]);
					i++;
				}
				else if(i == 4 && contador[i] == 49)
				{
					printf("%c", contador[i]);
					i++;
				}
				//ano aa
				if(i == 5 && contador[4] == 50 && contador[i] == 48 )
				{
					printf("%c", contador[i]);
					i++;
				}
				else if(i == 5 && contador[4] == 49 && contador[i] == 57)
				{
					printf("%c", contador[i]);
					i++;
				}
				//ano aaa
				if(i == 6 && contador[5] == 57 && contador[i] >= 52 && contador[i] <= 57)
				{
					printf("%c", contador[i]);
					i++;
				}
				else if(i == 6 &&contador[4] == 50 && contador[5] == 48 && contador[i] == 48 )
				{
					printf("%c", contador[i]);
					i++;
				}
				//ano aaaa
				if(i == 7 && contador[6] == 48 && contador[i] >= 48 && contador[i] <= 50)
				{
					printf("%c", contador[i]);
					i++;
				}
				else if(i == 7 && contador[6] >= 52 && contador[i] >= 48 && contador[i] <= 57 )
				{
					printf("%c", contador[i]);
					i++;
				}
							
			
		} 
//		printf("(%i)",i);
	}
	contador[i] = '\0';
}
Usuario getNomeCompleto()
{
	Usuario usuario;
	int tamanho, i;
	bool condi ;
	char nome[50];
	getchar();
	do
	{
		system("cls");
		condi = false;
		getTelaTexto("\t\t\t    Criar sua Conta");
		printf("\n\tInforme nome Completo: ");
		gets(nome);
		
		tamanho = strlen(nome);
		if((tamanho <= 6)!=0)
		{
			printf("\n\tNome negado!");
			printf("\n\tTamanho de nome invalida");
			condi = true;			

		}
		if(setverificarNum(nome) != 0)
		{
			printf("\n\tNome negado!");
			printf("\n\tNão é permitido numeros nesse campo");
			condi = true;			
		}
		if(setverificarCaracter(nome) != 0)
		{
			condi = true;	
			printf("\n\tNome negado!");
			printf("\n\t401 Caracter não permitido ");
		}
		for(i = 0;i <= strlen(nome);i++)
		{
	 		if(nome[i] == 64 || nome[i] == 45 || nome[i] == 46)
			{
				condi = true;
				printf("\n\tNome negado!");
				printf("\n\t406 Caracter não permitido %c", nome[i]);
			}
		}
	
		
	}while(condi != 0);
	strcpy(usuario.nome, nome);
	return usuario;	
}
Usuario getCPF()
{
	Usuario usuario;
	bool valid = false;
	int multiplicador[] = {11,10,9,8,7,6,5,4,3,2};

	
	usuario	= getNomeCompleto();

	 
	while(valid == 0)
	{
		int i, j = 1;
		int mult1 = 0, mult2 = 0;
		int soma1 = 0, soma2 = 0;
			
		system("cls");
		getTelaTexto("\t\t\t    Criar sua Conta");
		printf("\n\tNome Completo: %s",usuario.nome);
		printf("\n\tDigita o CPF: ");
		setNumero(usuario.cpf,11);
		
		for(i = 0; i <strlen(usuario.cpf); i++)
		{
			switch(usuario.cpf[i])
			{
				case 48:
					usuario.cpfnum[i]=0;
				break;
				case 49:
					usuario.cpfnum[i]=1;
				break;
				case 50:
					usuario.cpfnum[i]=2;
				break;
				case 51:
					usuario.cpfnum[i]=3;
				break;
				case 52:
					usuario.cpfnum[i]=4;
				break;
				case 53:
					usuario.cpfnum[i]=5;
				break;
				case 54:
					usuario.cpfnum[i]=6;
				break;
				case 55:
					usuario.cpfnum[i]=7;
				break;
				case 56:
					usuario.cpfnum[i]=8;
				break;
				case 57:
					usuario.cpfnum[i]=9;
				break;
				default:
				
				 break;
			}
		
			if(i<9)
			{
				mult1 = usuario.cpfnum[i] * multiplicador[j];
				soma1 += mult1;
				//printf("\n soma 1 %i",	soma1 );
			j++;
		 	}
		 	
			if(i <= 9)
			{
				mult2  = usuario.cpfnum[i] * multiplicador[i];
				soma2 += mult2;
				//printf("\n soma 2 %i",	soma2 );			
			}
				
		}
		soma1= ((soma1*10)%11);
		soma2= ((soma2*10)%11);
					
		if(soma1 == 10){
			soma1 =0;
		}
		if(soma2 == 10){
			soma2 =0;
		}	
		
		if(usuario.cpfnum[9]==soma1 && usuario.cpfnum[10]==soma2 )
		{
			valid= true;
		}
		else
		{	system("cls");
			getTelaTexto("\t\t\t    Criar sua Conta");
			printf("\n\tNome Completo: %s \n" ,usuario.nome);
			printf("\n\tCPF: %s Invalido!\n",usuario.cpf);
			getEnter();
			
			for(i = 0;i<=11;i++)
			{
				soma1=0;
				soma2= 0;
				mult1= 0;
				mult2= 0;
				usuario.cpfnum[i]= 0;
			
				//system("Pause");
				//system("cls");
			}
			system("cls");
			getTelaTexto("\t\t\t    Criar sua Conta");
			printf("\n\tNome Completo: %s \n" ,usuario.nome);
					
		}

	}
	return usuario;	
}
Usuario getNasc()
{
	Usuario usuario;
	int i;
	char data[10];
	bool  valid = false;
	
	usuario= getCPF();
	
	while(valid == 0)
	{
		system("cls");
		getTelaTexto("\t\t\t    Criar sua Conta");
		printf("\n\tNome Completo: %s",usuario.nome);
		printf("\n\tCPF: %s",usuario.cpf);
					
		printf("\n\tInforme a data de nascimento: ");
		setData(data, 8);
		
		if((strlen(data) == 8)!=0){
			strcpy(usuario.nasc, data);
			valid = true;
		}else {
			printf("\tDigite novamente a data\n");
			valid = false;
		}
	}
	return usuario;
}
Usuario getEmail()
{
	Usuario usuario;
	int x,tamanho;
	char tipoEmail[15];
	int i,j; 
	bool  valid = false;
	
	usuario = getNasc();
	
	getchar();
	while(valid == 0)
	{	
	
		system("cls");
		getTelaTexto("\t\t\t    Criar sua Conta");
		printf("\n\tNome Completo: %s " ,usuario.nome);
		printf("\n\tCPF: %s ",usuario.cpf);
		printf("\n\tData de Nascimento: %s ",usuario.nasc);
		printf("\n\tInforme seu email: ");
		gets(usuario.Login);
		
		if(setverificarCaracter(usuario.Login) == 0)
		{		
			tamanho = strlen(usuario.Login);
			
			for(i = 0; i <=tamanho; i++)
				if((usuario.Login[i] == 64) != 0)
					x = i;
					
			i=0;
			for(j = 0; j <tamanho; j++)			
				if(j >= x)
				{
					Tipologin[i] = usuario.Login[j];
					
					i++;
				}
		
			if(strcmp(Tipologin,"@gmail.com")==0)
			{
				strcpy(statusUser,"Cliente");
				strcpy(usuario.verificaCod,"CL");
				valid= true;
			}
			else if(strcmp(Tipologin,"@hotmail.com")==0)
			{
				strcpy(statusUser,"Cliente");
				strcpy(usuario.verificaCod,"CL");
				valid= true;
			}
			else if(strcmp(Tipologin,"@outlook.com")==0)
			{
				strcpy(statusUser,"Cliente");
				strcpy(usuario.verificaCod,"CL");
				valid= true;
			}
			else if(strcmp(Tipologin,"@yahoo.com")==0)
			{
				strcpy(statusUser,"Cliente");
				strcpy(usuario.verificaCod,"CL");
				valid= true;
			}
			else if(valid==0)
			{
				printf("\n\tEMAIL INVALIDO-\n");
				getStrDel(Tipologin,tipoEmail);
				printf("%s",Tipologin);
				getEnter();
			}
			if(strcmp(statusUser,"Administrador")==0)
			{
				if(strcmp(Tipologin,"@docente.unip.com")==0)
				{
					strcpy(statusUser,"Consultor");
					strcpy(usuario.verificaCod,"CO");
					valid= true;
				}
				else if(strcmp(Tipologin,"@aluno.unip.com")==0)
				{
					strcpy(statusUser,"Consultor");
					strcpy(usuario.verificaCod,"CO");
					valid= true;
				}
				else if(strcmp(Tipologin,"@adm.unip.com")==0)
				{
					strcpy(statusUser,"Administrador");
					strcpy(usuario.verificaCod,"AD");
					valid= true;
				}
				else if(valid==0)
				{
					printf("\n\tEMAIL INVALIDO-\n");
					getStrDel(Tipologin,tipoEmail);
					printf("%s",Tipologin);
					getEnter();
				}
			}
		}
	
	}
	return usuario;
}
Usuario getSenha()
{
	char  texto[20];
	char  texto1[20];
	Usuario usuario;
	usuario = getEmail();
	bool  valid = false;
	
	while(valid == 0)
	{
		system("cls");
		getTelaTexto("\t\t\t    Criar sua Conta");
		printf("\n\tNome Completo: %s " ,usuario.nome);
		printf("\n\tCPF: %s ",usuario.cpf);
		printf("\n\tData de Nascimento: %s ",usuario.nasc);
		printf("\n\tEmail: %s ",usuario.Login);
		printf("\n\tInforme a senha: ");
		
		setSenhaOculta(texto,'*');
		
		if((strlen(texto)>= 8)!=0)
		{
			printf("\tConfirme a senha: ");
		
			setSenhaOculta(texto1, '*');
			
			if(strcmp(texto,texto1)==0)
			{
				
				strcpy(usuario.senha,texto1);
				tamanho= strlen(usuario.senha);
				TirarEspacos(usuario.senha);
				valid = true;
			}
			else
			{
				printf("\n\tsenha invalida\n");
				getEnter();
			}
		}
		else
		{
			printf("\n\tsenha invalida\n");
			getEnter();
		}
	}
	return usuario;
}
Usuario getDDDCelular()
{
	Usuario usuario;
	usuario =getSenha();
	int ddd, i = 0;
	char estado[2];
	bool valid = false;
	bool valido = false;

		
	while(valido == 0)
	{
		while(valid == 0)
		{
			system("cls");
			getTelaTexto("\t\t\t    Criar sua Conta");
			printf("\n\tNome Completo: %s " ,usuario.nome);
			printf("\n\tCPF: %s ",usuario.cpf);
			printf("\n\tData de Nascimento: %s ",usuario.nasc);
			printf("\n\tEmail: %s ",usuario.Login);
			printf("\n\tDigite o DDD: ");
			scanf("%i" ,&ddd); 
			valid = true;
			printf("\n");
			if(ddd==11)strcpy(estado,"SP"); 
			else if(ddd==12)strcpy(estado,"SP");
			else if(ddd==13)strcpy(estado,"SP");
			else if(ddd==14)strcpy(estado,"SP");
			else if(ddd==15)strcpy(estado,"SP");
			else if(ddd==16)strcpy(estado,"SP");
			else if(ddd==17)strcpy(estado,"SP");
			else if(ddd==18)strcpy(estado,"SP");
			else if(ddd==19)strcpy(estado,"SP");
			else if(ddd==21)strcpy(estado,"RJ");
			else if(ddd==22)strcpy(estado,"RJ");
			else if(ddd==24)strcpy(estado,"RJ");
			else if(ddd==27)strcpy(estado,"ES");
			else if(ddd==28)strcpy(estado,"ES");
			else if(ddd==31)strcpy(estado,"MG");
			else if(ddd==32)strcpy(estado,"MG");
			else if(ddd==33)strcpy(estado,"MG");
			else if(ddd==34)strcpy(estado,"MG");
			else if(ddd==35)strcpy(estado,"MG");
			else if(ddd==37)strcpy(estado,"MG");
			else if(ddd==38)strcpy(estado,"MG");
			else if(ddd==41)strcpy(estado,"PR");
			else if(ddd==42)strcpy(estado,"SC");
			else if(ddd==42)strcpy(estado,"PR");
			else if(ddd==43)strcpy(estado,"PR");
			else if(ddd==44)strcpy(estado,"PR");
			else if(ddd==45)strcpy(estado,"PR");
			else if(ddd==46)strcpy(estado,"PR");
			else if(ddd==47)strcpy(estado,"SC");
			else if(ddd==47)strcpy(estado,"PR");
			else if(ddd==48)strcpy(estado,"SC");
			else if(ddd==49)strcpy(estado,"SC");
			else if(ddd==49)strcpy(estado,"PR");
			else if(ddd==51)strcpy(estado,"RS");
			else if(ddd==53)strcpy(estado,"RS");
			else if(ddd==54)strcpy(estado,"RS");
			else if(ddd==55)strcpy(estado,"RS");
			else if(ddd==61)strcpy(estado,"DF");
			else if(ddd==61)strcpy(estado,"GO");
			else if(ddd==62)strcpy(estado,"GO");
			else if(ddd==63)strcpy(estado,"TO");
			else if(ddd==64)strcpy(estado,"GO");
			else if(ddd==65)strcpy(estado,"MT");
			else if(ddd==66)strcpy(estado,"MT");
			else if(ddd==67)strcpy(estado,"MS");
			else if(ddd==68)strcpy(estado,"AC");
			else if(ddd==69)strcpy(estado,"RO");
			else if(ddd==71)strcpy(estado,"BA");
			else if(ddd==73)strcpy(estado,"BA");
			else if(ddd==74)strcpy(estado,"BA");
			else if(ddd==75)strcpy(estado,"BA");
			else if(ddd==77)strcpy(estado,"BA");
			else if(ddd==79)strcpy(estado,"SE");
			else if(ddd==81)strcpy(estado,"PE");
			else if(ddd==82)strcpy(estado,"AL");
			else if(ddd==83)strcpy(estado,"PB");
			else if(ddd==84)strcpy(estado,"RN");
			else if(ddd==85)strcpy(estado,"CE");
			else if(ddd==86)strcpy(estado,"PI");
			else if(ddd==87)strcpy(estado,"PE");
			else if(ddd==88)strcpy(estado,"CE");
			else if(ddd==89)strcpy(estado,"PI");
			else if(ddd==91)strcpy(estado,"PA");
			else if(ddd==92)strcpy(estado,"AM");
			else if(ddd==93)strcpy(estado,"PA");
			else if(ddd==94)strcpy(estado,"PA");
			else if(ddd==95)strcpy(estado,"RR");
			else if(ddd==96)strcpy(estado,"AP");
			else if(ddd==97)strcpy(estado,"AM");
			else if(ddd==98)strcpy(estado,"MA");
			else if(ddd==99)strcpy(estado,"MA");
			
			else
			{	
				valid = false;
				printf("\n\tDDD INVALIDO! %i\n", ddd);
				getEnter();
			//	system("cls");
			}
		}
	
	usuario.ddd = ddd;
	
		system("cls");
		getTelaTexto("\t\t\t    Criar sua Conta");
		printf("\n\tNome Completo: %s " ,usuario.nome);
		printf("\n\tCPF: %s ",usuario.cpf);
		printf("\n\tData de Nascimento: %s ",usuario.nasc);
		printf("\n\tEmail: %s ",usuario.Login);
		printf("\n\tDigite o numero:\n");
		printf("\t%s %i ", estado,ddd);
	 	scanf("%i",&usuario.celular);
		
		if(usuario.celular >=900000000 && usuario.celular <=999999999 )
		{
			valido = true;
			printf("\t(%i) %i \n",usuario.ddd,usuario.celular);
		}
		else 
		{
			valido = false;
			valid = false;
			printf("\n\tNumero Invalido!\n\tDigite novamente:\n");
			getEnter();
			usuario.celular= 0;
		}
			
	}
	
	
 return usuario;
 }
Usuario getcodigoDeSeguracao()
{
	Usuario usuario;
	usuario=getDDDCelular();
	
	srand(time(NULL) );
    usuario.codigoSeg = rand();
    //printf("\n\tCodigo de seguraça: %d\n", usuario.codigoSeg);
    getEnter();
    return usuario;
       
}		
getcliente()
{		
		Usuario usuario;
		usuario=getcodigoDeSeguracao();
		FILE * arq;
		arq = fopen("Cliente.txt","a+");
	    TirarEspacos(usuario.nome);
		fprintf(arq,"\n%s \t ",usuario.Login);
		fprintf(arq,"%s\t",usuario.consultaSenha);
		fprintf(arq,"%s\t",usuario.nome);
		fprintf(arq,"%s\t",usuario.cpf);
		fprintf(arq,"%s\t\t",usuario.nasc);
		fprintf(arq,"(%i) %i\t",usuario.ddd,usuario.celular);
		fprintf(arq,"%s\t",statusUser);
		fprintf(arq,"%s%i",usuario.verificaCod,usuario.codigoSeg);
		printf("\n\tSalvo com sucesso\n");
		getEnter();
	fclose(arq);
	
 	system("cls");
		getTelaTexto("\t\t\t    Criar sua Conta");
		printf("\n\tNome Completo: %s " ,usuario.nome);
		printf("\n\tCPF: %s ",usuario.cpf);
		printf("\n\tData de Nascimento: %s ",usuario.nasc);
		printf("\n\tEmail: %s ",usuario.Login);
		printf("\n\tNumero: (%i) %i\t",usuario.ddd,usuario.celular);
	 	printf("%s%i",usuario.verificaCod,usuario.codigoSeg);
	 	getEnter();

}
//int setValorReal()
//{
//
//	int i ,j = 1, indice = 0, num,*numero;
//	numero = malloc (sizeof (int)*i);
//	
//	printf("r\t0,0");
//	while((num = getch())!= 13 &&( indice >=0 || indice <=16))
//	{
//		if(i > 0 && num == 8 )
//		{		
//			printf("%c", 8);
//			printf("%c", 32);
//			printf("%c", 8);
//				
//			if(indice > 0)
//			{
//				i--;
//				indice--;
//				numero[indice] = 0;
//			
//				printf("%c", 8);
//				printf("%c", 32);
//				printf("%c", 8);
//			}
//				
//			for(i = indice; i >= 0; i-- )
//				printf("%c", 8);
//			if(indice < 4 && i > 1)
//				printf("%c",8);
//			if( indice >=5 )
//				printf("%c",8);
//			if( indice >=8 )
//				printf("%c",8);
//			if( indice >=11 )
//				printf("%c",8);
//			if( indice >=14 )
//				printf("%c",8);
//						
//			for(i= 0; i <= indice; i++ )
//			{
//				if(indice == 2 && i == 0)
//					printf("\t%c%c",48,44);
//				else if(indice == 1 && i == 0)
//					printf("%c%c",44,48);
//				else if(indice == 0 && i == 0)
//					printf("%c",48);
//					
//				if(indice >=3 && i == indice -2)
//					printf("%c",44);
//							
//				printf("%c",numero[i]);
//				
//				if(indice >=5 &&i == indice - 6)
//					printf("%c",46);
//				else if(indice >=8 &&i == indice - 9)
//					printf("%c",46);
//				else if(indice >=11 &&i == indice - 12)
//					printf("%c",46);
//				else if(indice >=13 &&i == indice - 15)
//					printf("%c",46);
//			}
//		}
//		
//		
//		else if( num >= 48 && num<= 57)
//		{
//			i == indice;
//			numero[indice] = num;
//		    			
//			if(indice >= 0)
//			{
//				for(i = indice; i >=0 ; i--)
//					printf("%c", 8);
//							
//					if( indice >=5 )
//						printf("%c",8);
//					if( indice >=8 )
//						printf("%c",8);
//					if( indice >=11 )
//						printf("%c",8); 
//					if( indice >=14 )
//						printf("%c",8);
//	
//				for(i = 0; i <= indice; i++)
//				{
//					if( indice <= 3 &&i == indice -1)
//						printf("%c",44);
//					
//					if( indice >=4   && i == indice-1)
//						printf("%c",44);
//										
//					printf("%c",numero[i]);
//										
//					if(indice >=5 &&i == indice - 5)
//						printf("%c",46);
//					else if(indice >=8 &&i == indice - 8)
//						printf("%c",46);
//					else if(indice >=11 &&i == indice - 11)
//						printf("%c",46);
//					else if(indice >=13 &&i == indice - 14)
//						printf("%c",46);
//						
//				
//				}
//					indice++;
//			}
//		}
//		
//	}
//					printf("(%i)",indice);
//}
//
//int main ()
//{
//	//setValorReal();
//	getEmail();
//	
//	return 0;
//}

//
//	time_t agora;
//	agora = time(NULL);
//	strftime(usuario.texto,sizeof(usuario.texto),"%c", localtime( &agora ) );
//    printf( "Data/Hora: %s\n", usuario.texto );
