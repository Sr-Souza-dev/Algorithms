#include "stdio.h"
#include "stdlib.h"

void maxmin1(int *vet, int n)
{
	int max=vet[0],min=vet[0];
	for(int i=1;i<n;i++)
	{	
		if(vet[i]>max){
			max=vet[i];
		}
		if(vet[i]<min){
			min=vet[i];
		}
	}

	printf("O maximo valor do vetor é: %d \n",max);
	printf("O minimo valor do vetor é: %d \n",min);
}