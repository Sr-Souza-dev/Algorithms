#include "dijkstra.hpp"

int main(){
    Graph graph = defGraphAdj();    
    printGraph(graph);

    // Testando Algoritmo de Dijkstra
    dijkstra(graph, 4, 10);
}