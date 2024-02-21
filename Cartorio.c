#include <stdio.h> // biblioteca de comunica��o com usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h>// biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das strings


int registro()// fun��o respons�vel por cadastrar os usu�rios no sistema
{

	// inicio da cria��o das vari�veis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   	// final da cria��o das vari�veis/string
   	
   printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
   scanf("%s", cpf);//%s refere-se a armazenamento de string
   
   strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
   
   FILE *file; // cria arquivo
   file = fopen(arquivo, "w"); // cria arquivo e o "w" significa escrever
   fprintf(file,cpf); // salvo o valor da variavel
   fclose(file); // fecha o arquivo
   
   file=fopen(arquivo, "a"); //  abre o arquivo e "a " atualiza o arquivo
   fprintf(file, ",");
   fclose(file);// fecha o arquivo


   printf("Digite o nome a ser cadastrado: ");//coletando informa��o do usu�rio
   scanf("%s", nome);
   
   file = fopen(arquivo, "a");//  abre o arquivo e "a " atualiza o arquivo
   fprintf(file, nome);// salvo o valor da variavel
   fclose(file);// fecha o arquivo
   
   file = fopen(arquivo, "a"); //  abre o arquivo e "a " atualiza o arquivo
   fprintf(file, ",");
   fclose(file);// fecha o arquivo
   
   printf("Digite o sobrenome a ser cadastrado: ");//coletando informa��o do usu�rio
   scanf("%s", sobrenome);
   
   file = fopen(arquivo, "a");//  abre o arquivo e "a " atualiza o arquivo
   fprintf(file, sobrenome);// salvo o valor da variavel
   fclose(file);// fecha o arquivo
   
   file = fopen(arquivo, "a"); //  abre o arquivo e "a " atualiza o arquivo
   fprintf(file, ",");
   fclose(file);// fecha o arquivo
   
   printf("Digite o cargo a ser cadastrado: ");//coletando informa��o do usu�rio
   scanf("%s", cargo);
   
   file = fopen(arquivo, "a");//  abre o arquivo e "a " atualiza o arquivo
   fprintf(file,cargo);// salvo o valor da variavel
   fclose(file);// fecha o arquivo
   
   system("pause");
   
   
}

int consulta()// fun��o respons�vel por consultar os usu�rios cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	// inicio da cria��o das vari�veis/string para a fun��o consulta
	char cpf[40];
	char conteudo[200];
	// inicio da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser consultado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a armazenamento de string
	
	FILE *file;// cria arquivo
	file = fopen(cpf, "r");// abre arquivo e l� informa��o cadastrada
	
	if(file == NULL)//op��o caso usuario digite informa��es erradas
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");// mensagem a ser impressa caso informa��o dada pelo usu�rio seja incorreta
		
	}
	
	while(fgets(conteudo, 200, file)!= NULL)// encontra no arquivo as informa��es desejadas pelo usu�rio
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");//mensagem a ser impressa
		printf("%s", conteudo);// armazena a string
		printf("\n\n");
	}
	
	system("pause");//pausa no sistema
		
}

int deletar() // fun��o respons�vel por deletar os usu�rios cadastrados no sistema
{
     char cpf[40]; // cria��o da vari�vel
     
     printf("Digite o CPF do usu�rio a ser deletedado: ");//coletando informa��o do usu�rio
     scanf("%s", cpf);//armazenando string
     
     remove(cpf);//deletando o us�ario
     
     FILE *file;// criando arquivo
     file = fopen(cpf,"r");//abre arquivo e l�
     
     if(file == NULL) 
	{
     	printf("O usuario n�o se encontra no sistema!.\n"); //caso usuario n�o exista ou j� tenha sido deletado essa mensagem ser� impressa
     	system("pause");
	}
}


int main()
{
	
	int opcao=0; // Definindo as vari�veis
	
	int laco=1;
	
	for(laco=1; laco=1;)
	{

	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); // Definindo a Linguagem
	
	    printf("### Cart�rio da EBAC ### \n\n"); // inicio do menu
    	printf(" Escolher a op��o desejada do menu: \n\n");
	    printf("\t1- Registrar nomes \n");
	    printf("\t2- Consultar nomes \n");
    	printf("\t3- Deletar nomes \n\n"); 
    	printf("Op��o:"); // Fim do menu
	
	    scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
	    system("cls");//responsavel por limpar a tela
	    
	    switch (opcao)// inicio da sele��o do menu
	    {
	    	case 1:
	    	registro();// chamada de fun��es
		    break;
		    
		    case 2:
		    consulta();
	        break;
	        
	        case 3:
	        deletar();
		    break;
		    
		    default:
		    printf("Essa op��o n�o est� disponivel!\n");
	    	system("pause");
	    	break;
		    	
	    	
	    }// fim da sele��o
	 
    }  
}
