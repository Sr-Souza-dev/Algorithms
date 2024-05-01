#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";

typedef long long ll;

const int INF = 0x3b3b3b3b;
const ll LINF = 0x3b3b3b3b3b3b3b3bll;

void printMatrix(int** matrix, int l, int c){
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void sum_matrix(int** A, int** B, int**C, int sa, int ea, int sb, int eb, int sc, int ec){
    const int n = ec - sc;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i+sc][j+ec] = A[i+sa][j+ea] + B[i+sb][j+eb];
        }
    }
}

int** multiply_matrix(int** A, int** B, int**C, int start, int end){
    if(end-start==0) C[start][start] = A[start][start] * B[start][start];
    else{
        const int m = floor(start+end)/2;

    }
    return C;
}

int main(){_
    int n; cin>>n;
    int** A = new int*[n];
    int** B = new int*[n];
    int** C = new int*[n];

    for(int i=0; i<n; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>A[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>B[i][j];
        }
    }
    cout<<"Matrix A"<<endl; printMatrix(A, n, n); cout<<endl;
    cout<<"Matrix B"<<endl; printMatrix(B, n, n); cout<<endl;

    return 0;
}