#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[15];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
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
			printf("CPF não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário solicitado: ");
		printf("%s", conteudo);
		printf("\n\n");
	
	}

	system("pause");
}

int deletar()
{
	printf("Deletar um usuário\n");
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
	
			printf("### Banco de Dados EBAC ###\n\n"); //Dando introdução ao programa //Fim do Menu
			printf("Escolha uma opção:\n\n"); //Solicitando escolha de uma opção
			printf("\t 1- Registrar Usuário\n");
			printf("\t 2- Consultar Usuário\n");
			printf("\t 3- Deletar Usuário\n\n\n"); 
			printf("\t 4- Sair do programa\n\n\n ");
			printf("Opção: ");//Fim, do menu
		
			scanf("%d",&opcao); //Captar informção dada após execução
		
			system("cls"); //Limpar prompt após captura
			
			switch(opcao) 
			{
				case 1: //Inicio Seleção
				registro();
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("\nObrigado por usar o cartório da EBAC\n");
				return 0;
				
				default:
				printf("Opção Inválida\n");
				system("pause");
				break;	//Fim Seleção
			
			}
			
		}
}
