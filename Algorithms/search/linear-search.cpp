#include <iostream> 
using namespace std;

void print_array(int* arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}

int linear_search(int* arr, int n, int v){
    for(int i=0; i<n; i++){
        if(arr[i] == v) return i;
    }
    return -1;
}

int linear_search_recursive(int* arr, int n, int v) {
    if(n<0) return -1;
    if(arr[n] == v) return n;
    return linear_search_recursive(arr, n-1, v);
}

int main() {
    int n; cin>>n;
    int* arr1 = new int[n];
    int* arr2 = new int[n];

    for(int i=0; i<n; i++) {cin>>arr1[i]; arr2[i] = arr1[i];}
    int v; cin>>v;

    print_array(arr1,n);

    cout<<"Interactive:  "<<linear_search(arr1, n, v) << endl;
    cout<<"Recursive:    "<<linear_search_recursive(arr2, n-1, v) << endl;

    delete[] arr1, arr2;
    return 0;
}
