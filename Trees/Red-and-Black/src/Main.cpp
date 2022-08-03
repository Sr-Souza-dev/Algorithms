#include <stdio.h>
#include <stdlib.h>
#include "Arvore.hpp"

int main()
{
	Tree *raiz = CreateTree();
	int aux = 10;
	Record record;

	do{
		cout<<"\n----------_Escolha um adas opções abaixo_---------------"<<endl;
		cout<<"Digite [1] para cadastrar um produto no sistema"<<endl;
		cout<<"Digite [2] para vender um produto cadastrado no sistema"<<endl;
		cout<<"Digite [3] para visualizar os produtos cadastrados"<<endl;
		cout<<"Digite [4] para visualizar a construção da arvore de forma binaria"<<endl;
		cout<<"Digite [0] para finalizar o programa"<<endl;
		cin>>aux;

		switch (aux)
		{
			case 1:
				cin.ignore();
				cout<<"\nDigite o nome do Produto: ";
				getline(cin,record.nome);
				cout<<"Digite a quantidade de unidades do Produto: ";
				cin>>record.quantidade;
				cout<<"Digite o código do Produto: ";	
				cin>>record.value;
				cout<<"Digite o código da nota fiscal: ";
				cin.ignore();
				getline(cin,record.nota);
				cout<<"Digite a data da nota fiscal (xx/xx/xxxx): ";
				getline(cin,record.data);
				if(insertTree(&raiz, record) == 1)
					cout<<"\n Produto cadastrado com sucesso! "<<endl;
				else	
					cout<<"\n Não foi possivel cadastrar o Produto! "<<endl;
			break;

			case 2:
				cout<<"\nDigite o código do produto a ser vendido: ";
				cin>>record.value;
				cout<<"Digite a quantidade unitaria do produto a ser vendido: ";
				cin>>record.quantidade;
				if(vender(&raiz, record, record.quantidade))
					cout<<"\n Venda realizada com sucesso!"<<endl;
				else	
					cout<<"\n Não foi Possivel efetuar a venda do produto! (Produto não encontrado)"<<endl;
			break;

			case 3:
				cout<<"\n-------------_Produtos Cadastrados_-----------------"<<endl;
				showTreeInOrder(raiz);
			break;

			case 4:
				cout<<"\n--------------_Arvore com codigo dos produtos (Raiz mais a Esquerda)_---------------"<<endl;
				print2D(raiz);  
				cout<<"\n-------------------------------------------------------------------------------------\n"<<endl;
			break;

			case 0:
				cout<<"\nObrigado por utilizar nosso sistema !"<<endl;
			break;
			
			default:
				cout<<"\nOpção inválida!"<<endl;
			break;
		}

	}while(aux != 0);
	return 0;
}
