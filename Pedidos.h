#include"Clientes.h"
#include"Medicamento.h"
#include"Endereco.h"

/*Estrutura do tipo pedido junto com as estruturas 'cliente' e 'medicamento' */
typedef struct{}Ped;

/*Codigo da função que gerencia as ações relacionada a pedidos*/
     void gerenciaDePedidos(Med *pedido, Cli *cliente, Med *medicamento, int *contPedido, int contCliente, int contProduto);

     /*Codigo da função que cadastra um pedido*/
     void cadastrarPedido(Ped *pedido, Cli *cliente, Med *medicamento, int *contPedido, int contCliente, int contMedicamento);

      /*Função que usa a biblioteca 'time.h' para implementar data*/
     void obterData(Ped *pedido);

      /*Função que lista os pedidos de um cliente*/
    void listarPedidosDeUmCliente(Ped *pedido, int contPedido);

    /*Código da função que ordena o pedido em data*/
    void ordenarPedidoPorData(Ped *pedido, int contPedido);

    /*Função que imprime o pedido*/
    void imprimirPedido(Ped pedido);

    /*Código da função da lista de pedidos feitos em uum dia*/
    void listarPedidosDeUmDia(Ped *pedido, int contPedido);

     /*Código da função que ordena os pedidos pelo nome dos clientes*/
     void ordenarPorNomeCliente(Ped *pedido, int contPedido);

