#include <stdio.h> // Biblioteca de comunicação com usuario
#include <stdlib.h> // Biblioteca de alocação de espaço e memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca responsavel por cuidar das string

int registro() // função responsavel por cadastrar os usuários do sistema
{
	// Inicio da criação de variáveis/ String
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variáveis/ String
	
	printf("Digite o cpf a ser cadastrado:"); // Coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file= fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); // Salva o valor da variavel
	fclose(file); // Fecha o arquivo
	
	file= fopen(arquivo, "a");// cria o arquivo e o "A" significa atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" ,nome);
	
	file= fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadatrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
	
}


int consulta()
{
		setlocale(LC_ALL, "Portuguese"); // Definindo Linguagens
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("Não foi possivel abrir o arquivo, não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("Usuário deletado! O usuário não se encontra mais no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; // Definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		setlocale(LC_ALL, "Portuguese"); // Definindo Linguagens
	
		printf("###Cartório da EBAC###\n\n"); // Inicio do menu
		printf("escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("opcao:");  // Fim do menu
		printf("Esse Softare é de carlos henrique\n");
		
		scanf("%d", &opcao); // Armazenado escolha do usuário
	
		system("cls"); // responsavel por limpar a tela
		
		switch(opcao) // inicio da seleçao do menu
		{
			case 1:
		registro(); // chamada de funções
		break;
		
		case 2:
		consulta();	
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("Essa opção não está disponível!\n");
		system("pause");
		break;	
		}
		
	

	
	}

}
