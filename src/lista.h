#ifndef _PARADIGMAS_T1_LISTA_H_
#define _PARADIGMAS_T1_LISTA_H_

/**
 * Você deve definir a estrutura da lista utilizando as duas estruturas
 * abaixo. Você pode alterá-las com preferir.
 */


typedef struct _lista_nodo {
    void* valor;
    struct _lista_nodo* next;
    struct _lista_nodo* prev;
} ListaNodo;

typedef struct {
    ListaNodo* head;
    ListaNodo* tail;
    ListaNodo* cursor;
    int size;
    int data_size;
    void (*free_data)(void*);
} Lista;


/**
 * Tarefas obrigatórias
 *
 * Implementar uma lista com encadeamento simples que funciona como
 * um iterador sobre sim mesma.
 *
 * A implementação deveria seguir a ordem em que as funções estão
 * definidas neste arquivo, pois as mesmas funções são utilizadas
 * nos testes automatizados, e são testadas nesta ordem.
 *
 * Você NÃO pode alterar a arquivo a partir deste ponto!
 */

/**
 * Inicializa a estrutura da lista.
 * Por exemplo, para criar uma lista de inteiros (int), é preciso definir
 * o tamanho do tipo de dados, mas não é preciso definir uma função para
 * liberar memória, uma vez que os dados não são ponteiros:
 *
 *    Lista_new(&intlist, sizeof(int), NULL);
 * 
 * De forma semelhante, uma lista de `double` também não precisa de uma
 * função para liberar memória, mas precisa utilizar o tamanho correto
 * para os dados:
 *
 *    Lista_new(&doublelist, sizeof(double), NULL);
 *
 * Já uma lista de 'strings', ou seja, de `char*`, precisa de uma função
 * para liberar o espaço alocado para os dados:
 *
 *    Listal_new(&strlist, sizeof(char*), free);
 */
void Lista_new(Lista* lista, int data_size, void (*free_data)(void*));

/**
 * Libera memória utilizada pela lista, e a reinicializa.
 */
void Lista_delete(Lista* lista);

/**
 * Retorna 0 (zero) casa o lista possua elementos, e 1 se estiver vazia.
 */
int Lista_isEmpty(Lista* lista);

/**
 * Retorna o número de elementos armazenados na lista.
 */
int Lista_size(Lista* lista);

/**
 * Insere um novo valor no início da lista.
 */
void Lista_pushFront(Lista* lista, void* valor);

/**
 * Insere um novo valor no final da lista.
 */
void Lista_pushBack(Lista* lista, void* valor);

/**
 * Procura na lista por um elemento associado com a chave.
 *
 * Por exemplo, para procura em uma lista de inteiros, é necessário
 * criar uma função de comparação de inteiros, como
 * 
 *     int int_cmp(const void *lhs, const void* rhs);
 *
 * que retorna um valor maior que 0 (zero), se 'lhs' representa um
 * valor maior que 'rhs', 0 (zero) se os valores forem iguais e um
 * valor menor que zero se 'lhs' representa um valor menor que 'rhs'.
 *
 * A função retorna 0 (falso) se não encontrou um valor, e um valor
 * diferente de zero (true) se o valor foi encontrado.
 */
int Lista_search(
    Lista* lista,
    void* chave,
    void* dest,
    int (*cmp)(void*,void*)
);

/**
 * Procura na lista pelo primeiro elemento com o valor da 'chave' dada e
 * o remove da lista.
 */
void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*,void*)
);

/**
 * Ajusta o 'elemento atual' da lista para o primeiro elemento.
 */
void Lista_first(Lista* lista);

/**
 * Ajusta o 'elemento atual' da lista para o último elemento.
 */
void Lista_last(Lista* lista);

/**
 * Ajusta o 'elemento atual' da lista para próximo elemento.
 * 
 * A função retorna 0 (falso) se não existe um próximo elemento,
 * e um valor diferente de zero (true) se existe.
 */
int Lista_next(Lista* lista);

/**
 * Retorna o valor do 'elemento atual' em 'dest'.
 */
void Lista_current(Lista* lista, void* dest);

/**
 * Insere um novo elemento na lista após o 'elemento atual'.
 */
void Lista_insertAfter(Lista* lista, void* dado);

/**********
 * Tarefas opcionais.
 *
 * Implementar uma lista duplamente encadeada.
 */

/**
 * Remove o 'elemento atual' da lista.
 */
void Lista_removeCurrent(Lista* lista);

/**
 * Ajusta o 'elemento atual' da lista para elemento anterior.
 * 
 * A função retorna 0 (falso) se não existe um elemento anterior,
 *  e um valor diferente de zero (true) se existe.
 */
int Lista_previous(Lista* lista);

/**
 * Insere um novo elemento no lista antes do 'elemento atual'.
 */
void Lista_insertBefore(Lista* lista, void* dado);

#endif /* _PARADIGMAS_T1_LISTA_H_ */
