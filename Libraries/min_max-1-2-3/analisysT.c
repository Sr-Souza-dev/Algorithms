#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define n 1000000
void maxmin1(int *vet)//*vet passa o vetor como referencia usando ponteiro
{
	clock_t t1,t2;
	t1=clock();			//depois da declaraçao e antes do loop for

	int max=vet[0],min=vet[0];
	for(int i=1;i<n;i++)
	{	
		if(vet[i]>max)
		{
			max=vet[i];
		}
		if(vet[i]<min)
		{
			min=vet[i];
		}
	}
	printf("\nCaso 1\n");
	printf("O maximo valor do vetor é: %d \n",max);
	printf("O minimo valor do vetor é: %d \n",min);

	t2 = clock();// depois dos prints e for
	float t=(((float)t2-(float)t1)/1000000.0f);
	printf("Tempo de execucão: %f \n",t);
}
void maxmin2(int *vet)
{
	clock_t t1,t2;
	t1=clock();
	
	int max=vet[0],min=vet[0];
	for(int i=1;i<n;i++)
	{
		if(vet[i]>max)
		{
			max=vet[i];
		}
		else if(vet[i]<min)
		{
			min=vet[i];
		}
	}
	printf("\nCaso 2 \n");
	printf("O maximo valor do vetor é: %d \n",max);
	printf("O minimo valor do vetor é: %d \n",min);

	t2 = clock();// depois dos prints e for
	float t=(((float)t2-(float)t1)/1000000.0f);
	printf("Tempo de execucão: %f \n",t);


}
void maxmin3(int *vet)
{
	clock_t t1,t2;
	t1=clock();
	int FimDoAnel,max,min;

	if(n%2>0)
	{
		vet[n]=vet[n-1];
		FimDoAnel =n;
	}
	else
	{
		FimDoAnel =n-1;
	}
	if(vet[0]>vet[1])
	{
		max = vet[0];
		min = vet[1];
	}
	else
	{
		max = vet[1];
		min = vet[0];	
	}

	int i=2;
	while(i<=FimDoAnel)
	{
		if(vet[i]>vet[i+1])
		{
			if(vet[i]>max)
			{
				max = vet[i];
			}
			if(vet[i+1]<min)
			{
				min = vet[i+1];
			}
		}
		else
		{
			if(vet[i+1]>max)
			{
				max = vet[i+1];
			}
			if(vet[i]<min)
			{
				min = vet[i];
			}
		}
		i = i+2;
	}
	printf("\nCaso 3 \n");
	printf("O maximo valor do vetor é: %d \n",max);
	printf("O minimo valor do vetor é: %d \n",min);

	t2 = clock();// depois dos prints e for
	float t=(((float)t2-(float)t1)/1000000.0f);
	printf("Tempo de execucão: %f \n",t);
}

//rand começa no 0 adiciona-se 1 no final do rand para contabilizar o ultimo numero antes dele
int main()
{
	int vet[n];
	//srand(); troca a semente randomica
	for(int i=0;i<n;i++)
	{
		vet[i]= rand()%1000001;
	}
	maxmin1(vet);
	maxmin2(vet);	
	maxmin3(vet);	
	return 0;
}
