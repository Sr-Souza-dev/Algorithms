// ******************* Implementação Selection Sort ********************
template<class Tp>
void selectionSort(Tp *vec, int size){
    int idx;
    for(int i=0; i<size-1; i++){
        idx = i;
        for(int j=i+1; j<size; j++){

            if(vec[idx]>vec[j]){
                idx = j;
            }
        }
        swap(&vec[idx], &vec[i]);
    }
}

