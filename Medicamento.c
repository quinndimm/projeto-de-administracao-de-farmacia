#include"Medicamento.h"

/*Estrutura do tipo medicamento */
typedef struct{
    int codigo;
    char nome[30];
    char fornecedor[30];
    char categoria[30];
    int quantidade[30];
    float valorUnit;
}Med;

/*Codigo da função que gerencia as ações relacionadas aos produtos*/
     void gerenciaDeMedicamentos(Med *medicamento, int *contMedicamento, FILE *arquivo){
          char opcao;

          do{
               printf("GERENCIAR MEDICAMENTOS\n");
               printf("C - Cadastrar um medicamento\n");
               printf("L - Listar todos os medicamentos cadastrados\n");
               printf("B - Buscar medicamento já cadastrado\n");
               printf("A - Atualizar um medicamento cadastrado\n");
               printf("S - Atualizar estoque de um medicamento\n");
               printf("\nDigite uma opção para prosseguir: ");
               scanf(" %c%c", &opcao);
               system("clear");

               switch(opcao){
                    case "C":
                    case "c":
                         arquivo = fopen("Força de vendas.txt", "a+");
                         if(arquivo == NULL){
                              printf("Não foi possivel abrir o arquivo. ");
                              return;
                         }

                         printf("Cadastro de Medicamentos.\n");
                         medicamento[*contMedicamento] = cadastrarMedicamento(medicamento[*contMedicamento], 0);
                         
                         fprintf(arquivo," %d;%s;%s;%s;%d;%.2f\n", medicamento[*contMedicamento].codigo, medicamento[*contMedicamento].nome, medicamento[*contMedicamento].fornecedor, medicamento[*contMedicamento].categoria, medicamento[*contMedicamento].quantidade, medicamento[*contMedicamento].valorUnit);
                         fclose(arquivo);
                         
                         *contMedicamento +=1;
                         if(*contMedicamento == 10)
                              medicamento = realloc(medicamento, (*contMedicamento+1) * sizeof(Med));
                         break;
                    
                    case "L":
                    case "l":
                          listarMedicamentosCadastrados(medicamento, *contMedicamento);
                          break;
                          
                    case "B":
                    case "b":
                          buscarMedicamentoCadastrados(medicamento, *contMedicamento);
                          break;
                    
                    case "A":
                    case "a":
                           atualizarMedicamentoCadastrado(medicamento, *contMedicamento);
                           break;

                    case "S":
                    case "s":
                          atualizarEstoqueMedicameno(medicamento, *contMedicamento);
                          break;

                    default:
                          printf("OPÇÃO INVALIDA!\nDigite novamente outra opção!\n");
                          sleep(2);
                          system("clear");
                          continue;
                                   
          }
          break;   
     }
     while (1);
}

/*Codigo da função que cadastra um produto*/
void cadastrarMedicamento(Med medicamento, int identificador) {
     char aux[15];

     do{
          printf("Codigo do medicamento: ");
          scanf(" %10s", aux);
          medicamento.codigo = atoi(aux);
          if(identificador == 0) {
               if(medicamento.codigo == 0) {
                    printf("\nCODIGO INVALIDO!\nApenas numeros para codigo!\n");
                    sleep(2);
                    system("clear");
                    printf("Cadastro de Medicamentos\n");
                    continue;
               }
          }
          else{
               if(medicamento.codigo == 0 && strlen(aux) > 0){
                    printf("\nCODIGO INVALIDO!\nApenas numeros para codigo!\n");")
                    sleep(3);
                    system("clear");
                    printf("Cadastro de Medicamentos\n");
                    continue;
               }
          }
          break;
     }while (1);
     printf("Nome do medicamento: ");
     scanf(" %[^\n]s", medicamento.nome);
     printf("Fornecedor: ");
     scanf(" %[^\n]s", medicamento.fornecedor);
     printf("Categoria: ");
     scanf(" %[^\n]s", medicamento.categoria);
     if(identificador == 0){
         printf("Quantidade: ");
         scanf("%d", &medicamento.quant);
     }

     do{
        printf("Valor unitario: ");
        scanf("%s", aux);
        medicamento.valorUnit = atof(aux);
        if(identificador == 0) {
           if(medicamento.valorUnit == 0){
           printf("\nValor unitario invalido!\nApenas numeros para valor unitario!\n");
           sleep(3);
           system("clear");
           continue;
        }
     }
     else{
         if(medicamento.valorUnit == 0 && strlen(aux) > 0){
             printf("\nValor unitario invalidado!\nApenas numeros para valor unitario!\n");
           sleep(3);
           system("clear");
           continue;
         }
     }
     break;
}
while(1);
               }

if(identificador == 0){
       printf("\nMedicamento cadastrado com sucesso\n");
       sleep(2);
       system("clear");
       
       menu();
     }

     return medicamento;

/*Função que lista os medicamentos que estão cadastrados*/
void listarProdutosCadastrados(Med *medicamento, int contMedicamento);{
      char filtrar;
    };

/*Chamando função para ordenar medicamentos por nome*/
 ordenarMedicamentoPorNome(medicamento, contMedicamento)

printf("Deseja filtrar por categoria [s/n]\n");
scanf(" %c%c",&filtrar);

switch(filtrar){  /*Swith/case para verificar como o usuario deseja listar os medicamentos*/
     case "s":
     case "S":
          filtrarCategoria(medicamento, contMedicamento);
          break;
     case "n":
     case "N": {
           int i;
           printf("\n");
           if(contMedicamento > 0){
               for(i=0; i<contMedicamento; i++)
                   imprimirProduto(medicamento[i]);
               getch();
           };
           else{
                printf("\nERRO!\nNenhum cliente cadastrado\n");
                sleep(2);
           };
           break;

system("clear");

menu(); /*Chamando a função menu*/


/*Função que filtra a categoria do medicamento para imprimi-lo*/
void filtrarCategoria(Med *medicamento, int contMedicamento){
     int i, j=0, indiceMesmaCategoria[30];
     char categoria[30];

     printf("Deseja visualizar os medicamentos de qual categoria: ");
     scanf("%s", categoria);
     printf("\n");

     for(i=0; i<contMedicamento; i++){
          if(strcmp(medicamento[i].categoria, categoria) == 0)
             indiceMesmaCategoria[j++] = i;
}

if(!j){
   printf("\nERRO!\nCategoria não cadastrada\n");
   sleep(2);
}

else{
    for(i=0; i<j; i++)
        imprimirMedicamento(medicamento[indiceMesmaCategoria[i]]);
     getch();
    };

};

/*Função que ordena medicamentos por nome*/
void ordenarMedicamentoPorNome(Med *medicamento, int contMedicamento){
     int i, j, marcador;
     Med aux;

     for(i=1; i<contMedicamento; i++){
         aux = medicamento[i];
         j= i-1;

         do{
            marcador = 0;
            if(strcmp(medicamento[j].nome, aux.nome) > 0){
               medicamento[j+i] = medicamento[j];
               j--;
               marcador = 1;
         }
         
         if(j < 0)
             marcador = 0;
     
}while(marcador);

medicamento[j+1] = aux;

     };
};

/*Função que busca um medicamento cadastrado*/
void buscarMedicamentoCadastrado(Med *medicamento, int conMedicamento){
     int codigoMedicamento;
     char nomeMedicamento[30];
     int i, marcador = 0;

     printf("Digite o nome ou o codigo do medicamento que deseja buscar: ");
     scanf(" %[^\n]s", nomeMedicamento);
     printf("\n");

     codigoMedicamento = atoi(nomeMedicamento);

     for(i=0; i<contMedicamento; i++) { /*Laço que busca e imprime o medicamento solicitado pelo usuario*/
         if(medicamento[1].codigo == codigoMedicamento || strcmp(medicamento[i].nome, nomeMedicamento) == 0) {
            imprimirMedicamento(medicamento[i]);
            marcador=1;
            getch();
            break;
          };
     }
     
     if(!marcador) {
         printf("ERRO!\n produto não cadastrado\n");
         sleep(2);
     }

     system("clear");

     menu();  /*Chamando a função menu*/

     /*Função que imprime um medicamento*/
     void imprimirMedicamento(Med medicamento);{
          printf("Codigo: %d\n", medicamento.codigo);
          printf("Nome: %s\n", medicamento.nome);
          printf("Categoria: %s\n", medicamento.categoria);
          printf("fornecedor: %s\n", medicamento.fornecedor);
          printf("Quantidade: %d\n", medicamento.quantidade);
          printf("Valor unitario: %.2f\n\n", medicamento.valorUnidade);
        }
     }

     /*Função que atualiza um produto já cadastrado*/
     void atualizarMedicamentoCadastrado(Med *medicamento, int contMedicamento){
          Med aux;
          int i, marcado=0;

          printf("Digite o codigo do medicamento que deseja atualizar:");
          scanf(" %d", &aux.codigo);

          for(i=0; i<contMedicamento; i++){
              if(medicamento[i].codigo == aux.codigo){
                 marcador=1;
              };
          }

          if(!marcador)
             printf("\nERRO!\nMedicamento não cadastrado\n");
          
          else{
              printf("\nEntre com os dados atualizados\n");
              aux = cadastrarMedicamento(aux, -1);

              if(aux.codigo > 0)
                 medicamento[i].codigo = aux.codigo;

               if(strlen(aux.nome) > 0)
                  strcpy(medicamento[i].nome, aux.nome);

               if(strlen(aux.fornecedor) > 0)
                  strcpy(medicamento[i].fornecedor, aux.fornecedor);
               
               if(strlen(aux.categoria) > 0)
                  strcpy(medicamento[i].categoria, aux.categoria);
               
               if(strlen(aux.valorUnit) > 0)
                  strcpy(medicamento[i].valorUnit, aux.valorUnit);

               printf("\nProduto atualizado com sucesso!\n");

             };

          sleep(2);
          system("clear");

          menu();  /*Chamando a função menu*/
        };

     /*Função que atualiza o estoque de um medicamento*/
     void atualizarEstoqueMedicamento(Med *medicamento, int contMedicamento){
          int codigo, i, marcado=0;

          printf("Digite o codigo do medicamento que tera seu estoque atualizado: ");
          scanf("%d", &codigo);

          for(i=0; i<contMedicamento; i++){  /*Laço que busca e lê a nova quantidade em estoque*/
              if(medicamento[i].codigo == codigo){
                 printf("Digite estoque atualizado: ");
                 scanf("%d", &medicamento[i].quantidade);
                 marcador=1;
                 printf("\nEstoque atualizado com sucesso!\n");
                 break;
                };
            };

          if(!marcador)
              printf("\nERRO!\nMedicamento não cadastrado\n");
          

          sleep(2);
          system("clear");

          menu(); /*Chamada da função menu*/

         }
    
