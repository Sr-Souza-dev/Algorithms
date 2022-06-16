## Quadratic Complexity

#### Bubble Sort
Em uma ordenação crescente, esse algoritmo tem como ideia principal levar sempre os maiores valores para o final do vetor/array, já em ordem decrescente o algoritmo levará sempre o menor valor para a ultima posição do vetor/array. Ele verifica casa a casa e compara se o elemento reservado é o menor que a posição atual, caso seja, ele atualizará o elemento reservado com o atual e continuará caminhando até chegar na ultimaa posição ordenada ou fim do array.
<a href="https://github.com/Sr-Souza-dev/Algorithms/blob/main/Ordination/bubble_sort.hpp">ver código</a>

    Melhor Caso: O(N);
    Pior Caso: O(N^2);
    Não Recomendado para grandes conjuntos de dados
<br>
<a href="https://www.macoratti.net/20/11/c_algoritm2.htm"> <image src = "images/bubble.png"></a>


#### Selection Sort
Em uma ordenação crescente, esse algoritmo tem como ideia principal buscar sempre o menor valor e move-lo para o inicio, ou seja, ele procura primeiramento o menor valor presente no array e após encontra-lo, faz uma troca com a primeira posição deseordenada do array. 
<a href="https://github.com/Sr-Souza-dev/Algorithms/blob/main/Ordination/selection_sort.hpp">ver código</a>

    Melhor Caso: O(N);
    Pior Caso: O(N^2);
    Não Recomendado para grandes conjuntos de dados
<br>
<a href="https://www.codingninjas.com/codestudio/problem-details/selection-sort_981162"> <image src = "images/selection.png"></a>

#### Insertion Sort
Esse algoritmo (de forma grosseira) reduz o problema ao mínimo possível e ordena uma pequena sub-lista (de forma analoga ao selection sort ele pega o novo valor adicionado e começar a comparar do final da sub-lista até encontrar a posição de ordenação), após essa ordenação, ele pega o proximo elemento faltante da lista real e repete os passos até que o tamanho da lista ordenada é do mesmo tamanho da lista real.
<a href="https://github.com/Sr-Souza-dev/Algorithms/blob/main/Ordination/insertion_sort.hpp">ver código</a>

    Melhor Caso: O(N);
    Pior Caso: O(N^2);
    Não Recomendado para grandes conjuntos de dados
<br>
<a href="https://www.w3resource.com/javascript-exercises/searching-and-sorting-algorithm/searching-and-sorting-algorithm-exercise-4.php"> <image src = "images/insertion.png"></a>

#### Shell Sort
Sendo considerado um refinamento do método Insertion Sort, o Shell Sort define uma constante 'h' para definir o tamanho dos passos a serem executados. O tamanho desses passos podem ser definidos atravéz de uma heuristica suposta pelo desenvolvedor, alguns costumam começar com 'h' igual ao tamanho do vetor a ser ordenado, outros com metade desse tamanho... Após definir o tamanho de 'h', é feita uma comparação a cada dois elemento com distância 'h' sem repetir elementos, finalizando as comparações, o h é reduzido por outra heuristica que fisa encurtar o tamanho desses passo. Esta sequência é repetida até que se tenha 'h' = 1 (passos de tamanho 1), o que significa que esse algoritmo se comportará de forma similar ao insertion sort.
<a href="https://github.com/Sr-Souza-dev/Algorithms/blob/main/Ordination/shell_sort.hpp">ver código</a>

A complexidade desse algoritmo ainda não é conhecida devido a incapacidade de encontrar uma fórmula fechada para sua função de complexidade, portanto são feitas algumas conjecturas referentes ao número de comparações para a sequeência de Knuth, sendo elas:

    Conjectura 1: O(N^{1.25});
    Conjectura 2: O(N (ln N)^2);
    Recomendado para uma quantidade moderada de dados
<br>
<a href="https://www.youtube.com/watch?v=QnHOwrZllXk"> <image src = "images/shell.png"></a>

#### Analysis
Você pode acessar o algoritmo que chama todos os métodos de ordenação quadrática <a href="https://github.com/Sr-Souza-dev/Algorithms/blob/main/Ordination/analysisqd.cpp">clicando aqui</a>, nele o mesmo vetor é ordenado por diversos métodos gerando uma saída de quantas interações em um laço foram gastas.

Para simular a execução basta efetuar o download deste diretorio e abrir o terminal nesta pasta, digitando os seguintes comandos.

    1. g++ analysisqd.cpp -o analysisqd
    2. ./analysisqd


## Logarithmic Complexity

#### Merge Sort 
Baseado na técnica dividir para conquistar, esse algoritmo vai dividindo (na maioria das vezes por 2) o vetor/lista em estruturas de árvore cada vez menores, até chegar em um nó 'folha' com um único elemento. Após toda divisão do vetor/lista esse algoritmo inicializa a etapa de junção começando dos nós folhas e subindo nível a nível e ordenando a lista em cada um deles, visto que a cada nível alcançado a lista fica maior, ao chegar na raiz da arvore nosso vetor/lista já estará ordenado.

O metodo Merge Sorte normalmente gera uma arvore binária que a cada divisão os filhos de cada nó tendem a ter metade de elementos do nó pai. O metodo de junção começa pelas folhas e trata cada nó folha como uma pilha, tal que para subir um nível, ele compara o topo de uma pilha com o topo de outra (assim fazendo a ordenação da sub-lista no nó pai), feito isso ele sobe até esse nó pai que agora se torna um nó folha da arvore. Esse processo é feito até que se tenha uma lista toda ordenada.
<a href="https://github.com/Sr-Souza-dev/Algorithms/blob/main/Ordination/merge_sort.hpp">ver código</a>

    Melhor Caso: O(N (ln N));
    Pior Caso: O(N (ln N));
<br>
<a href="https://en.wikipedia.org/wiki/Merge_sort"> <image src = "images/merge.png"></a>

#### Quick Sort 
Esse método utiliza de preceitos parecidos com o do Merge Sorte, aqui, esse algoritmo primeiramente define um 'Pivô' (que tem um impacto direto no tempo de execução do algoritmo) e coloca todos os números que são menores a esse 'pivô' a sua esquerda e todos números maiores a sua direita. Após ter uma lista separada pelo 'pivô', são geradas sub-listas, uma correspondente a cada lado do 'pivô'. Feito essa separação, o método Quick Sorte é chamado novamente em cada uma das sub-listas (visto que a outra lista não importa, pois sabe-se que todos os elementos da outra lista serão maiores ou menores em comparação a todos da lista atual). Esse processo é repetido até o ter-se a lista completamente ordenada.

Na realidade, para evitar o custo de ficar transitando com o 'pivô' por toda lista são delimitadas arrows que percorrem a lista a medida que a separação é feita. No qual todos os valores a esquerda da arrow mais a direita (arrow_right) até a arrow mais a esquerda (arrow_left) são maiores do que o 'pivô', e todos os valores a esquerda da arrow_left são menores do que o pivô, assim, será necessário movimentar o 'pivô' somente uma vez. 
<a href="https://github.com/Sr-Souza-dev/Algorithms/blob/main/Ordination/quick_sort.hpp">ver código</a> (Como essa ordenação ocorre em relação ao pivô pode ser visualizada na imagem abaixo)

<a href="https://github.com/Sr-Souza-dev"> <image src = "images/quickP.png"></a>

    Melhor Caso: O(N (log N));
    Pior Caso: O(N^2);
<br>
<a href="https://dev.to/mwong068/quick-sort-in-ruby-2302"> <image src = "images/quick.png"></a>


#### Heap Sort





Verifica esse site "https://pt.wikipedia.org/wiki/Merge_sort"