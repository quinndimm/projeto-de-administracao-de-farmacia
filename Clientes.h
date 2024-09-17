

/*Estrutura do tipo cliente junto com a estrutura endereço */
typedef struct{
}Cli;

/*Código da função que gerencia os clientes*/
void gerenciaDeClientes(Cli*, int*, FILE*);

    /*Função que cadastra um cliente*/
     Cli cadastrarCliente(Cli*, int);

    /*Função que lista um cliente selecionado*/
     void listarCliente(Cli*, int);

        /*Função ira ordena os clientes em ordem alfabetica*/
          void ordenarClientePorOrdemAlfabetica(Cli*, int);

    /*Função que busca um cliente selecionado*/
    void buscarCliente(Cli*, int);

    /*Função que busca e atualiza os dados de um cliente*/    
    void atualizarCliente (Cli*, int);

    /*Função que exclui um cliente selecionado*/
    void excluirCliente(Cli*, int*);

    /*Função que imprime os dados de um cliente passado por parametro*/
    void imprimirCliente(Cli);