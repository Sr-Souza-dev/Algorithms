#include <bits/stdc++.h>
using namespace std;

/*
    --- Mantém a subarvore começando de i como uma heap O(lg n) ---
    Ao mover um elemento, não é garantido que a posição i continua sendo
    o maior de sua subarvore, por isso, é necessário ir descendo ele na arvore
    até encontrar a posição correta
*/
void max_heapify(int* vec, int i, int n){
    const int left = i<<1;
    const int right = (i<<1) + 1;
    int bigger = i;
    if (left < n and vec[left] > vec[bigger]) bigger = left;
    if (right < n and vec[right] > vec[bigger]) bigger = right;

    if(bigger != i) {
        vec[bigger] = vec[bigger] ^ vec[i];
        vec[i]      = vec[bigger] ^ vec[i];
        vec[bigger] = vec[bigger] ^ vec[i];
        max_heapify(vec, bigger, n);
    }
}

/*
    --- Constroi a max-heap O(n) ---
    Como os filhos de cada nó são 2i e 2i+1, temos que a partir 
    do tamanho n/2 do vetor teremos apenas folhas da árvore heap.
    Podemos utilizar o max_heapify para a construção da árvore,
    para isso, basta aplicalo ao contrário.
*/
void build_max_heap(int* vec, int n){
    for (int i=n/2; i>=0; i--){
        max_heapify(vec, i, n);
    }
}

/*
    --- Ordena o vetor utilizando o selection-sort pegando da heap ---
*/
void heap_sort(int* vec, int n) {
    build_max_heap(vec,n);
    for(int i=n-1; i>0; i--){
        vec[0] = vec[i] ^ vec[0];
        vec[i] = vec[i] ^ vec[0];
        vec[0] = vec[i] ^ vec[0];
        max_heapify(vec, 0, i);
    }
}

void print_vec(int* vec, int n){
    for(int i=0; i<n; i++) cout<<vec[i]<<" ";
    cout<<endl;
}

int main() {
    int n; cin>>n;
    int* vec = new int[n];

    for (int i=0; i<n; i++) cin>>vec[i];
    print_vec(vec, n);

    heap_sort(vec, n);
    print_vec(vec, n);
}