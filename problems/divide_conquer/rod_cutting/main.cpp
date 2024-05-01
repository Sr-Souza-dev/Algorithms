#include <iostream>
#include <iomanip>
using namespace std;

void print_array(int* vec, int n){
    for (int i=0; i<n; i++) cout<<setw(2)<<vec[i]<<" ";
    cout<<endl;
}

int cut_rod(int* cut, int* gain, int n, int size){
    if(size<=0) return 0;

    int q = 0;
    for(int i=0; i<n; i++){
        if(size < cut[i]) return q;
        q = max(q, gain[i] + cut_rod(cut, gain, n, size-cut[i]));
    }
    return q;
}

int main() {
    int n; cin>>n;
    int* gain = new int[n];
    int* cut = new int[n];

    for(int i=0; i<n; i++) cin>>cut[i];
    for(int i=0; i<n; i++) cin>>gain[i];

    cout<<"Cut Size: ";print_array(cut,n);
    cout<<"Cut Gain: ";print_array(gain,n);

    const int rodSize = 24;
    cout<<"Max Gain for "<<rodSize<<"p: "<<cut_rod(cut, gain, n, rodSize)<<endl;

    delete [] gain, cut;
    return 0;
}