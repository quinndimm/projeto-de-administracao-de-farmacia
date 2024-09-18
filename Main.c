/*Incluindo as bibliotecas que seram usadas para esse programa*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include"Clientes.h"
#include"Endereco.h"
#include"Medicamento.h"
#include"Pedidos.h"

char op; /*Variavel global para capturar em qual gerencia o usuario quer entrar  */

void getch(){
    system("read b");
};

/*Declaração da função menu, que irá gerenciar o funcionamento do programa*/
void menu();

/*Função principal*/
int main(){
    FILE *arquivo; /*Declaração de um arquivo*/
    Med *medicamento; /*Declarando um ponteiro para a estrutura produto*/
    Cli *cliente; /*declarando um ponteiro para a estrutura cliente*/
    Ped *pedido; /*declarando um ponteiro para a estrutura pedido*/
    int contCliente=0, contMedicamento=0, contPedido=0; /*Inicializando os contadores em '0'*/

    /*Alocando memoria para os ponteiros*/
    medicamento = calloc(10, sizeof(Med));
    cliente = calloc(10, sizeof(Cli));
    pedido = calloc(10, sizeof(Ped));

    /*Chamada da função menu*/
    menu();


do{ /*Ciclo que ira controlar o funcionamento do programa*/
        switch(op){
             case 'C':
             case 'c':
                  gerenciaDeClientes(cliente, &contCliente, arquivo);
                  break;

             case 'P':
             case 'p':
                 gerenciaDeMedicamentos(medicamento, &contMedicamento, arquivo);
                 break;

             case 'E':
             case 'e':
                  gerenciaDePedidos(pedido, cliente, medicamento, &contPedido, &contCliente, &contMedicamento);
                  break;

             case 'S':
             case 's':
                  exit(1);

             default:
                  printf(" COMANDO INVALIDO!! \n Entre com o comando novamente.\n");
                  sleep(2);
                  system("clear");
                  menu();
        }

    }while (1);
     
     return 0;
    
} /*Fim da função principal*/

/*Código da função menu*/
void menu(){
     printf("Menu de Gerenciamento\n");
     printf("C - Gerenciar Clientes\n");
     printf("P - Gerenciar Medicamentos\n");
     printf("E - Gerenciar Pedidos\n");
     printf("S - Sair\n");
     printf("Digite um comando para proceguir: ");
     scanf("%c", &op);
     system("clear");
}