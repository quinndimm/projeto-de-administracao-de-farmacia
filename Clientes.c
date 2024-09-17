#include"Clientes.h"
#include"Endereco.h"

/*Estrutura do tipo cliente junto com a estrutura endereço */
typedef struct{
    int codigo;
    char nome[30];
    char cnpj[20], cpfj[20];
    char telefone[10];
    end endereço;
}Cli;

void gerenciaDeClientes(Cli *cliente, int *contCliente, FILE *arquivo){
     char opção;

     do{
          printf("Gerenciar Clientes\n");
          printf("C -Cadastrar Cliente\n");
          printf("L - Listar clientes cadastrados\n");
          printf("B - Buscar cliente cadastrado\n");
          printf("A - Atualizar cliente cadastrado\n");
          printf("E - Excluir cliente cadatrado\n");
          printf("\n Digite uma opção para prosseguir: ");
          scanf("%c",&opção);
          system("clear");

          switch (opção)
          {
          case 'C':
          case 'c':
                arquivo = fopen("Força de Vendas.txt", "a+");
                if(arquivo == NULL) {
                    printf("Não foi possivel abrir o arquivo.");
                    return;
               }

               printf("Cadastro de Cliente\n");
               fprintf(arquivo, "%d;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;\n", cliente[*contCliente].codigo, cliente[*contCliente].nome, cliente[*contCliente].cnpj, cliente[*contCliente].cpf, cliente[*contCliente].telefone, cliente[*contCliente].endereço.logradouro,cliente[*contCliente].endereço.complemento,cliente[*contCliente].endereço.cep, cliente[*contCliente].endereço.bairro,cliente[*contCliente].endereço.cidade, cliente[*contCliente].endereço.estado);
               fclose(arquivo);

               *contCliente+=1;
               if(*contCliente == 10)
                  cliente = realloc(cliente, (*contCliente + 1) *sizeof(Cli));
               break;

            case 'L':
            case 'l':
               listarCliente(cliente, *contCliente);
               break;

            case 'B':
            case 'b':
               buscarCliente(cliente, *contCliente);
               break;

            case 'A':
            case 'a':
               atualizarCliente(cliente, *contCliente);
               break;

            case 'E':
            case 'e':
               excluirCliente(cliente, *contCliente);
               break;

          default:
               printf("OPÇÃO INVALIDA!\nDigite novamente outra opção\n");
               sleep(2);
               system("clear");
               continue;
          }break;
     }while (1);
     
}

/*Função que cadastra um cliente*/
Cli cadastrarCliente(Cli cliente, int identificador){
     char opção;
     char codigoCliente[10];

     do
     {
      printf("Codigo cliente: ");
      scanf("%s", codigoCliente);
      
      cliente.codigo = atoi(codigoCliente);
      if (identificador == 0)
      {
          printf("\nCODIGO INVALIDO!\nApenas números para o codigo\n");
          sleep(2);
          system("clear");
          printf("Cadastro de Clientes\n");
          continue;
      }
      
     }
     else(
          if(cliente.codigo == 0 && strlen(codigoCliente) > 0)(
               printf("CODIGO INVALIDO!\nApenas números no codigo\n");
               sleep(2);
               system("clear");
               continue;
          )
     )
     break;
}while (1);
{
     printf("Nome do cliente: ");
     scanf("%[^\n]s", cliente.nome);
     do(
          printf("Pessoa: Fisica(F) , Juridica(J):");
          scanf("%c", &opção);
          switch (opção) { /*Switch/case para determinar qual identificação pegar do usuario*/
                case 'F':
                case 'f':
                     printf("CPF do clinte:");
                     scanf("%[^\n]s", cliente.cpf);
               break;
          
               case 'J':
                case 'j':
                     printf("CNPJ do clinte:");
                     scanf("%[^\n]s", cliente.cnpj);
               break;


          default:
                   printf("\n  ATENÇÃO!\n Digite (F) para pessoa Fisica ou (J) para pessoa Juridica\n\n");
               continue;
          }
          break;
     )
}
while (1);
{
  printf("Telefone do cliente: ");
  scanf("%[^\n]s", cliente.telefone);
  printf("\nEndereço do Cliente\n");
  printf("Logradouro: ");
  scanf("%[^\n]s", cliente.endereço.logradouro);
  printf("Complemento: ");
  scanf("%[^\n]s", cliente.endereço.complemento);
  printf("CEP: ");
  scanf("%[^\n]s", cliente.endereço.cep);
  printf("Bairro: ");
  scanf("%[^\n]s", cliente.endereço.bairro);
  printf("Cidade: ");
  scanf("%[^\n]s", cliente.endereço.cidade);
  printf("Estado: ");
  scanf("%[^\n]s", cliente.endereço.estado);

  if(indentificador == 0){
     printf("\nCADASTRO REALIZADO COM SUCEESSO!\n");
     sleep(2);
     system("clear");
     menu();
  }
  return cliente;
}

/*Função que lista um cliente selecionado*/
void listarCliente(Cli *cliente, int contCliente){
     int i;

     if(contCliente == 0){
          printf("ERRO!\nNENHUM CLIENTE CADASTRADO\n");
          sleep(2);
          system("clear");
          menu();
          return;
     }
}

/*Função ira ordena os clientes em ordem alfabetica*/
ordenarClientePorOrdemAlfabetica(Cli *cliente, contCliente){

printf("LISTA DE CLIENTES CADASTRADOS\n\n");
for(i<constClient;i++) /*Ciclo que procura e imprime um cliente */
imprimirCliente(cliente[i]);

getch();
system("clear");
menu(); /*Chamando a função menu ao final da função listarCliente*/

}

/*Código da função que ordena os clientes em ordem alfabetica*/
void ordenarClientePorOrdemAlfabetica(Cli *cliente, int contCliente){
     int i;j, maracdor;
     Cli aux;

     for(i=1; i<contCliente; i++){
          aux = cliente[i];
          j = i-1;
          do{
               marcador = 0;
               if(strcmp(cliente[j].nome, aux.nome)>0){
                    cliente[j+1] = cliente[j];
                    j--;
                    marcador = 1;
          }
          if(j<0)
               marcador = 0;
}while (marcador);
{
     cliente[j+1] = aux;/* code */
}

/*Função que imprime os dados de um cliente passado por parametro*/
void imprimirCliente(Cli client){
     printf("Codigo: %d\n", cliente.codigo);
     printf("Nome: %s\n", cliente.nome);
     if(strlen(cliente.cnpj) == 0);
         printf("CPF: %s\n, cliente.cpf");
     else
         printf("CNPJ: %s\n", cliente.cnpj);
         printf("Telefone: %s\n", cliente.telefone);
         printf("Endereço: Logradouro %s / Complemento %s\n", cliente.endereço.logradouro, cliente.endereço.complemento);
         printf("CEP: %s\n", cliente.endee.cep);
         printf("Bairro: %s\n", cliente.endereço.bairro);
         printf("Cidade: %s\n", cliente.endereço.cidade);
         printf("Estado: %s\n", cliente.endereço.estado);

}

/*Função que busca um cliente selecionado*/
void buscarCliente(Cli *cliente, int contCliente){
   void buscarCliente(Cli *cliente, int contCliente){
     int 1, marcador=0;
     int codigoCliente;
     char nomeCliente[30];

     printf("Digite o nome ou o codigo do cliente que deseja buscar: ");
     scanf(" %[^\n]s", nomeCliente);
     printf("\n");
     codigoCliente = atoi(nomeCliente);

     for(i=0; i<contCliente; i++){
          if(cliente[i].codigo == codigoCliente || strcmp(cliente[i].nome, nomeCliente) == 0){
               imprimirCliente(cliente[i]);
               getch();
               marcador = 1;
               break;
          }    
     }    
       if(marcador){
          printf("ERRO!!\nCliente não cadastrado\n");
          sleep(2);
       }

       system("clear");

       menu(); /*Chamando a função menu depois de ter buscado um cliente*/

}

/*Função que busca e atualiza os dados de um cliente*/
void atualizarCliente(Cli *cliente, int contCliente){
         int codigo, i, marcador = 0;
     Cli aux;
     char codigoCliente[10];

     do{
          printf("Codigo do cliente que deseja atualizar: ");
          scanf(" %s", codigoCliente);

          codigo = atoi(codigoCliente);
          if(codigo == 0){
               printf("\n ERRO!\nApenas numeros para o codigo\n");
               sleep(2);
               system("clear");
               continue;
          }
          break;
     }while (1);
     
     for(i=0; i<contCliente; i++){
          if(cliente[i].codigo == codigo){
               marcador = 1;
               break;
          }
     }
     
     if(!marcador)
          printf("\n ERRO!\nCliente não cadastrado\n");

     else{
          printf("\nEntre com os dados atualizados\n");
          aux = cadastrarCliente(aux, -1);

          if(aux.codigo > 0)
              cliente[i].codigo = aux.codigo;
          if(strlen(aux.nome) > 0)
              strcpy(cliente[i].nome, aux.nome);
          if(strlen(aux.cpfj) > 0)
              strcpy(cliente[i].cpf, aux.cpfj);
          if(strlen(aux.cnpj) > 0)
              strcpy(cliente[i].cnpj, aux.cnpj);
          if(strlen(aux.telefone) > 0)
              strcpy(cliente[i].telefone, aux.telefone);
          if(strlen(aux.endereço.logradouro) > 0)
              strcpy(cliente[i].endereço.logradouro, aux.endereço.logradouro);
          if(strlen(aux.endereço.complemento) > 0)
              strcpy(cliente[i].endereço.complemento, aux.endereço.complemento);
          if(strlen(aux.endereço.cep) > 0)
              strcpy(cliente[i].endereço.cep, aux.endereço.cep);
          if(strlen(aux.endereço.bairro) > 0)
              strcpy(cliente[i].endereço.bairro, aux.endereço.bairro);
          if(strlen(aux.endereço.cidade) > 0)
              strcpy(cliente[i].endereço.cidade, aux.endereço.cidade);
          if(strlen(aux.endereço.estado) > 0)
              strcpy(cliente[i].endereço.estado, aux.endereço.estado);

          printf("\nCliente atualizado com sucesso\n");

     }

     sleep(2);
     system("clear");

     menu(); /*Chamando a função manu ao final da função atualizarCliente*/


}

/*Função que exclui um cliente selecionado*/
void excluirCliente(Cli *cliente, int *contCliente){
     int codigo, i, marcador=0;

     printf("Codigo de cliente que deseja excluir: ");
     scanf("%d",&codigo);

     for(i=0; i<*contCliente; i++){  /*Laço que verifica se o cliente existe*/
         if(cliente->codigo == codigo){
             marcador = 1;
             break;
         }
     }

     if(!marcador)
         printf("\n ERRO!\nCliente não cadastrado\n");
     
     else{  /*Se existir, o cliente será sobrescrito e será excluido*/
         for(i; i<*contCliente; i++)
            cliente[i] = cliente[i+i];

          *contCliente -=1;
          printf("\nCliente excluido com sucesso\n");
     }

     sleep(2);
     system("clear");

     menu()  /*chamando a função menu ao final da função excluirCliente*/
