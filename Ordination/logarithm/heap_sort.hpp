#include <bits/stdc++.h>
template <class tp>
void rebuildHeap(tp *vec, int father, int end)
{
    int child = (2*father) + 1;
    while((child+1) < end)
    {
        if(vec[child] < vec[child+1]) child++;
        if(vec[father] < vec[child]){
           swap(&vec[father], &vec[child]);
           father = child;
           child = (2*father)+1;
        } else child = end;
    }
}

template <class tp>
void buildHeap(tp *vec, int n)
{
    int father = (n/2);
    while(father >= 0) rebuildHeap(vec,father--,n);
}

template <class tp>
void heapSort(tp* vec, int n){
    buildHeap(vec,n);
    int left = 0, right = n-1;

    while(right > -1)
    {
        if(vec[left] < vec[right]) right--;
        swap(&vec[left], &vec[right]);
        rebuildHeap(vec, left, right--);
    }
}
