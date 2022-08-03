#include <bits/stdc++.h>
#include "vector-op.hpp"        // Biblioteca com definição dos vetores


// OBS. Cada arquivo importado abaixo depende dos importes acima, caso deseje executar de forma isolada add ao arquivo desejado
#include "quadratic/bubble_sort.hpp" 
#include "quadratic/selection_sort.hpp"
#include "quadratic/insertion_sort.hpp"
#include "quadratic/shell_sort.hpp"

using namespace std;

void cleanVars(){
    rebase();
    contInteraction = 0;
}

int main(){
    cout<<"------------------------ Bubble Sort --------------------------"<<endl;
    cleanVars();
    // Teste com valores inteiros
    bubbleSort(vecInt, vecSize("int"));
    std::cout<<"*********** INT VALUES (bubble) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    // Teste com valores flutuantes
    bubbleSort(vecFloat, vecSize("float"));
    std::cout<<"********** FLOAT VALUES (bubble) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));


    cout<<"\n---------------------- Selection Sort -------------------------"<<endl;
    cleanVars();
    // Teste com valores inteiros
    selectionSort(vecInt, vecSize("int"));
    std::cout<<"*********** INT VALUES (selection) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    // Teste com valores flutuantes
    selectionSort(vecFloat, vecSize("float"));
    std::cout<<"********** FLOAT VALUES (selection) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));


    cout<<"\n----------------------- Insertion Sort -------------------------"<<endl;
    cleanVars();
    // Teste com valores inteiros
    insertionSort(vecInt, vecSize("int"));
    std::cout<<"*********** INT VALUES (Insertion) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    // Teste com valores flutuantes
    insertionSort(vecFloat, vecSize("float"));
    std::cout<<"********** FLOAT VALUES (Insertion) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));


    cout<<"\n------------------------- Shell Sort ---------------------------"<<endl;
    cleanVars();
    // Teste com valores inteiros
    shellSort(vecInt, vecSize("int"));
    std::cout<<"*********** INT VALUES (shell) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    // Teste com valores flutuantes
    shellSort(vecFloat, vecSize("float"));
    std::cout<<"********** FLOAT VALUES (shell) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));
}