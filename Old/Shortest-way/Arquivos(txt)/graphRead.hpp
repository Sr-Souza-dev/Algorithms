#include <bits/stdc++.h>
using namespace std;

#define INF 999
const int qtdVertice = 15;
const int qtdArestas = 26;

typedef struct graph Graph;

struct graph{
    const int sizeI = qtdVertice;
    const int sizeJ = qtdVertice;
    int mat[qtdVertice][qtdVertice];
};

void printGraph(Graph graph){
    for(int i = 0; i<graph.sizeI; i++){
        for(int j = 0; j<graph.sizeJ; j++){
            printf("| %4d",graph.mat[i][j]);
        }
        printf("|\n");
    }
    printf("\n\n");
}

// Inicializa o Grafo de Matriz de Adjacencia
Graph defGraphAdj(){
    Graph graph;
    for(int i=0; i<graph.sizeI; i++){
        for(int j=0; j<graph.sizeJ; j++){
            graph.mat[i][j] = 0;
        }
    }

    // Definindo Grafo em matriz de adjacencia a partir do arquivo.txt
    vector <string> tokens;
	ifstream arquivo;
	string linha, intermediate;
    arquivo.open("../Arquivos(txt)/adjacencia.txt");

	if(arquivo.is_open())
	{
		while(getline(arquivo,linha))
		{
			stringstream check1(linha);            
			while(getline(check1, intermediate, ','))
			{
				tokens.push_back(intermediate);
			}
			if(int(tokens.size()) == 3) graph.mat[stoi(tokens[0])][stoi(tokens[1])] = stoi(tokens[2]);
			else cout<<"[ERRO] Problemas na estrutura do arquivo!"<<endl;
			tokens.clear();
		}
	} else printf("Deu ruim");
    return graph;
}
