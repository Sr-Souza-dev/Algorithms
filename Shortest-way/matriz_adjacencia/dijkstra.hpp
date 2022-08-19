#include "../Arquivos(txt)/graphRead.hpp"

int min(vector<int> cost, vector<int> unvisited)
{
	int min=cost[unvisited[0]], position = 0;
    for(int i=1;i<unvisited.size();i++){

        if(cost[unvisited[i]]<min){
			min = cost[unvisited[i]];
            position = i;
		}
    }
	return position;
}

void initializeStructure(vector<int> *unvisited, vector<int> *cost, vector<int> *predecessor, Graph graph, int start){
    for(int i=0; i<graph.sizeI; i++){
        (*unvisited).push_back(i);
        (*cost).push_back(INF);
        (*predecessor).push_back(-1);
    }
    (*cost)[start] = 0;
}

void dijkstra(Graph graph, int start, int end){
    
    vector<int> unvisited, visited, cost, predecessor;
    initializeStructure(&unvisited, &cost, &predecessor, graph, start);
    int current = start, position = start;

    while(current != end && !unvisited.empty()){

        visited.push_back(current);
        unvisited.erase(unvisited.begin()+position);

        for(int i=0; i<graph.sizeI; i++){
            if(graph.mat[current][i] > 0 && cost[i] > cost[current] + graph.mat[current][i]){
                cost[i] = cost[current] + graph.mat[current][i];
                predecessor[i] = current;
            }
        }

        position = min(cost, unvisited);
        current = unvisited[position];
    }

    int i=end, cont=0;
    cout<<" | "<<end;
    while(i!=start && cont < graph.sizeI){
        cout<<" | "<<predecessor[i];
        i = predecessor[i];
        cont++;
    }

    cout<<endl;
}