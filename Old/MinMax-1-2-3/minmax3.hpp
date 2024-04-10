#include "stdio.h"
#include "stdlib.h"

void maxmin3(int *vet, int n)
{
	int FimDoAnel,max,min,i=2;

    if(n%2>0){                      // Se tamanho do vetor for impar
        vet[n]  = vet[n-1];
        FimDoAnel = n;
    }
    else FimDoAnel = n-1;

    if(vet[0]>vet[1]){
        max = vet[0];
        min = vet[1];
    }
    else{
        max = vet[1];
        min = vet[0];	
    }

    while(i<=FimDoAnel){
        if(vet[i]>vet[i+1]){
            if(vet[i]>max)max = vet[i];
            if(vet[i+1]<min)min = vet[i+1];
        }
        else{
            if(vet[i+1]>max)max = vet[i+1];
            if(vet[i]<min)min = vet[i];
        }
        i = i+2;
    }

	printf("O maximo valor do vetor é: %d \n",max);
	printf("O minimo valor do vetor é: %d \n",min);
}