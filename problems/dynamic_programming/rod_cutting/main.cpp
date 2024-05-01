#include <iostream>
#include <iomanip>
using namespace std;

void print_array(int* vec, int n){
    for (int i=0; i<n; i++) cout<<setw(2)<<vec[i]<<" ";
    cout<<endl;
}

int cut_rod(int* cut, int* gain, int* memo, int n, int size){
    if(size<=0) return 0;
    if(memo[size] > 0) return memo[size];

    int q = 0;
    for(int i=0; i<n; i++){
        if(size < cut[i]) continue;
        q = max(q, gain[i] + cut_rod(cut, gain, memo, n, size-cut[i]));
    }
    memo[size] = q;
    return q;
}

/*
    Implementação Up-down. 
    Conhecido como programação dinâmica ou 
    procedimento recursivo memorizado. 
*/
int memorized_cut_rod(int* cut, int* gain, int n, int size){
    int* memo = new int[size+1];
    for(int i=0; i<size+1; i++) memo[i] = -1;
    return cut_rod(cut, gain, memo, n, size);
}

/*
    Implementação Bottom-up.
    Essa e a implementação anterior tem o mesmo custo computacional
*/
int dynamic_cut_rod(int* cut, int* gain, int n, int size){
    const int resIdx = size;
    int* memo = new int[size+1];
    int* seq  = new int[size+1];

    for(int i=1; i<size; i++) memo[i]=-1;

    memo[0] = 0;
    for (int j = 1; j <= size; j++) {
        int q = 0;
        for (int i = 0; i < n; i++) {
            if(j < cut[i]) continue;
            if(q < gain[i] + memo[j - cut[i]]){
                q = gain[i] + memo[j - cut[i]];
                seq[j] = cut[i];
            }
        }
        memo[j] = q;
    }
    cout<<"[ ";
    while(size > 0){
        cout<<seq[size]<<" ";
        size -= seq[size];
    } cout<<"] ";

    return memo[resIdx];
}

int main() {
    int n; cin>>n;
    int* gain = new int[n];
    int* cut = new int[n];

    for(int i=0; i<n; i++) cin>>cut[i];
    for(int i=0; i<n; i++) cin>>gain[i];

    cout<<"Cut Size: ";print_array(cut,n);
    cout<<"Cut Gain: ";print_array(gain,n);

    const int rodSize = 29;
    cout<<"Max Gain Up-Down   ("<<rodSize<<"): "<<memorized_cut_rod(cut, gain, n, rodSize)<<endl;
    cout<<"Max Gain Bottom-Up ("<<rodSize<<"): "<<dynamic_cut_rod(cut, gain, n, rodSize)<<endl;

    delete [] gain, cut;
    return 0;
}