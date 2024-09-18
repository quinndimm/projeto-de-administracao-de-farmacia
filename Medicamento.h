/*Estrutura do tipo medicamento */
typedef struct{
}Med;

/*Declaração das funções que gerenciam as ações relacionadas aos medicamentos */
void gerenciaDeMedicamentos (Med*, int*, FILE*);


     Prod cadastrarMedicamento(Med, int);


     void listarMedicamentosCadastrados(Med, int);


          void ordenarMedicamentoPorNomme(Med, int);


          void filtrarCategoria();


     void buscarMedicamentoCadastrados(Med, int);


     void atualizarMedicamentoCadastrado(Med, int);


     void atualizarEstoqueMedicamento(Med, int);


     void imprimirMedicamento(Med);