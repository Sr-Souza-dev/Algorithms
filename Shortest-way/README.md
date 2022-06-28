# Menor Caminho em um Grafo
O problema de caminho mínimo considera um grafo ponderado, tal que seus pesos representam o custo para caminhar de um nó ao outro. O objetivo deste problema é minimizar o custo partindo de um nó 's' até um nó 'k'.
Tal problema poderia ser representado e solucionado por algoritmos de programação linera inteira (como o simplex), porém como a complexidade desse algoritmo é muito alta (pode atingir custo de tempo exponencial), alguns algoritmos foram desenvolvidos para solucionar este problema, dentre eles temos os de: Edsger W. Dijkstra, Bellman Ford e Floyd Warshall

## Dijkstra
Esse algoritmo foi proposto em 1959 por Edsger W. Dijkstra com o intuito de encontrar o caminho mínimo de grafos ponderados com somente arcos positivos. Para tal feito, este algoritmo define algumas estruturas principais para seu funcionamento, sendo elas:

1. Conjunto R: São os nós ja visitados do grafo, ou seja, são os nós que ja se conhece e sabe-se o custo para partir dele até seus adjacentes. 
2. Conjunto Q: É o complementar de R, ou seja, são os nós que ainda não foram visitados, portanto ainda não se conhece o custo para chegar aos seus adjacentes a partir dele. 
3. Vetor D: É um vetor com o custo de um determinado nó 's' até outro nó 'i'. Esse vetor é iniciado com todos os valores tendendo ao infinito visto que a priori não se sabe o custo de nenhum caminho.
4. Vetor P: É um vetor que indica quem é o predecessor de 'i', ou seja, a partir de qual elemento eu consigo chegar em 'i' com o menor custo conhecido. 

Tendo conhecimento das estruturas acima, o algoritmo de Dijkstra inicializa com os conjuntos: R vazio e Q com todos os nós, e os vetores D e P nulos (na pratica infinito e -1). Feito isso, esse algoritmo pega o nó origem e atualiza o custo e os predecessores de seus adjacentes, em seguida, ele verifica no conjunto Q o nó de menor custo e o explora de forma similar ao nó inicial (atualizando os vetores R e Q de seus adjacentes). Esse sequência é repetida até que o nó escolinho como sendo o de menor custo for o nó destino. 

    Melhor Caso: O(N log N);
    Pior Caso: O(N^2);

<img src="images/Dijkstra_Animation.gif">

## Bellman Ford
Sendo considerado uma generalização do algoritmo de Dijkstra, esse algoritmo também encontra o caminho mínimo em um grafo, diferenciando apenas com a inserção de um vetor 'H' que é responsável por contabilizar quantas vezes um determinado nó foi analizado, ou seja, com esse algoritmo é possivel encontrar o caminho mínimo de um grafo que tenha custos negativos em suas arestas (arcos) desde que não haja ciclos negativos. Para tal feito, ele caminha igualmente ao algoritmo de Dijkstra, porém quando o predecessor 'x' de um nó 'i' é atualizado e se esse nó 'i' estiver no conjunto de nós já visitados (R), então esse nó 'i' retorna para o conjunto de nós desconhecidos (Q) e acrescenta-se uma unidade no seu contador do vetor 'H'. Esse processo é realizado até que não haja mais elementos no conjunto de nós desconhecidos (Q). 


    Melhor Caso: O(V E) -> O(N^2), tal que V é a quantidade de vertices e E a quantidade de arestas;
    Pior Caso: O(N^3);

<img src="images/bellmanfordGF.jpeg">

### Exemplo Caminho Mínimo (Dijkstra e Bellman Ford)

| <div><img src="images/Dijkstra.jpg"></div> | <img src ="images/BellmanFord.jpg"> |
| -------- | ------- |

