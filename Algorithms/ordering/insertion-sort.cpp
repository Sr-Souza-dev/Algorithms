#include <iostream>

using namespace std;

void print_array(int* arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    } cout << endl;
}

void insertion_sort(int* arr, int n){
    for(int i=1; i<n; i++) {

        int key = arr[i];
        int j   = i-1;

        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void insertion_sort_recursive(int* arr, int n) {
    if(n < 1) return;
    insertion_sort_recursive(arr, n-1);
    
    int key = arr[n];
    int j   = n-1;

    while(j>=0 && arr[j] > key){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}

int main(){
    int n;  cin >> n;
    int* arr  = new int[n]; 
    int* arr2 = new int[n];

    for(int i = 0; i < n; i++) {cin >> arr[i]; arr2[i] = arr[i];}

    print_array(arr, n); cout << endl;

    insertion_sort(arr, n);
    insertion_sort_recursive(arr2, n);

    cout<<"Interactive: "; print_array(arr, n);
    cout<<"Recursive:   "; print_array(arr2, n);

    delete[] arr, arr2;
    return 0;
}