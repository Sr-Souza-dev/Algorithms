#include <iostream>
#include <ctime> // Para inicializar a semente randômica

using namespace std;

void print_vec(int* vec, int n){
    for(int i=0; i<n; i++) cout<<vec[i]<<" ";
    cout<<endl;
}

int random_number(int x, int y) {
    srand(static_cast<unsigned int>(std::time(nullptr)));  // Inicializa a semente randômica com o tempo atual
    return rand() % (y - x + 1) + x;                       // Gera um número aleatório entre x e y (inclusive)
}

void swap_int(int& a, int&b){
    if(&a == &b) return;
    a ^= b;
    b ^= a;
    a ^=b;
}

int random_partition(int* vec, int p, int r){
    int idx = random_number(p, r-1);
    swap_int(vec[idx], vec[r-1]);
    int i = p-1;
    for(int j=p; j<r-1; j++){
        if(vec[j] > vec[r-1]) continue;
        i++;
        swap_int(vec[i], vec[j]);
    }
    swap_int(vec[i+1], vec[r-1]);
    return i+1;
}

/*
    Seleciona a estatistica de ordem de um array desordenado
    Recupera a i-esima posição do vetor em que todos abaixo de i são menores que ele
    e todos acima do elemento na posição i são maiores que ele.
    É como se o vetor estivesse ordenado e retornacemos a i-esima posição dele.
    Pior caso: O(n²)
    Caso médio: O(n)
*/
int select_order(int* vec, int p, int r, int i){
    if(p==r) return vec[p];
    const int q = random_partition(vec, p, r);
    if(i==q) return vec[q];
    else if(i<q) return select_order(vec, p, q, i);
    else return select_order(vec, q+1, r, i);
}

int main(){
    int n; cin>>n;
    int* vec = new int [n];

    for(int i=0; i<n; i++) cin>>vec[i];
    print_vec(vec, n);
    int idx = random_number(0, 9);
    int x = select_order(vec, 0, n, idx);
    cout<<"O "<<idx<<"º i-esimo: "<<x<<endl;
    
    delete [] vec;
    return 0;
}