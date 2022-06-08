#include <bits/stdc++.h>

// ********** Função para facilitar operações no vetor ***************
template <class tp>
void swap(tp *v1, tp *v2){
    tp aux = *v1;
    *v1 = *v2;
    *v2 = aux;    
}

template <class tp>
void print(tp *vec, int size){
    for(int i=0; i<size; i++){
        if(i!=0) std::cout<<" | ";
        std::cout<<vec[i];
    }
    std::cout<<std::endl;
}

// ******************** Implementação Bubble Sort ********************
template <class tp>
void bubbleSort(tp *vec, int size){
    if(size<=0) return;

    for(int i=0; i<size-1; i++){
        if(vec[i] > vec[i+1]){
            swap(&vec[i], &vec[i+1]);
        }
    }
    bubbleSort(vec, size-1);
}

// *********************** PRINCIPAL (Main) **************************
int main(){

    // Teste com valores inteiros
    int vec[] = {0,6,46,3,9,7,8,16,26};
    bubbleSort(vec, 9);
    print(vec, 9);

    // Teste com valores flutuantes
    float vec1[] = {0.6,6.95,46.12,3.99,4.9,7.18,8.6,16,33};
    bubbleSort(vec1, 9);
    print(vec1, 9);

    return 0;
}