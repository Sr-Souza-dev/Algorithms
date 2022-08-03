#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>        //Biblioteca necessaria para o uso de booleanos

typedef struct lista List;
typedef struct node Node;
typedef struct datanode DataNode;

struct datanode{             //Local onde armazena os dados da lista, está estrutura fica dentro de Node que fica dentro de List
    int id;
};
struct node{                 //Struct que controla a sequencia dos elementos da lista, e conten a struct Dados
    DataNode data;
    struct node* next;
};
struct lista{                //Struct que controla o tamanho da lista e aponta qual é o primeiro elemento da lista
    int size;
    Node* head;
};

List* creatList(){                             //Criando uma lista
    List* list = (List*) malloc(sizeof(List));
    list->size = 0;                             //Como a lista acabou de ser criada, é necessario definir seu tamanho como 0 (Vazio)
    list->head = NULL;                          //É necessario definir o cabeçalho (1º elemento) como nulo também já que a lista começa vazia
    return list;
}
//----------------------------------------------------------------------------------------------------------------------------------------
void push(List* list, DataNode data)            //Adcionando elementos (insere sempre no começo)
{
    Node* node = (Node*) malloc(sizeof(Node));  //Criando um novo bloco para  a lista
    node->data = data;                          //Definido que o conteúdo deste bloco é igual ao conteúdo recebido na função
    node->next = list->head;                    //É como se estivesse apontando o 1º elemento para NULL pois o list->head é igual a NULL (Proxima posição vazia)
    list->head = node;                          //Definindo que o head(1º elemento) é agora este node que foi criado
    list->size++;                               //Incrementando no tamanho da lista para informar que ela agora não é mais vazia
}
//---------------------------------------------------------------------------------------------------------------------------------------
void printList(List *list)                      //Imprime todos os elementos da lista
{
    if(isEmpty(list))                         //Verifica se a lista está vazia
    {
        printf("Lista Vazia \n");
        return;
    }
    Node *pointer = list->head;                 //Cria um novo ponteiro, visto que se ele for alterado, não alterará o padrão da lista
    while(pointer != NULL)                      //Se a lista não for vazia vai entrar no laço
    {
        printf("%d\n",pointer->data.id);        //imprimindo o primeiro elemento da lista
        pointer=pointer->next;                  //definindo que agora meu pointer é meu proximo elemento da lista
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------
void pop(List *list)                            //Remove o primeiro elemento
{
    if(!isEmpty(list))                          //Verifica se a lista não está vazia
    {
        Node *pointer = list->head;             //Declara um ponteiro auxiliar para salvar o endereço que se quer remover
        list->head = pointer->next;             //Define que o head agora será o proximo elemento 
        free(pointer);                          //Libera a memória do que antes era o primeiro elemento
        list->size--;                           //Decrementa no tamanho da lista
    }

}
//---------------------------------------------------------------------------------------------------------------------------------------
bool isEmpty(List *list)                        //Verifica se a lista está vazia
{
    return (list->size == 0);
}
//---------------------------------------------------------------------------------------------------------------------------------------
Node* atPos(List *list, int index)              //Busca um elemento de acordo com o indice na lista
{
    if(index >=0 && index < list->size)         //Verifica se o indice passado é válido para está lista
    {
        Node *node = list->head;             //Cria o ponteiro auxiliar para que não haja alterações na lista
        for(int i = 0; i<index; i++)            //Faz um loop indo de 0 até index, sendo que respeita os indeces como se fosse vetor [0 = 1ºposição]
        {
            node = node->next;                    //Vai para o proximo elemento da lista até encontrar o desejado
        }
        return node;                            //Retorna o conteúdo do indice desejado
    }
    return NULL;
}
//---------------------------------------------------------------------------------------------------------------------------------------
int indexOf(List *list, Node *node)             //Buscando por um No (Bloco da lista)
{
    if(node != NULL)                           //Verificando se o No passado é valido
    {
        Node *pointer = list->head;             //Ponteiro auxiliar para não danificar a estrutura da lista
        int index=0;                            //Indice para nos dizer qual a posição do No procurado
        while(pointer != node && pointer != NULL)   //percorrendo a lista até encontrar o No, caso não pertença vai sair do laço
        {
            pointer = pointer->next;
            index++;
        }
        if(pointer != NULL)                     //Verifica se o No foi encontrado e retorna seu indice
        {
            return index;
        }
    }
    printf("No não encontrado nestá lista\n");
    return -1;                                 //Retorna -1 caso o No não seja encontrado
}
//---------------------------------------------------------------------------------------------------------------------------------------
void erase(List *list, int index)                   //Excluindo um elemento em qualquer posição da lista
{
    if(index==0)                                    //Verificando se é a primeira posição na lista
    {
        pop(list);
    }
    else
    {
        Node *pointer1 = atPos(list,index);         //Criando um ponteiro para a posição que deseja escluir
        if(pointer1 != NULL)                        //Se este item existir na lista 
        {
            Node *pointer2 = atPos(list,index-1);   //Criando um ponteiro para o elemento que vem antes do que você quer excluir
            pointer2->next = pointer1->next;        //Fazendo o item anterior da exclusão apontar para o proximo da exclusão
            free(pointer1);                         //Liberando o endereço que desejamos excluir
            list->size--;
        }
        
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------
void insert(List *list,DataNode data, int index)                //Adcionando em qualquer posição da lista
{
    if(index==0)                                                //Verificando se quer inserir no primeiro elemento 
    {
        push(list,data);                                        //Inserindo no primeiro elemento
    }
    else
    {
        Node *pointer1 = atPos(list,index);                     //Criando um ponteiro para a posição em que eu quero adcionar um novo item
        if(pointer1 != NULL)                                     //Se está posição existir
        {
            Node *pointer2 = atPos(list,index-1);               //Cria um ponteiro para posição anterior a que deseja inserir
            Node *newNode = (Node*) malloc(sizeof(Node));       //Aloca um novo espaço na memoria para o item
            newNode->data = data;                               //Define o conteúdo deste novo item
            pointer2->next = newNode;                           //Define que o próximo elemento do anterior ao index vai apontar agora para o novo item criado
            newNode->next = pointer1;                           //E que o proximo elemento do item criado vai apontar para o elemento que anteriormente ocupava o index 
            list->size++;
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------
void xchgNodes(List *list, Node *nodeA, Node *nodeB)           //Trocando dois blocos de lugares
{
    if(nodeA == nodeB)                                          //Verificando se os Blocos não são iguais
    {
        return;
    }
    int indexA = indexOf(list,nodeA);                           //Pegando o indice do primeiro elemento
    int indexB = indexOf(list,nodeB);                           //Pegando o indice do segundo elemento
    if(indexA<0 || indexB<0)                                    //Verificando se os elementos foram encontrados
    {
        return;
    }
    if(indexA > indexB)                                         //verificando se minha posição de A é maior do que a posição de B
    {                                                           //Isso é necesssario para não ter que considerar o A sendo head e o B sendo head, assim trocamos eles de lugar
        nodeA = nodeB;                                          //NodeA passa a ser o nodeB Fazendo assim que A seja menor que B
        nodeB = atPos(list,indexA);
        indexA = indexB;
        indexB = indexOf(list, nodeB);
    }
    Node *pb = atPos(list, indexB-1);                           //Criando um ponteiro para a posição anterior a B, já que agora ele nunca será o head
    if(nodeA == list->head)                                     //Verificando se meu NodeA é o head
    {
        list->head = nodeB;                                     //Caso seja o head, basta colocar o ponteiro head apontando para o NodeB
    }
    else{                                                       //Se o nodeA não for o head
        Node *pa = atPos(list, indexA-1);                       //Cria outro ponteiro para pegar o elemento anterior a nodeA
        pa->next = nodeB;                                       //Fazendo com que o proximo a este anterior a nodeA seja nodeB
    }
    pb->next = nodeA;                                           //Fazendo com que o proximo a este anterior a nodeB seja nodeA
    Node *pointer = nodeA->next;                                //cria um ponteiro que aponta para o proximo elemento a nodeA (para não perder a referencia)
    nodeA->next = nodeB->next;                                  //Define que o proximo elemento de NodeA será agora o proximo que era de NodeB
    nodeB->next = pointer;                                      //Define que o proximo elemento de NodeB será agora o proximo que era de NodeA
}
//----------------------------------------------------------------------------------------------------------------------------------------
Node* min(List *list, int index)                                //Retorna o menor elemento da lista
{
    Node* pointer = atPos(list, index);                         //Declara um ponteiro da primeira posição a ser buscada adiante
    if(pointer != NULL)                                         //Se o ponteiro for encontrado
    {
        Node* minNode = pointer;                                //Declara-se um ponteiro para manter o endereço do menor elemento (apontando agora para o 1º da comparação)
        while(pointer != NULL)                                  //Se o conteúdo de index recibido for encontrado (Ciclo)
        {
            if(pointer->data.id <minNode->data.id)              //Faz a comparação de menor valor
            {
                minNode = pointer;
            }
            pointer = pointer->next;                            //Faz o pointer percorrer a lista toda
        }
        return minNode;
    }
    return NULL;
}
//----------------------------------------------------------------------------------------------------------------------------------------
Node* max(List *list, int index)                                //Retorna o menor elemento da lista
{
     Node* pointer = atPos(list, index);                        //Declara um ponteiro da primeira posição a ser buscada adiante
    if(pointer != NULL)                                         //Se o ponteiro for encontrado
    {
        Node* maxNode = pointer;                                //Declara-se um ponteiro para manter o endereço do menor elemento (apontando agora para o 1º da comparação)
        while(pointer != NULL)                                  //Se o conteúdo de index recibido for encontrado (Ciclo)
        {
            if(pointer->data.id > maxNode->data.id)              //Faz a comparação de menor valor
            {
                maxNode = pointer;
            }
            pointer = pointer->next;                            //Faz o pointer percorrer a lista toda
        }
        return maxNode;
    }
    return NULL;
}
//----------------------------------------------------------------------------------------------------------------------------------------
void incShort(List *list)                                       //Ordenar em ordem crescente
{
    int i=0;
    for(i=0; i<list->size-1; i++)                               //Percorre o tamanho da lista -1
    {
        xchgNodes(list,atPos(list,i),min(list,i));              //troca os valores da posição atual da lista com o menor valor na lista a partir daquele ponto
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------
void decShort(List *list)                                       //Ordenar em ordem decrescente
{
    int i=0;
    for(i=0; i<list->size-1; i++)                               //Percorre o tamanho da lista -1
    {
        xchgNodes(list,atPos(list,i),max(list,i));              //troca os valores da posição atual da lista com o maior valor na lista a partir daquele ponto
    }
} 



int main() {
    List *list = creatList();
    
    DataNode data;
    data.id = 5;
    push(list, data);
    printf("%d \n", list->head->data.id);

    return 0;
}