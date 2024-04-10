#include <stdio.h>
#define N 10

typedef struct lista{
	int dados[N];
	int p1,p2;
}lista;

void limpar(lista *l)
{
	l->p1=0;
	l->p2=0;
}

void inserir(lista *l, int num)
{
	if(l->p2>=N)
	{
		printf("FULL!\n");
	}
	else
	{
		l->dados[l->p2]=num;
		l->p2++;
		printf("Dado inserido com sucesso!\n");
	}
}

void remover(lista *l, int num)
{
    
	if(l->p1!=l->p2)
	{
		int aux=0;

		for(int i=l->p1; i<l->p2; i++)
		{
			if(l->dados[i]==num)
			{
				for(int j=i; j<l->p2; j++)
				{
					l->dados[j]=l->dados[j+1];
				}
				l->p2--;
				printf("Dado removido com sucesso!\n");
				aux++;
				break;
			}
		}
		if(aux==0)
		{
			printf("Elemento não encontrado!\n");
		}
	}
	else
		{printf("A lista está vazia! \n");}
}

void procurar(lista *l, int num)
{
	if(l->p1!=l->p2)
	{
		
			int aux=0;
			for(int i=l->p1; i<l->p2; i++)
			{
				if(l->dados[i]==num)
				{
					printf("Dado %d encontrado na posição %d \n",l->dados[i],i+1);
					aux++;
					break;
				}
			}
			if(aux==0)
			{
				printf("Dado não encontrado!\n");
			}		
	}
	else
		{printf("A lista está vazia! \n");}
}

void imprimir(lista *l)
{
	for(int i=l->p1; i<l->p2; i++)
	{
		printf("%d: ",l->dados[i]);
	}
	printf("\n");
}

int main()
{
	lista l;
	int num, aux=0;

	limpar(&l);
	do{
		printf("\n--------ESCOLHA UMA OPÇÃO ABAIXO-----------\n");
		printf("Digite [1] para limpar a lista\n");
		printf("Digite [2] para inserir dados da lista\n");
		printf("Digite [3] para remover dados da lista\n");
		printf("Digite [4] para procurar na lista\n");
		printf("Digite [5] para imprimir lista de dados\n");
		printf("Digite [0] para finalizar o programa\n");
		scanf("%d",&aux);

		switch (aux)
		{
			case 1:
				limpar(&l);
			break;

			case 2:
				printf("Digite o número que deseja inserir: ");
				scanf("%d",&num);
				inserir(&l,num);
			break;

			case 3:
				printf("Digite o número que deseja remover: ");
				scanf("%d",&num);
				remover(&l,num);
			break;

			case 4:
				printf("Digite o número que deseja procurar: ");
				scanf("%d",&num);
				procurar(&l,num);
			break;

			case 5:
				imprimir(&l);
			break;

			default:
				if(aux!=0)
					printf("Opção inválida! \n");
			break;
		}

	}while(aux!=0);
	return 0;
}