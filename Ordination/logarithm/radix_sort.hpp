int getDecimal(int value, int exp) {return (value / exp) % 10;}

template <class tp>
void Contagem(tp *vec, int n, int exp)
{
    int i,j;
    int bucket[10] = { 0 };
    tp *aux = new tp[n];

    for(i=0; i<n; i++)
    {
        j = getDecimal(vec[i],exp);
        bucket[j]++;
    }
    for(i=1; i<10; i++)
    {
        bucket[i] += bucket[i-1];
    }
    for(i=n-1; i>=0; i--)
    {
        j = getDecimal(vec[i],exp);
        aux[--bucket[j]] = vec[i];
    }
    for(i=0; i<n; i++)
    {
        vec[i] = aux[i];
    }
    delete aux;
}

template <class tp>
void radixSort(tp *vec, int n)
{
    int i; 
    int maior = 0;
    int exp = 1;
    for (i=0; i<n; i++)
    {
        if(vec[i] > maior)
            maior = vec[i];
    }
    while (maior/exp > 0)
    {
        Contagem(vec,n,exp);
        exp = exp * 10;
    }
}
