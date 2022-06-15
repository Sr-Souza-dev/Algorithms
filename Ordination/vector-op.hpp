
// Realiza a troca de posições do vetor
template <class tp>
void swap(tp *v1, tp *v2){
    tp aux = *v1;
    *v1 = *v2;
    *v2 = aux;    
}

// imprime as posições do vetor
template <class tp>
void print(tp *vec, int size){
    for(int i=0; i<size; i++){
        if(i!=0) std::cout<<" | ";
        std::cout<<vec[i];
    }
    std::cout<<std::endl;
}


// Declara os vetores
int vecInt[] = {0,6,46,3,9,7,8,16,26, 28, 43};
float vecFloat[] = {0.6,6.95,46.12,3.99,4.9,7.18,8.6,16,33};


// Descobre o tamanho do vetor
int vecSize(std::string opt){
    if(opt == "int"){
        return (sizeof(vecInt) / sizeof(int));

    }else if(opt == "float"){
        return (sizeof(vecFloat) / sizeof(float));
    }
    return -1;
}