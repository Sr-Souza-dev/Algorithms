#include <bits/stdc++.h>
#include "vector-op.hpp"        // Biblioteca com definição dos vetores

int contInteraction = 0;

// OBS. Cada arquivo importado abaixo depende dos importes acima, caso deseje executar de forma isolada add ao arquivo desejado
#include "bubble_sort.hpp" 
#include "selection_sort.hpp"
#include "insertion_sort.hpp"
#include "shell_sort.hpp"

using namespace std;

int main(){
    cout<<"------------------------ Bubble Sort --------------------------"<<endl;
    runBubble();

    cout<<"\n---------------------- Selection Sort -------------------------"<<endl;
    runSelection();

    cout<<"\n----------------------- Insertion Sort -------------------------"<<endl;
    runInsertion();

    cout<<"\n------------------------- Shell Sort ---------------------------"<<endl;
    runShell();


}