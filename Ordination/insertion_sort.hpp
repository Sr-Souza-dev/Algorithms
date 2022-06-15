// ******************* Implementação Selection Sort ********************
template<class Tp>
void insertionSort(Tp *vec, int size){
    int aux;
    int j;
    for(int i=1; i<size; i++){
        aux = vec[i];
        j = i - 1;
        contInteraction++;
        while(aux < vec[j] && j>=0)
        {
            contInteraction++;
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = aux;
    }
}

// ***************** Testando o metodo de ordenação *****************
void runInsertion(){
    // Teste com valores inteiros
    insertionSort(vecInt, vecSize("int"));
    std::cout<<"*********** INT VALUES (Insertion) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    std::cout<<"Quantidade de Interações: "<<contInteraction<<std::endl;

    contInteraction = 0;

    // Teste com valores flutuantes
    insertionSort(vecFloat, vecSize("float"));
    std::cout<<"********** FLOAT VALUES (Insertion) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));
    std::cout<<"Quantidade de Interações: "<<contInteraction<<std::endl;
}
