#include <stdio.h> // biblioteca de comunicação com usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h>// biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings


int registro()// função responsável por cadastrar os usuários no sistema
{

	// inicio da criação das variáveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   	// final da criação das variáveis/string
   	
   printf("Digite o CPF a ser cadastrado: ");//coletando informação do usuário
   scanf("%s", cpf);//%s refere-se a armazenamento de string
   
   strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
   
   FILE *file; // cria arquivo
   file = fopen(arquivo, "w"); // cria arquivo e o "w" significa escrever
   fprintf(file,cpf); // salvo o valor da variavel
   fclose(file); // fecha o arquivo
   
   file=fopen(arquivo, "a"); //  abre o arquivo e "a " atualiza o arquivo
   fprintf(file, ",");
   fclose(file);// fecha o arquivo


   printf("Digite o nome a ser cadastrado: ");//coletando informação do usuário
   scanf("%s", nome);
   
   file = fopen(arquivo, "a");//  abre o arquivo e "a " atualiza o arquivo
   fprintf(file, nome);// salvo o valor da variavel
   fclose(file);// fecha o arquivo
   
   file = fopen(arquivo, "a"); //  abre o arquivo e "a " atualiza o arquivo
   fprintf(file, ",");
   fclose(file);// fecha o arquivo
   
   printf("Digite o sobrenome a ser cadastrado: ");//coletando informação do usuário
   scanf("%s", sobrenome);
   
   file = fopen(arquivo, "a");//  abre o arquivo e "a " atualiza o arquivo
   fprintf(file, sobrenome);// salvo o valor da variavel
   fclose(file);// fecha o arquivo
   
   file = fopen(arquivo, "a"); //  abre o arquivo e "a " atualiza o arquivo
   fprintf(file, ",");
   fclose(file);// fecha o arquivo
   
   printf("Digite o cargo a ser cadastrado: ");//coletando informação do usuário
   scanf("%s", cargo);
   
   file = fopen(arquivo, "a");//  abre o arquivo e "a " atualiza o arquivo
   fprintf(file,cargo);// salvo o valor da variavel
   fclose(file);// fecha o arquivo
   
   system("pause");
   
   
}

int consulta()// função responsável por consultar os usuários cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	// inicio da criação das variáveis/string para a função consulta
	char cpf[40];
	char conteudo[200];
	// inicio da criação das variáveis/string
	
	printf("Digite o CPF a ser consultado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a armazenamento de string
	
	FILE *file;// cria arquivo
	file = fopen(cpf, "r");// abre arquivo e lê informação cadastrada
	
	if(file == NULL)//opção caso usuario digite informações erradas
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");// mensagem a ser impressa caso informação dada pelo usuário seja incorreta
		
	}
	
	while(fgets(conteudo, 200, file)!= NULL)// encontra no arquivo as informações desejadas pelo usuário
	{
		printf("\nEssas são as informações do usuário: ");//mensagem a ser impressa
		printf("%s", conteudo);// armazena a string
		printf("\n\n");
	}
	
	system("pause");//pausa no sistema
		
}

int deletar() // função responsável por deletar os usuários cadastrados no sistema
{
     char cpf[40]; // criação da variável
     
     printf("Digite o CPF do usuário a ser deletedado: ");//coletando informação do usuário
     scanf("%s", cpf);//armazenando string
     
     remove(cpf);//deletando o usúario
     
     FILE *file;// criando arquivo
     file = fopen(cpf,"r");//abre arquivo e lê
     
     if(file == NULL) 
	{
     	printf("O usuario não se encontra no sistema!.\n"); //caso usuario não exista ou já tenha sido deletado essa mensagem será impressa
     	system("pause");
	}
}


int main()
{
	
	int opcao=0; // Definindo as variáveis
	
	int laco=1;
	
	for(laco=1; laco=1;)
	{

	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	    printf("### Cartório da EBAC ### \n\n"); // inicio do menu
    	printf(" Escolher a opção desejada do menu: \n\n");
	    printf("\t1- Registrar nomes \n");
	    printf("\t2- Consultar nomes \n");
    	printf("\t3- Deletar nomes \n\n"); 
    	printf("Opção:"); // Fim do menu
	
	    scanf("%d", &opcao); // Armazenando a escolha do usuário
	
	    system("cls");//responsavel por limpar a tela
	    
	    switch (opcao)// inicio da seleção do menu
	    {
	    	case 1:
	    	registro();// chamada de funções
		    break;
		    
		    case 2:
		    consulta();
	        break;
	        
	        case 3:
	        deletar();
		    break;
		    
		    default:
		    printf("Essa opção não está disponivel!\n");
	    	system("pause");
	    	break;
		    	
	    	
	    }// fim da seleção
	 
    }  
}
