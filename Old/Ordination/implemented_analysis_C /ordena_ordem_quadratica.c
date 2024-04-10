#include <stdlib.h>
#include <stdio.h>


//--------------------------------Tratando do vetor a ser ordenado----------------------------------------
typedef struct vetor vetor;                 //struct do vetor
struct vetor{
    int *vet;
    int *beckup;
    int count;
};

void iniciarVet(vetor *v, int n)            //Alocando espaços de memória para o ponteiro
{
    v->vet = (int*) malloc(n*sizeof(int));
    v->beckup =  (int*) malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        v->vet[i] = rand()%100;             //Definindo valores aleatórios para o vetor
        v->beckup[i] = v->vet[i];
    }
    v->count = 0;
}
//Função que faz a troca de dois elementos do vetor
void swap(int *v1, int *v2)
{
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

//Função imprimir generalista
void imprimir(vetor *v, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d\t", v->vet[i]);
    }
    printf("\n");
}
//----------------------------------------FIM de configurações do vetor------------------------------------


//Metodo de ordenação da bolha (bubble sort) (Leva o maior elemento sempre para ultima posição do vetor) (Metodo recursivo)
void bubbleSort(vetor *v, int n)
{
    if(n <= 0)
    {
        return;
    }
    for(int i=0; i<n-1; i++)
    {
        if(v->vet[i] > v->vet[i+1])
        {
            swap(&v->vet[i], &v->vet[i+1]);
            v->count++;
        }
    }
    imprimir(v, 10);
    bubbleSort(v, n-1); //ação recursiva
}

//Metódo de ordenação selection Sort    (pega o menor elemento e traz para cabeça do vetor e vai repitindo isso alterando a cabeça com i++)
void selectionSort(vetor *v, int n)
{
    int idx;
    for(int i = 0; i < n-1; i++)
    {
        idx = i;
        for(int j = i+1; j<n; j++)
        {
            if(v->vet[idx] > v->vet[j])
            {
                idx = j;
            }
        }
        swap(&v->vet[idx], &v->vet[i]);
        v->count++;
        imprimir(v,10);
    }
}

//Metodo de ordenação por inserção (insertion Sort) (vai andando no vetor pegando o elemento da frente e comparando se ele é o menor dentre os detrás)
void insertionSort(vetor *v, int n)
{
    int aux;
    int j;
    for(int i=1; i<n; i++)
    {
        aux = v->vet[i];
        j = i-1;
        while(aux < v->vet[j] && j>=0)
        {
            v->vet[j+1] = v->vet[j];
            j--;
            v->count++;
        }
        v->vet[j+1] = aux;
        imprimir(v,10); 
    }
}

//Metodo de ordenação concha (Shell sort)
void shellSort(vetor *v, int n)
{
    int h=1;
    int aux, j;
    do{
        h=3*h+1;
    }while(h <= n);
    
    do{
        h=h/3;
        for(int i=h; i<n; i++)
        {
            aux = v->vet[i];
            j=i;
            while(v->vet[j-h] > aux)
            {
                v->vet[j] = v->vet[j-h];
                v->count++;
                j = j - h;
                if(j<h || j<=0)
                {
                    break;
                }
            }
            v->vet[j] = aux;
            imprimir(v,10);
        }
    }while(h != 1);
}


int main()
{
    vetor v;
    iniciarVet(&v, 10);
    printf("------------------------------Vetor Aleatório ------------------------------\n");
    imprimir(&v,10);
    printf("\n\n");

    //testando o bubblesorte
    printf("--------------------------------Bubble Sort---------------------------------\n");
    bubbleSort(&v, 10);
    printf("SWAP: %d\t \n\n", v.count);

    //Voltando com o vetor na posição inicial
    for (int i=0; i<10; i++)
    {
        v.vet[i] = v.beckup[i];
    }
    v.count = 0;

    //testando selection Sort
    printf("-------------------------------Selection Sort------------------------------\n");
    selectionSort(&v, 10);
    printf("SWAP: %d\t \n\n", v.count);

    //Voltando com o vetor na posição inicial
    for (int i=0; i<10; i++)
    {
        v.vet[i] = v.beckup[i];
    }
    v.count = 0;

    //testando insertion Sort
    printf("-------------------------------Insertion Sort------------------------------\n");
    insertionSort(&v, 10);
    printf("SWAP: %d\t \n\n", v.count);

    //Voltando com o vetor na posição inicial
    for (int i=0; i<10; i++)
    {
        v.vet[i] = v.beckup[i];
    }
    v.count = 0;

    //testando shell Sort
    printf("---------------------------------Shell Sort--------------------------------\n");
    shellSort(&v, 10);
    printf("SWAP: %d\t \n\n", v.count);
}
