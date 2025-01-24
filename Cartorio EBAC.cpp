#include <stdio.h> //biblioteca de comunica��o com o us�ario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()//Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
    char arquivo [40];
	char cpf[40];
    char nome [40];
    char sobrenome[40];
    char cargo[40];
    //Final da cria��o de vari�veis/string

    
    printf("Digite o CPF a ser cadastrado:"); //coletando informa��es de CPF do usu�rio
    scanf("%s", cpf);//%s refere-se a strings
    
    strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salvo o valor da variavel
    fclose(file); //fecho o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o Nome a ser cadastrado:");//coletando informa��es do Nome do usu�rio
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o Sobrenome a ser cadastrado:");//coletando informa��es do Sobrenome do usu�rio
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o Cargo a ser cadastrado:");//coletando informa��es do Cargo do usu�rio
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}
int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF do Usu�rio a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo do Usu�rio, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	
	{
        printf("\nEssas s�o as Informa��es do Usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
    }
	
	system("pause");
    }

    int deletar()
    {
     char cpf[40];
     
     printf("Digite o CPF do usu�rio a ser deletado: ");
     scanf("%s", cpf);
     
     remove(cpf);
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
     {
     	printf("O Usu�rio n�o existe no nosso sistema!.\n");
     	system("pause");
	 }
	 
    }

    int main()
    {
	int opcao=0; //Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");//responsavel por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //Inicio do Menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n\n");
	    printf("\t4 - Sair do Sistema\n\n");//Final do Menu
        printf("Op��o: ");
	
	    scanf("%d", &opcao); //Armazenando a Escolha do usu�rio
	
	    system("cls");//responsavel por limpar a tela
	    
	    switch(opcao) //inicio da sele��o de menu
	    {
	    	case 1:
	        registro();//chamada de fun��es
	        break;
	        
	        case 2:
	        consultar();
            break;
            
            case 3:
            deletar();
	        break;
	        
	        case 4:
	        printf("Obrigado por utilizar o Sistema!\n");
	        return 0;
	        break;
	        
	        default:
	        printf("\t - Essa Op��o n�o est� disponivel!\n");
	        system("pause");
	        break;
	
		} //fim da sele��o
	   
    }
}
