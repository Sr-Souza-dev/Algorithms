#include <iostream>
using namespace std;

void print_vec(int* vec, int n){
    for(int i=0; i<n; i++) cout<<vec[i]<<" ";
    cout<<endl;
}

// Obtém o bit de um inteiro (começando da LSB para MSB)
int get_bit_index(int value, int index){
    int bit = 0;
    for(int i=0; i<index; i++){
        if(value <= 0) return 0;
        bit = value%10;
        value /= 10;
    }
    return bit;
}

void counting_sort(int* res, int n, int p){
    int k = 10; // Tamanho da base (base decimal)
    int* aux = new int[k];
    int* vec = new int[n];

    for(int i=0; i<k; i++) aux[i]=0;
    for(int i=0; i<n; i++) {aux[get_bit_index(res[i], p)]++; vec[i] = res[i];}
    for(int i=1; i<k; i++) aux[i] += aux[i-1];
    while(n--){
        res[aux[get_bit_index(vec[n], p)]-1] = vec[n];
        aux[get_bit_index(vec[n], p)]--;
    }
    delete [] aux, vec;
}

void radix_sort(int* vec, int n, int p){
    for(int i=1; i<=p; i++){
        counting_sort(vec, n, i);
    }
}

int main() {
    int n; cin>>n;
    int* vec = new int[n];

    for(int i=0; i<n; i++) cin>>vec[i];

    print_vec(vec, n);
    radix_sort(vec, n, 3);
    print_vec(vec, n);

    delete [] vec;
    return 0;
}