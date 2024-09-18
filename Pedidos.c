#include"Clientes.h"
#include"Pedidos.h"
#include"Medicamento.h"

/*Estrutura do tipo pedido junto com as estruturas 'cliente' e 'medicamento' */
typedef struct{
    int codigo;
    int dia;
    int mes;
    int ano;
    Cli clienteQuePediu;
    Med *medicamentoPedido;
    int *qntMedicamentoPedido;
    int qnt;
}Ped;

     /*Codigo da função que gerencia as ações relacionada a pedidos*/
     void gerenciaDePedidos(Med *pedido, Cli *cliente, Med *medicamento, int *contPedido, int contCliente, int contMedicamento){
           char opcao;

           do{
              printf("GERENCIAR PEDIDOS\n");
              printf("C - Cadastrar um pedido\n");
              printf("L - Listartodos os pedidos de um cliente\n");
              printf("D - Listar todos os pedidos de um dia especifico\n");
              printf("\nDigite uma opção para prosseguir: ");
              scanf("%c",&opcao);
              system("clear");

              switch(opcao){
                     case "C":
                     case "c":
                          cadastrarPedido(pedido, cliente, medicamento, contPedido, contCliente, contMedicamento);
                          break;

                     case "L":
                     case "l":
                          listarPedidosDeUmCliente(pedido, contPedido);
                          break;

                     case "D":
                     case "d":
                          listarPedidosDeUmDia(pedido, contPedido);
                          break;

                     default:
                           printf("Opção Invalida!\nDigite novamente outra opção!\n");
                           sleep(2);
                           system("clear");
                           continue;

                         }
                         break;              
                    }
                    While(1);
               };

     /*Codigo da função que cadastra um pedido*/
     void cadastrarPedido(Ped *pedido, Cli *cliente, Med *medicamento, int *contPedido, int contCliente, int contMedicamento){
           char nomeCliente[30];
           int codigoCliente, marcado=0;
           int codigoDoMedicamentoParaCadastro;
           int qdtMedicamento;
           int i, j, auxindice=0;
           char opcao;

           printf("Cadastro de Pedidos\n");
           printf("Digite o codigo ou o nome do cliente que esta fazendo o pedido: ");
           scanf(" %[^\n]s", nomeCliente);

           codigoCliente = atoi(nomeCliente);  /*Convertendo a string em inteiro*/

           for(i=0; i<contCliente; i++){
               if(codigoCliente == cliente[i].codigo || strcmp(cliente[i].nome, nomeCliente) == 0{
                   pedido[*contPedido].clienteQuePediu = cliente[i];
                   marcador = 1;
                   break;
               }
           }
           }

           if(!marcador && strlen(nomeCliente) !>0){
                printf("\nERRO!\nCliente não encontrado\n");
                sleep(2);
                system("clear");
                menu();
                return;
               }

               printf("Digite a quatidade de medicamentos que deseja pedir: ");
               scanf(" %d", &pedido[*contPedido].qdt);

               pedido[*contPedido].medicamentoPedido = malloc(pedido[*coontPedido].qdt * sizeof(Ped));
               pedido[*contPedido].qdtMedicamento = malloc(pedido[*contPedido].qdt * sizeof(int));

               do{  /*Laço que captura o pedido do cliente*/
                    marcador = 0;
                    for(i=auxindice; i<pedido[*contPedido].qdt; i++) {
                         printf("Digite o codigo do medicamento para cadastro: ");
                         scanf("%d", &codigoMedicamentoParaCadastro);
                         for(j=0; j<contMedicamento; j++){
                              if(Medicamento[j].codigo == codigoMedicamentoParaCadastro){
                                  printf("Digite a quantidade para cadastro: ");
                                  scanf(" %d", &qdtMedicamento);
                                  pedido[*contPedido].medicamentoPedido[i] = medicamento[j];
                                  pedido[*contPedido].qdtProdutoPedido[i] = qdtProduto;
                                  marcador = 1;
                                  break;
                                 }
                                }
                              }
                         }
                         
                         if(!marcador){
                             printf("\nERRO!\nProduto não encontrado\n");
                             printf("O pedido sera descartado; o deseja digitar novamente outro codigo de produto s/n ");
                             scanf(" %c", &opcao);
                             auxindice = i;
                             system("cls");
                             break;

                         }
               While(opcao == 'S' || opcao == 's');

               if(opcao == 'N' || opcao == 'n'){
                   printf("Pedido não cadastrado\n");
                   sleep(2);

               }
               else {
                    obterData(&pedido[*contPedido]);
                    *contPedido +=1;
                    if(*contPedido == 10)
                         pedido = realloc(pedido, (*contPedido +1) * sizeof(Ped));

                    printf("\nPedido ccadastrado com sucesso\n");
                    sleep(2);
               };

               system("clear");
               menu();

     /*Função que usa a biblioteca 'time.h' para implementar data*/
     void obterData(Ped *pedido){
           time_t t = time(NULL);

           struct tm data = *localtime(&t);

           pedido->ano = data.tm_year + 1900;
           pedido->mes = data.tm_mon + 1;
           pedido->dia = data.tm_mday;
     }

    /*Função que lista os pedidos de um cliente*/
    void listarPedidosDeUmCliente(Ped *pedido, int contPedido){
         char nomeCliente[30];
         int codigoCliente;
         int i, marcador=0;

         printf("Digite o codigo ou o nome do cliente para visualizar seus pedidos: ");
         scanf(" %[^\n]s", nomeCliente);
         system("clear");

         codigoCliente = atoi(nomeCliente);

         for(i=0; i<contPedido; i++){
              if(pedido[i].clienteQuePediu.codigo == codigoCliente || strcmp(pedido[i].clienteQuePediu.nome, nomeCliente) == 0){
                  ordenarPedidosPorData(pedido, contPedido);
                  imprimirPedido(pedido[i]);
                  getch();
                  marcador = 1;
                  break;

              }
         }

         if(!marcador){
             printf("ERRO!\nNenhum pedido cadastrado para esse cliente\n");
             sleep(3);
         }
         
         system("clear");

         menu();
    };