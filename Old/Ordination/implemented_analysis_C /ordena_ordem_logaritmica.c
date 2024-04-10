#include <stdlib.h>
#include <stdio.h>

//--------------------------------Tratando do vetor a ser ordenado----------------------------------------
typedef struct vetor vetor;                 //struct do vetor
struct vetor{
    int *vet;
};

void iniciarVet(vetor *v, int n)            //Alocando espaços de memória para o ponteiro
{
    srand(42);
    v->vet = (int*) malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        v->vet[i] = rand()%100;             //Definindo valores aleatórios para o vetor
    }
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
//-------------------------------------------FIM de configurações do vetor-------------------------------------

//Metodo de ordenação marge sort (Divide em varios subproblemas e começa a ordenar (exige o dobro da memória))
void marge(vetor *v, int p, int q, int r)  //Comaça a ordenar os elementos
{
    int i = p;
    int j = q + 1;
    int k = 0;

    int *aux = (int*)malloc((r-p+1) * sizeof(int));

    while(i<=q && j<=r)
    {
        if(v->vet[i] < v->vet[j])
        {
            aux[k] = v->vet[i];
            i++;
        }
        else
        {
            aux[k] = v->vet[j];
            j++;
        }
        k++;
    }
    while(i<=q)
    {
        aux[k] = v->vet[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        aux[k] = v->vet[i];
        j++;
        k++;
    }
    for(i=p; i<=r; i++)
    {
        v->vet[i] = aux[i-p];
    }
    printf("P: %d, Q: %d, R: %d\t",p,q,r);
    imprimir(v, 10);
    free(aux);
}
void margeSort(vetor *v, int p, int r)      //divide o vetor em sub vetores 
{
    if(p < r)
    {
        int q = (p+r)/2;
        margeSort(v, p, q);
        margeSort(v, q+1, r);
        marge(v,p,q,r);
    }
}

//Metodo de ordenação quick sort (Define um pivô e vai comprando com os outro elementos e os ordenando de acordo com o pivô)
void partition(vetor *v, int p, int r, int *i, int *j)
{
    int pivo;
    int idx = (p+r)/2;
    *i = p;
    *j = r;
    pivo = v->vet[idx];

    do{
            while(v->vet[*i] < pivo && *i < r)
                *i = *i +1;
            while(v->vet[*j] > pivo && *j >p)
                *j = *j - 1;
            if(*i<=*j)
            {
                swap(&v->vet[*i], &v->vet[*j]);
                *i = *i +1;
                *j = *j - 1;
            }
    }while(*i<=*j);
}
void quickSort(vetor *v, int p, int r, int i, int j)
{
    partition(v,p,r, &i, &j);
    imprimir(v,10);
    if(j > p)
    {
        quickSort(v,p,j,i,j);
    }
    if(i < r)
    {
        quickSort(v,i,r,i,j);
    }
}

//Método de Ordenação head sort (Cria uma arvore binaria e mantém os maiores elementos na raiz e os menores subsequente ate que os menores esteja nas folhas)
void rebuildHeap(vetor *v, int left, int right)
{
    int i = left;
    int child = (2*i) + 1;
    while((child+1) < right)
    {
        if(v->vet[child] < v->vet[child+1])
        {
            child = child + 1;
        }
        if(v->vet[i] < v->vet[child])
        {
            swap(&v->vet[i], &v->vet[child]);
            i = child;
            child = (2*i);
        } else child = right;
        
    }
}
void buildHeap(vetor *v, int n)
{
    int left = (n/2);
    while(left > 0)
    {
        left = left - 1;
        rebuildHeap(v,left,n);
    }
}
void heapSort(vetor *v, int n)
{
    int left, right;
    buildHeap(v,n);
    left = 0;
    right = n-1;

    while(right > 0)
    {
        if(v->vet[left] < v->vet[right]) right--;
        swap(&v->vet[left], &v->vet[right]);
        imprimir(v,10);
        right = right - 1;
        rebuildHeap(v, left, right);
    }
}

//Metodo de ordenação Radix Sort 
int getDecimal(int value, int exp)
{
    return (value / exp) % 10;
}
void Contagem(vetor *v, int n, int exp)
{
    int i,j;
    int bucket[10] = { 0 };
    int *aux = (int*) malloc(n*sizeof(int));

    for(i=0; i<n; i++)
    {
        j = getDecimal(v->vet[i],exp);
        bucket[j]++;
    }
    for(i=1; i<10; i++)
    {
        bucket[i] += bucket[i-1];
    }
    for(i=n-1; i>=0; i--)
    {
        j = getDecimal(v->vet[i],exp);
        aux[--bucket[j]] = v->vet[i];
    }
    for(i=0; i<n; i++)
    {
        v->vet[i] = aux[i];
    }
    free(aux);
}
void radixSort(vetor *v, int n)
{
    int i; 
    int maior = 0;
    int exp = 1;
    for (i=0; i<n; i++)
    {
        if(v->vet[i] > maior)
            maior = v->vet[i];
    }
    while (maior/exp > 0)
    {
        Contagem(v,n,exp);
        imprimir(v,n);
        exp = exp * 10;
    }
}

int main()
{
    vetor v;
    iniciarVet(&v, 10);
    printf("------------------------------Vetor Aleatório ------------------------------\n");
    imprimir(&v,10);
    printf("\n\n");

    //testando o marge sort
      printf("--------------------------------Marge Sort---------------------------------\n");
      margeSort(&v, 0, 9);

    //testando o Quick sort
     printf("--------------------------------Quick Sort---------------------------------\n");
    quickSort(&v, 0, 9, 0, 0);

    //testando o Heap sort
     printf("--------------------------------Head Sort---------------------------------\n");
    heapSort(&v, 10);

    //testando o Radix sort
    printf("--------------------------------Radix Sort---------------------------------\n");
    radixSort(&v, 10);
}
