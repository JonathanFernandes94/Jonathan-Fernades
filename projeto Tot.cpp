#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct pedido
{
    char namePed[50];
    char CPF[50];
    char numPed[50];
    char qtdPed[50];
    char valorped[50];
    int cod;
}logP[50];

struct cadastro
{
    char CPF[50];
    char telefone[50];
    char nome[50];
    char endereco[50];
    char data[50];
    int vazio,cod;
    struct pedido clientePed;
   
}log[50];

int verifica_pos(void);
int verifica_cod( int cod );
int opt;
void cadastroP(int cod,int pos);
void list();
void cadastroPedido();
void consultaCod (void);
void excluirCliente (void);
int main(void){ 

    int i,Opcao,OpcaoCliente,posicao,retorno;
    int codaux;
    do
    {
        printf("1 - Cadastrar Novo Cliente\n");
        printf("2 - Cliente\n");
        printf("3 - Alterar Cliente\n");
        printf("4 - Excluir Cliente\n");
        printf("5 - Pedido\n");
        printf("6 - Alterar Pedido\n");
        printf("7 - forma de pagamento\n");
        printf("8 - Excluir Pedido\n");
        printf("9 - confirmacao\n");
        printf("10 - numero do pedido\n");
        printf("11 - Sair\n");
        printf(" Selecione uma opcao por favor: ");
        scanf("%d", &Opcao);
        getchar();
        if (Opcao == 1)
        {
            printf("Voce selecionou a opcao 1 - Cadastrar Novo Cliente\n");
            posicao=verifica_pos();

                if ( posicao != -1 )
                {

                    printf("\nEntre com um codigo de 1 a 200 para seu cadastro: \n");
                    scanf("%d",&codaux);fflush(stdin);

                    retorno = verifica_cod( codaux );

                    if ( retorno == 1 )
                        cadastroP( codaux, posicao );
                    else{
                        printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
                        getchar();
                        system("cls");
                        main();
                    }

                }
                else
                    printf("\nNao e possivel realizar mais cadastros!\n");

                break;
 
        }
        else if (Opcao == 2)
        {
            system("cls");
            do{
            printf("Voce selecionou a opcao 2 - Clientes\n\n");
            printf("1 - Pesquisar cliente por codigo\n");
            printf("2 - Listar todos os clientes\n");
            printf("3 - Voltar ao menu principal\n");
            printf("Selecione uma opcao por favor: ");
            scanf("%d", &OpcaoCliente);
            getchar();
                 if(OpcaoCliente == 1){
                    consultaCod();
                }
                else if(OpcaoCliente == 2){
                    list();
                }
                else if(OpcaoCliente == 3){
                    printf("Voce selecionou voltar ao menu principal, pressione ENTER para continuar");
                    getchar();
                    system("cls");
                }
                else
                    printf("Opcao Invalida\n\n");
    }while(OpcaoCliente =!3 || OpcaoCliente > 3 || OpcaoCliente < 0 || OpcaoCliente == 0);
        }
        else if (Opcao == 3)
        {
            printf("Voce selecionou a opcao 3 - Alterar Cliente\n");
        }
        else if (Opcao == 4)
        {
            printf("Voce selecionou a opcao 4 - Excluir Cliente\n");
            excluirCliente();
        }
        else if (Opcao == 5)
        {
            printf("Voce selecionou a opcao 5 -Pedido\n");
            cadastroPedido();
        }
        else if (Opcao == 6)
        {
            printf("Voce selecionou a opcao 6 - Alterar Pedido\n");
        }
        else if (Opcao == 7)
        {
            printf("Voce selecionou a opcao 7 - forma de pagamento\n");
        }
        else if (Opcao == 8)
        {
            printf("Voce selecionou a opcao 9 - Excluir Pedido\n");
        }
        else if (Opcao == 9)
        {
            printf("Voce selecionou a opcao 10 -confirmacao\n");
        }
        else if (Opcao == 10)
        {
            printf("Voce selecionou a opcao 10- numero do pedido\n");
        }
        else if (Opcao == 11)
        {
            printf("Voce selecionou a opcao 11 - Sair\n");
        }
        else{
            printf("Opcao invalida, favor pressione enter para voltar ao menu principal");
            getchar();
            system("cls");
        }
        }    while (Opcao != 8 || Opcao < 8);

} 
void list(){ 
    int i,j;  
    for(i=0;i<50;i++){
        if(log[i].cod!=NULL){
            printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", log[i].cod,log[i].nome,log[i].CPF,log[i].endereco,log[i].telefone);
    }
}
    printf("Pressione enter para volta ao menu principal");
    getchar();
    system("cls");

} 
void cadastroP(int cod, int pos){ 
    int i;
    do{
    pos = verifica_pos();
    log[pos].cod = cod;
        printf("\nDigite seu nome: ");
        gets(log[pos].nome);
        printf("\nDigite seu CPF: ");
        gets(log[pos].CPF);
        printf("\nDigite seu Telefone: ");
        gets(log[pos].telefone);
        log[pos].vazio = 1;
       
        opt ==1;
        getchar();  
    }while(opt==1);
    system("cls");
    main();

} 
int verifica_pos( void ) 
{
    int cont = 0;

    while ( cont <= 50 )
    {

        if ( log[cont].vazio == 0 )
            return(cont);

        cont++;

    }

    return(-1);

} 
int verifica_cod( int cod ) 
{
    int cont = 0;

    while ( cont <= 50 )
    {
        if ( log[cont].cod == cod )
            return(0);

        cont++;
    }

    return(1);

} 
void cadastroPedido(){ 
    system("cls");    
    int i;
    int Option;
    int OpcaoPedido;
    char nomeCad[50];
    printf("\nDigite seu nome como esta no cadastro: ");
    gets(nomeCad);
    for(i=0;i<50;i++){
            if(strcmp(log[i].nome, nomeCad)==0){
                do{
                printf("\nEscolha o seu pedido: "); //PEDIDOS MERAMENTE ILUSTRATIVOS, COLOQUEI SÓ PARA VER SE CONSEGUIA ANEXAR A 1 CADATRO MAS NÃO CONSEGUI.
                printf("\n1- big mac");
                printf("\n2- big tasty");
                printf("\n3- mctastico:");
                scanf("%d", &OpcaoPedido);
                if(OpcaoPedido == 1){
                    strcpy(log[i].clientePed.namePed, "big mac");
                    printf("\nVoce escolheu %s, seu pedido foi adicionado .",log[i].clientePed.namePed);
                    printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    printf("\nPressione 1 para confirmar pedido -- pedido confirmado: ");
                    scanf("%d", &Option);
                    i++;
                }
                else if(OpcaoPedido == 2){
                    strcpy(log[i].clientePed.namePed, "big tasty");
                    printf("\nVoce escolheu %s, seu pedido foi adicionado .", log[i].clientePed.namePed);
                    printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    printf("\nPressione 1 para confirmar pedido -- pedido confirmado: ");
                    scanf("%d", &Option);
                    i++;
                   }
                   else if(OpcaoPedido == 3){
                    strcpy(log[i].clientePed.namePed, "mctastico");
                    printf("\nVoce escolheu %s, seu pedido foi adicionado ", log[i].clientePed.namePed);
                    printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    printf("\nPressione 1 para confirmar pedido -- pedido confirmado: ");
                    scanf("%d", &Option);
                    i++;
                }
    }while(Option == 1);
    system("cls");

   
}
}
} 
void consultaCod (void) 
{
    int cont = 0, cod;

    printf("\nEntre com o codigo\n");
    scanf("%d",&cod);
    fflush(stdin);
    system("cls");

    while ( cont <= 50 )
    {

        if (log[cont].cod==cod)
        {
            if (log[cont].vazio==1)
            {
               
                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", log[cont].cod,log[cont].nome,log[cont].CPF,log[cont].endereco,log[cont].telefone);
               

                system ("pause");

                system("cls");

                break;

            }
        }

        cont++;

        if ( cont > 50 ){
            printf("\nCodigo nao encontrado, pressione enter para volar ao menu principal\n");
            getchar();
            system("cls");
        }

    }
} 
void excluirCliente(void)  
{
    int cod, cont = 0;
    char resp;
    printf("\nEntre com usuario do registro que deseja excluir: \n");
    scanf("%d", &cod );

    while ( cont <= 50 )
    {

        if ( log[cont].cod == cod )
        {

            if (log[cont].vazio == 1 )
            {
                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", log[cont].cod,log[cont].nome,log[cont].CPF,log[cont].endereco,log[cont].telefone);
                getchar();
                printf("\nDeseja realmente exlucir? s/n: ");
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    log[cont].vazio=0;
                    log[cont].cod = NULL;
                    printf("\nExclusao feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 50 )
            printf("\nCodigo nao encontrado\n");

    }

    system("pause");
    system("cls");

}
