#include <iostream>
using namespace std;

void print_vec(int* vec, int n){
    for(int i=0; i<n; i++) cout<<vec[i]<<" ";
    cout<<endl;
}

void swap_int(int& a, int& b){
    if(&a == &b) return;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int partition(int* vec, int p, int r){
    int x = vec[r-1];
    int i = p-1; 
    for(int j=p; j<r-1; j++){
        if(vec[j] > x) continue;
        i++;
        swap_int(vec[j], vec[i]);
    }
    swap_int(vec[r-1], vec[i+1]);
    return i+1;
}

void quick_sort(int* vec, int p, int r){
    if(p >= r) return; 

    const int q = partition(vec, p, r);
    quick_sort(vec, p, q);
    quick_sort(vec, q+1, r);
}

int main() {
    int n; cin>>n;
    int* vec = new int[n];

    for(int i=0; i<n; i++) cin>>vec[i];
    print_vec(vec, n);
    quick_sort(vec, 0, n);
    print_vec(vec, n);

    delete [] vec;
    return 0;
}