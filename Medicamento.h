
/*Estrutura do tipo medicamento */
typedef struct{
}Med;

     /*Codigo da função que gerencia as ações relacionadas aos produtos*/
     void gerenciaDeMedicamentos(Med *medicamento, int *contMedicamento, FILE *arquivo)

     void cadastrarMedicamento(Med medicamento, int identificador)

     /*Função que lista os medicamentos que estão cadastrados*/
void listarProdutosCadastrados(Med *medicamento, int contMedicamento)

/*Chamando função para ordenar medicamentos por nome*/
 ordenarMedicamentoPorNome(medicamento, contMedicamento)

 /*Função que filtra a categoria do medicamento para imprimi-lo*/
void filtrarCategoria(Med *medicamento, int contMedicamento)

/*Função que ordena medicamentos por nome*/
void ordenarMedicamentoPorNome(Med *medicamento, int contMedicamento)

/*Função que busca um medicamento cadastrado*/
void buscarMedicamentoCadastrado(Med *medicamento, int conMedicamento)

/*Função que imprime um medicamento*/
     void imprimirMedicamento(Med medicamento)

     /*Função que atualiza um produto já cadastrado*/
     void atualizarMedicamentoCadastrado(Med *medicamento, int contMedicamento)

     /*Função que atualiza o estoque de um medicamento*/
     void atualizarEstoqueMedicamento(Med *medicamento, int contMedicamento)