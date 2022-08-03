// ******************* Implementação Selection Sort ********************
template<class Tp>
void insertionSort(Tp *vec, int size){
    int aux;
    int j;
    for(int i=1; i<size; i++){
        aux = vec[i];
        j = i - 1;
        while(aux < vec[j] && j>=0)
        {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = aux;
    }
}
