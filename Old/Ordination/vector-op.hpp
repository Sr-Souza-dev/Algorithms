
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

// Declarando os vetores da base
static const int baseInt[] = {9,2,6,1,13,23,7,15};
static const float baseFloat[] = {0.6,6.95,46.12,3.99,4.9,7.18,8.6,16,33,7.23,7.12};

// Descobre o tamanho do vetor
int vecSize(std::string opt){
    if(opt == "int"){
        return (sizeof(baseInt) / sizeof(int));

    }else if(opt == "float"){
        return (sizeof(baseFloat) / sizeof(float));
    }
    return -1;
}

// Declara os vetores
int *vecInt = new int[vecSize("int")];
float *vecFloat = new float[vecSize("float")];

// Volta o vetor ao seu estado inicial
void rebase(){
    for(int i=0; i<vecSize("int"); i++){
        vecInt[i] = baseInt[i]; 
    }

    for(int i=0; i<vecSize("float"); i++){
        vecFloat[i] = baseFloat[i]; 
    }
}


