// ******************* Implementação merge Sort ********************
template <class tp>
void merge(tp *vec, int start, int middle, int end){

    int leftIndex = start;                                                      // Define o inicio do vetor a esquerda para poder ser tratado como pilhar
    int rightIndex = middle+1;                                                  // Define o inicio do vetor a direita para poder ser tratado como pilhar

    tp *aux = new tp[end-start+1];                                              // Define o vetor que será ordenado
    int i = 0;                                                                  // Define o indice do vetor que será ordenado

    while(leftIndex <= middle && rightIndex <= end){                            // Verifica qual das 'pilhas' (esquerda ou direita) tem o menor valor
        if(vec[leftIndex] < vec[rightIndex]) aux[i++] = vec[leftIndex++];       // Caso a pilha a esquerda tenha o menor valor, ele é salvo em um vetor auxiliar e removido da 'pilha' esquerda 
        else aux[i++] = vec[rightIndex++];                                      // Caso a pilha da direita tenha o menor valor, ele é salvo em um vetor auxiliar e removido da 'pilha'  direita
    }

    while(leftIndex <= middle) aux[i++] = vec[leftIndex++];                     // Caso sobre elementos na pilha a esquerda
    while(rightIndex <= end) aux[i++] = vec[rightIndex++];                      // Caso sobre elementos na pilha a direita
    
    for(int k=start; k<=end; k++) vec[k] = aux[k-start];                        // Atualiza o vetor real com o vetor aux (atualmente ordenado)
}

template <class tp>
void mergeSort(tp *vec, int start, int end){                                    // Divide o vetor em estrutura de arvore até que se tenha somente um item nas folhas
    if(start < end){
        int middle = (start + end)/2;
        mergeSort(vec, start, middle);                                          // Divide o lado esquerdo do vetor em outros dois subvetores
        mergeSort(vec, middle+1, end);                                          // Divide o lado direito do vetor em outros dois subvetores
        merge(vec, start, middle, end);                                         // Faz a junção dos nós de mesmo nível da arvore binaria gerada
    }
}


// ***************** Testando o metodo de ordenação *****************
void runMerge(){
    // Teste com valores inteiros
    mergeSort(vecInt, 0, (vecSize("int") - 1));
    std::cout<<"*********** INT VALUES (Merge) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    std::cout<<"Quantidade de Interações: "<<contInteraction<<std::endl;

    contInteraction = 0;

    // Teste com valores flutuantes
    mergeSort(vecFloat, 0, vecSize("float") - 1);
    std::cout<<"********** FLOAT VALUES (Merge) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));
    std::cout<<"Quantidade de Interações: "<<contInteraction<<std::endl;
}