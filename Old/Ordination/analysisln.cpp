#include <bits/stdc++.h>
#include "vector-op.hpp"        // Biblioteca com definição dos vetores


#include "logarithm/merge_sort.hpp"
#include "logarithm/quick_sort.hpp"
#include "logarithm/heap_sort.hpp"
#include "logarithm//radix_sort.hpp"


void cleanVars(){
    rebase();
}

int main(){
    std::cout<<"------------------------ Merge Sort --------------------------"<<std::endl;
    cleanVars();
    // Teste com valores inteiros
    mergeSort(vecInt, 0, (vecSize("int") - 1));
    std::cout<<"*********** INT VALUES (Merge) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    // Teste com valores flutuantes
    mergeSort(vecFloat, 0, vecSize("float") - 1);
    std::cout<<"********** FLOAT VALUES (Merge) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));


    std::cout<<"\n------------------------ Quick Sort --------------------------"<<std::endl;
    cleanVars();
    // Teste com valores inteiros
    quickSort(vecInt, 0, vecSize("int") - 1);
    std::cout<<"*********** INT VALUES (Quick) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    // Teste com valores flutuantes
    quickSort(vecFloat, 0, vecSize("float") - 1);
    std::cout<<"********** FLOAT VALUES (Quick) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));


    std::cout<<"\n------------------------ Heap Sort --------------------------"<<std::endl;
    cleanVars();
    // Teste com valores inteiros
    heapSort(vecInt, vecSize("int"));
    std::cout<<"*********** INT VALUES (Heap) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    // Teste com valores flutuantes
    heapSort(vecFloat, vecSize("float"));
    std::cout<<"********** FLOAT VALUES (Heap) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));


    std::cout<<"\n------------------------ Radix Sort --------------------------"<<std::endl;
    cleanVars();
    // Teste com valores inteiros
    radixSort(vecInt, vecSize("int"));
    std::cout<<"*********** INT VALUES (Radix) ************"<<std::endl;
    print(vecInt, vecSize("int"));


    return 0;
}
 