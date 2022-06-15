// ******************** Implementação Shell Sort ***********************
template <class tp>
void shellSort(tp vec, int size){
    int h=3*size+1;
    int aux, j;

    

    do{
        h=h/3;
        contInteraction++;
        for(int i=h; i<size; i++){
            aux = vec[i];
            j=i;
            contInteraction++;
            while(vec[j-h] > aux){
                vec[j] = vec[j-h];
                j = j - h;
                contInteraction++;
                if(j<h || j<=0){
                    break;
                }
            }
            vec[j] = aux;
        }
    }while(h!=1);
}

// ***************** Testando o metodo de ordenação *****************
void runShell(){
    // Teste com valores inteiros
    shellSort(vecInt, vecSize("int"));
    std::cout<<"*********** INT VALUES (shell) ************"<<std::endl;
    print(vecInt, vecSize("int"));
    std::cout<<"Quantidade de Interações: "<<contInteraction<<std::endl;

    contInteraction = 0;

    // Teste com valores flutuantes
    shellSort(vecFloat, vecSize("float"));
    std::cout<<"********** FLOAT VALUES (shell) ***********"<<std::endl;
    print(vecFloat, vecSize("float"));
    std::cout<<"Quantidade de Interações: "<<contInteraction<<std::endl;
}

