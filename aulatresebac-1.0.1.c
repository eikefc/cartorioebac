#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[15];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nNome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	system ("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	char cpf[15];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
			printf("CPF n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio solicitado: ");
		printf("%s", conteudo);
		printf("\n\n");
	
	}

	system("pause");
}

int deletar()
{
	printf("Deletar um usu�rio\n");
	system("pause");
}

int main()
{
		int opcao=0; //Definindo Variavel
		int laco=1;
		
		for(laco=1;laco=1;)
		{
		
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
			printf("### Banco de Dados EBAC ###\n\n"); //Dando introdu��o ao programa //Fim do Menu
			printf("Escolha uma op��o:\n\n"); //Solicitando escolha de uma op��o
			printf("\t 1- Registrar Usu�rio\n");
			printf("\t 2- Consultar Usu�rio\n");
			printf("\t 3- Deletar Usu�rio\n\n\n"); 
			printf("\t 4- Sair do programa\n\n\n ");
			printf("Op��o: ");//Fim, do menu
		
			scanf("%d",&opcao); //Captar inform��o dada ap�s execu��o
		
			system("cls"); //Limpar prompt ap�s captura
			
			switch(opcao) 
			{
				case 1: //Inicio Sele��o
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("\nObrigado por usar o cart�rio da EBAC\n");
				return 0;
				
				default:
				printf("Op��o Inv�lida\n");
				system("pause");
				break;	//Fim Sele��o
			
			}
			
		}
}
