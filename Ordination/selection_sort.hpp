// ******************* Implementação Selection Sort ********************
template<class Tp>
void selectionSort(Tp *vec, int size){
    int idx;
    for(int i=0; i<size-1; i++){
        idx = i;
        contInteraction++;
        for(int j=i+1; j<size; j++){
            contInteraction++;
            if(vec[idx]>vec[j]){
                idx = j;
            }
        }
        swap(&vec[idx], &vec[i]);
    }
}

// ***************** Testando o metodo de ordenação *****************
void runSelection(){
    // Teste com valores inteiros
    selectionSort(vecInt, vecSize("int"));
    std::cout<<"*********** INT VALUES (selection) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    std::cout<<"Quantidade de Interações: "<<contInteraction<<std::endl;

    contInteraction = 0;

    // Teste com valores flutuantes
    selectionSort(vecFloat, vecSize("float"));
    std::cout<<"********** FLOAT VALUES (selection) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));
    std::cout<<"Quantidade de Interações: "<<contInteraction<<std::endl;
}
