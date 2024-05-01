#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n';

typedef long long ll;

const int INF = 0x3b3b3b3b;
const ll LINF = 0x3b3b3b3b3b3b3b3bll;

void print_array(int* arr, int start = 0, int end = 1){
    for(int i=start; i<end; i++){
        cout << arr[i] << " ";
    } cout << endl;
}

void merge(int* vec, int s, int m, int e) {
    int left = m-s;
    int right = e-m;

    int* vLeft = new int[left+1]; vLeft[left] = INF;
    int* vRight = new int [right+1]; vRight[right] = INF;

    for(int i=0; i<left; i++) vLeft[i] = vec[s+i];
    for(int i=0; i<right; i++) vRight[i] = vec[m+i];

    int l=0; int r=0;
    for(int i=s; i<e; i++){
        if(vLeft[l] < vRight[r]) {
            vec[i] = vLeft[l];
            l++;
        } else {
            vec[i] = vRight[r];
            r++;
        }
    }
}

void merge_sort(int* vec, int s, int e) {
    if(e-s <= 1) return;

    int m = floor((s+e)/2);
    merge_sort(vec, s, m);
    merge_sort(vec, m, e);
    merge(vec, s, m, e);
}


int main() {_
    int n; cin>>n;
    int* vec = new int[n];

    for(int i=0; i<n; i++) cin>>vec[i];
    print_array(vec, 0, n);

    merge_sort(vec, 0, n);
    print_array(vec, 0, n);

    return 0;
}
