// ******************** Implementação Shell Sort ***********************
template <class tp>
void shellSort(tp vec, int size){
    int h=3*size+1;
    int aux, j;

    do{
        h=h/3;
        for(int i=h; i<size; i++){
            aux = vec[i];
            j=i;
            while(vec[j-h] > aux){
                vec[j] = vec[j-h];
                j = j - h;  
                if(j<h || j<=0){
                    break;
                }
            }
            vec[j] = aux;
        }
    }while(h!=1);
}
