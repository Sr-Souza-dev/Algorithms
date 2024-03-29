// ******************* Implementação quick Sort ********************
template <class tp>
int partition(tp *vec, int start, int end){
    int arrow_left = start-1;
    int arrow_right = start;
    int index_pivot = (start+end)/2;
    tp pivot = vec[index_pivot];

    while(arrow_right <= end){
        if(vec[arrow_right] < pivot){
            swap(&vec[arrow_left + 1], &vec[arrow_right]);
            arrow_left++;
        } 
        if(vec[arrow_right] == pivot){
            index_pivot = arrow_right;
        }
        arrow_right++;
    }

    arrow_left++;
    swap(&vec[arrow_left], &vec[index_pivot]);

    return arrow_left;
}

template <class tp>
void quickSort(tp *vec, int start, int end){
    if(start<end){
        int index_pivot =  partition(vec, start, end);
        quickSort(vec,start,index_pivot-1);
        quickSort(vec,index_pivot+1,end);
    }
}

