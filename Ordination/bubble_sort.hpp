// ******************** Implementação Bubble Sort (Recursivo) ********************
template <class tp>
void bubbleSort(tp *vec, int size){
    if(size<=0) return;

    contInteraction++;
    for(int i=0; i<size-1; i++){
        contInteraction++;
        if(vec[i] > vec[i+1]){
            swap(&vec[i], &vec[i+1]);
        }
    }
    bubbleSort(vec, size-1);
}

// ***************** Testando o metodo de ordenação *****************
void runBubble(){
    // Teste com valores inteiros
    bubbleSort(vecInt, vecSize("int"));
    std::cout<<"*********** INT VALUES (bubble) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    std::cout<<"Quantidade de Interações: "<<contInteraction<<std::endl;

    contInteraction = 0;

    // Teste com valores flutuantes
    bubbleSort(vecFloat, vecSize("float"));
    std::cout<<"********** FLOAT VALUES (bubble) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));
    std::cout<<"Quantidade de Interações: "<<contInteraction<<std::endl;
}

