#include <iostream>
using namespace std;

void print_vec(int* vec, int n){
    for(int i=0; i<n; i++) cout<<vec[i]<<" ";
    cout<<endl;
}

int get_max_number(int* vec, int n){
    int max = vec[0];
    for(int i=1; i<n; i++){
        if(vec[i] > max) max = vec[i];
    }
    return max;
}

/*
    Repare que esse algoritmo cria um vetor auxiliar do tamanho 
    do máximo elemento presente no vetor de interesse,
    portanto o custo desse algoritmo será O(k), onde k é o maior 
    elemento do vetor de interesse. 
    Nesse algoritmo, todos os valores do array precisam ser positivos. 
*/
void counting_sort(int* vec, int* vecR, int n){
    int k = get_max_number(vec, n) + 1;
    int* aux = new int[k];
    for(int i=0; i<k; i++) aux[i] = 0;                      // Inicializa o vetor auxiliar
    for(int i=0; i<n; i++) aux[vec[i]]++;                   // conta quantas vezes cada valor ocorreu
    for(int i=1; i<k; i++) aux[i] = aux[i] + aux[i-1];      // Obtém o vetor acumulado (conseguindo a assim cada posição do elemento no array real)
    while(n--){                              // Esse for é ao contrário para garantir a estabilidade
        vecR[aux[vec[n]]-1] = vec[n];
        aux[vec[n]]--;
    }
}

int main() {
    int n; cin>>n;
    int* vec = new int[n];
    int* vecR = new int [n];

    for (int i=0; i<n; i++) cin>>vec[i];

    print_vec(vec, n);
    counting_sort(vec, vecR, n);
    print_vec(vecR, n);

    delete [] vec, vecR;
    return 0;
}