#include <iostream>
using namespace std;

void print_array(int* arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    } cout << endl;
}

void selection_sort(int* arr, int n){
    for (int i=0; i<n-1; i++) {
        int min = i;
        for (int j=i+1; j<n; j++){
            if(arr[j] < arr[min]) min = j;
        }
        if(min != i){
            arr[i]   = arr[i] ^ arr[min];
            arr[min] = arr[i] ^ arr[min];
            arr[i]   = arr[i] ^ arr[min];
        }
    }
}

void selection_sort_recursive(int* arr, int n) {
    if (n<1) return;
    int max = n;
    for(int i=0; i<n; i++) {
        if (arr[i] > arr[max]) max = i;
    }
    if(max != n){
        arr[n]   = arr[n] ^ arr[max];
        arr[max] = arr[n] ^ arr[max];
        arr[n]   = arr[n] ^ arr[max];
    }
    selection_sort_recursive(arr, n-1);
}

int main() {
    int n; cin>>n;
    int *arr  = new int[n];
    int *arr2 = new int[n];

    for(int i=0; i<n; i++) {cin>>arr[i]; arr2[i] = arr[i];}

    print_array(arr, n); cout << endl;

    selection_sort(arr, n);
    selection_sort_recursive(arr2, n-1);

    cout<<"Interactive: "; print_array(arr, n);
    cout<<"Recursive:   "; print_array(arr2, n);

    delete[] arr, arr2;
    return 0; 
}