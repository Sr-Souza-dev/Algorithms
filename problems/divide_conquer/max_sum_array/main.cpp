#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n';

typedef long long ll;
const int INF = 0x3b3b3b3b;
const ll LINF = 0x3b3b3b3b3b3b3b3bll;

struct MaxInterval {
    int low, high, maxSum;
    MaxInterval(int l, int h, int s) : low(l), high(h), maxSum(s) {}
};

void print_array(int* vec, int start, int end){
    for(int i=start; i<end; i++) cout<<vec[i]<<" ";
    cout<<endl;
}

MaxInterval findMaxSubArray(int* vec, int low, int mid, int high) {
    int maxSum=vec[mid], left=mid, currSum=vec[mid];
    for(int i=mid-1; i>=low; i--){
        currSum += vec[i];
        if(currSum > maxSum) {
            maxSum = currSum;
            left = i;
        }
    }

    int right=mid+1;
    int maxSumR=vec[right];
    currSum=vec[right];
    for(int i=right+1; i<high; i++){
        currSum += vec[i];
        if(currSum > maxSumR) {
            maxSumR = currSum;
            right = i;
        }
    }
    return MaxInterval(left, right, maxSum+maxSumR);
}

MaxInterval findMaxSum(int* vec, int low, int high){
    if(high - low <= 0 ) return MaxInterval(low, high, vec[high]);

    const int m = floor((low+high)/2);
    const MaxInterval left = findMaxSum(vec, low, m);
    const MaxInterval right = findMaxSum(vec, m+1, high);
    const MaxInterval curr = findMaxSubArray(vec, low, m, high);

    if(left.maxSum > right.maxSum && left.maxSum > curr.maxSum) return left;
    else if(right.maxSum > curr.maxSum) return right;
    else return curr;
}

MaxInterval findMaxSumLinear(int*vec, int low, int high){
    int M = -INF;
    int lowm, highm;
    int mr=0, lowr=0, highr=0;

    for (int i=low; i<high; i++){
        mr += vec[i];
        if(mr> M){
            lowm = lowr;
            highm = i;
            M=mr;
        }
        if(mr<0){
            mr = 0;
            lowr = i+1;
        }
    }
    return MaxInterval(lowm, highm, M);
}

int main() {_
    int n; cin>>n;
    int* vec = new int[n];
    for(int i=0; i<n; i++) cin>>vec[i];
    print_array(vec, 0, n);

    const MaxInterval interval = findMaxSum(vec, 0, n);
    const MaxInterval intervalw = findMaxSumLinear(vec, 0, n);
    cout<<"left: "<<interval.low<<" | high: "<<interval.high<<"  |  max: "<<interval.maxSum<<endl;
    cout<<"left: "<<intervalw.low<<" | high: "<<intervalw.high<<"  |  max: "<<intervalw.maxSum<<endl;
    return 0;
}

