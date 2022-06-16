#include <bits/stdc++.h>
#include "vector-op.hpp"        // Biblioteca com definição dos vetores

int contInteraction = 0;

#include "merge_sort.hpp"
#include "quick_sort.hpp"

using namespace std;

void cleanVars(){
    rebase();
    contInteraction = 0;
}

int main(){
    cout<<"------------------------ Merge Sort --------------------------"<<endl;
    cleanVars();
    runMerge();

    cout<<"\n------------------------ Quick Sort --------------------------"<<endl;
    cleanVars();
    runQuick();


    return 0;
}
 