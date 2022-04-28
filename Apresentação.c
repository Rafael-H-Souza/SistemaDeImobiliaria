#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "MenuImoveis.c"


// AGREGAR FUNÇÕES PARA A PRIMEIRA TELA 
void getApresentacao()
{
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t					  Encontre o imóvel para sua história                        \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	getEnter();
	system("cls");
	getMenuInicial();

}

int main ()
{
	

//	system("mode con:cols=140 lines>=30");/* tamanho do console */
	
    unsigned int cp    = 1252; //Codepage latin2

    //Respaldo do codepage original da consola
    unsigned int cpin  = GetConsoleCP();
    unsigned int cpout = GetConsoleOutputCP();



    SetConsoleCP(cp);       //Estabelecendo o codepage de entrada 1252(latin2)
    SetConsoleOutputCP(cp);  //Estabelecendo o codepage de saída 1252(latin2)
	setlocale(LC_ALL,"");
	getApresentacao();
	
	printf("Retornando o codepage de entrada ao estado original: %u\n", cpin );
    SetConsoleCP(cpin);
    printf("Retornando o codepage de saída ao estado  original: %u\n\n", cpout );
    SetConsoleOutputCP(cpout);
	return 0;
}

