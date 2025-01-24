#include <stdio.h> //biblioteca de comunicação com o usúario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()//Função responsavel por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
    char arquivo [40];
	char cpf[40];
    char nome [40];
    char sobrenome[40];
    char cargo[40];
    //Final da criação de variáveis/string

    
    printf("Digite o CPF a ser cadastrado:"); //coletando informações de CPF do usuário
    scanf("%s", cpf);//%s refere-se a strings
    
    strcpy(arquivo, cpf); //responsável por copiar os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salvo o valor da variavel
    fclose(file); //fecho o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o Nome a ser cadastrado:");//coletando informações do Nome do usuário
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o Sobrenome a ser cadastrado:");//coletando informações do Sobrenome do usuário
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o Cargo a ser cadastrado:");//coletando informações do Cargo do usuário
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
	
	printf("Digite o CPF do Usuário a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo do Usuário, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	
	{
        printf("\nEssas são as Informações do Usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
    }
	
	system("pause");
    }

    int deletar()
    {
     char cpf[40];
     
     printf("Digite o CPF do usuário a ser deletado: ");
     scanf("%s", cpf);
     
     remove(cpf);
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
     {
     	printf("O Usuário não existe no nosso sistema!.\n");
     	system("pause");
	 }
	 
    }

    int main()
    {
	int opcao=0; //Definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
		system("cls");//responsavel por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //Inicio do Menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Deletar Nomes\n\n");
	    printf("\t4 - Sair do Sistema\n\n");//Final do Menu
        printf("Opção: ");
	
	    scanf("%d", &opcao); //Armazenando a Escolha do usuário
	
	    system("cls");//responsavel por limpar a tela
	    
	    switch(opcao) //inicio da seleção de menu
	    {
	    	case 1:
	        registro();//chamada de funções
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
	        printf("\t - Essa Opção não está disponivel!\n");
	        system("pause");
	        break;
	
		} //fim da seleção
	   
    }
}
