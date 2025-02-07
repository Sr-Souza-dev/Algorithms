## Descrição
Olá, meu nome é Gabriel Rosa. No momento, sou estudante de Engenharia de Computação no CEFET-MG. Este repositório busca armazenar todos as estruturas de dados estudadas por mim... Qualquer dúvida ou detalhe que deseja tratar sobre estes documentos, sinta-se a vontande para propor algo ou entrar em contato. </br> Att. Gabriel.

![ref](https://github.com/black-shadows/Cracking-the-Coding-Interview/tree/master)

## Introdução
Informalmente, um algoritmo é qualquer procedimento computacional bem definido que objetiva solucionar algum problema computacional bem especifico, ou seja, a partir de um conjunto de valores como entrada ele produz algum(s) conjunto(s) de valor(es) como saída. Diz-se que um algoritmo é correto se, para toda instância de entrada, ele retornar uma saída correta

## Complexidade
A complexidade (T(n)) de um algoritmo é dificilmente mensurada de forma precisa (devido a dificuldade em determinados casos). Para facilitar essa tarefa sem perder o real significado de complexidade, o alemão Edmund Landau desenvolveu a teoria da complexidade (que em sua essência, objetiva restringir o dominio de complexidade de uma função atravez de equações matemáticas simples). <br>
Supondo que um determinado algoritmo tenha custo de **T(n) = 4n^2 + 2n + 3**, a teória da complexidade diz que um único termo da função é capaz de expressar determinado custo de forma simples sem muitas perdas para valores de 'n' tendendo ao infinito, ou seja, um único termo se torna tão grande a partir de determinado 'n' que o resto da função T(n) se torna despresivel.

![](images/complexNotation.jpeg)

#### Big O notation
A notação big O é a mais utilizada no ramo da computação, pois ela descreve de forma clara e fácil um 'limite assintótico' que é capaz de expressar o pior caso de execução de um algoritmo, sendo assim possivél análisar/garantir condições em que um algoritmo pode ser aceito. 
<br>
Para que essa notação seja aceita, é preciso garantir que:

```sh
f(x) = O(g(x)) se e somente se |f(N)| <= C|g(N)| para todo N > n0 
```

![](images/funcO.jpeg)

    É necessário que exista um 'C', tal que Cg(N) >= f(N) a partir de um determinado n0.

As funções mais comuns podem ser visualizadas abaixo com seus respectivos gráficos. (Na imagem abaixo a função fatorial não foi expressa, mas ela é mais custosa do que a exponecial "!n > c^n").

| ![](images/Onotation.jpeg) | ![](images/cus.jpg) |
| ---- | ---- |

Essa notação é comumente utilizada em maratonas de programação em que a performace do algoritmo influência diretamente na sua aceitabilidade. Na imagem abaixo é possivel visualizar uma aproximação de entradas sobre cada complexidade admissível no âmbito competitivo.

<a href="https://www.youtube.com/watch?v=cu3kKbkEZSw&list=PLU2KWF7n4KZzvYwAk7h2LAx4Td0kadh-T&index=3"><img src="images/custo.png"></a>


## Classes de problemas 
Diz-se que a complexidade de um problema computacional é o consumo de tempo e espaço do melhor algoritmo pssível para o problema. É válido salientar que para muitos problemas, o melhor algoritmo conhecido está longe de de ser o melhor algoritmo possível. Tendo como base os algoritmos já conhecidos, foi feita a classificação dos algoritmos nas seguinted classes: P, NP, NP-completo e Np-difícil.

#### P (polynomial time)
É uma classe de problemas (de decisão) que podem ser resolvidos em tempo polinomial com uma maquina de Turing deterministica, ou seja, se seu consumo de tempo no pior caso de execução possível é limitado por uma função polinomial do tamanho das instâncias do problema. Em outras palavras, o algoritmo é polinomial se existe um número 'i-esimo' para todas as instâncias, tal que o consumo de tempo do algoritmo é  '**Ο(N^i)**'.
<br>
Adota-se polinomial como definição de razoavelmente rápido, devido a classe dos polinômios exclui as funções exponenciais, como '2^N', e principalmente porque a classe é fechada sob as operações de 'adição', 'multiplicação' e 'composição', o que permite combinar algoritmos polinomiais de várias maneiras sem que as combinações deixem de ser polinomiais.

#### NP (nondeterministic polynomial time)
É possivel verificar a resposta em tempo polinomial, mas encontrar a responta já é algo muito trabalhoso (é fácil reconhecer/verificar uma solução de uma instância do problema quando se está diante de uma).
* Esses problemas podem ser solucionados em tempo polinomial se usada uma maquina de Turing não-determinística 

##### NP-completo
Se a partir de um problema 'B' pertencente a classe 'NP' for possível reduzir (em tempo polinomial) em outro problema 'A' pertencente  a classe 'NP', então, é possivel afirmar que B é 'NP-completo'
* São os mais dificeis da class NP

##### NP-difícil (NP-hard)
Segue o mesmo padrão que os problemas NP-completo, mas engloba a classe de problemas de otimização. (Pode haver problemas np-difíceis que não estão na class NP)

#### P == NP?
Como já observamos, P ⊆ NP, ou seja, todo problema polinomial de decisão é polinomialmente verificável. O bom-senso sugere que P é apenas uma pequena parte de NP. Surpreendentemente, ninguém encontrou ainda um problema de NP que seja não polinomial (embora existam muitos candidatos).
<br>
A propósito, o Instituto Clay de Matemática oferece um prêmio de um milhão de dólares pela solução da questão 'P==NP'?.

<a href="https://gizmodo.uol.com.br/problema-matematica-roubar-bitcoins/"><img src="images/p-versus-np.png"><a>





## Referências
<a href="https://www.amazon.com.br/Algoritmos-Teoria-Pr%C3%A1tica-Thomas-Cormen/dp/8535236996/ref=asc_df_8535236996/?tag=googleshopp00-20&linkCode=df0&hvadid=379707181411&hvpos=&hvnetw=g&hvrand=17219642873615724507&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9101167&hvtargid=pla-1002925180312&psc=1"> Algoritmos / Thomas H. Cormen </a> <br>
<a href="https://www.amazon.com.br/Estruturas-dados-usando-Aaron-Tenenbaum/dp/8534603480/ref=asc_df_8534603480/?tag=googleshopp00-20&linkCode=df0&hvadid=379720423869&hvpos=&hvnetw=g&hvrand=17178851799298766701&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9101167&hvtargid=pla-811023936931&psc=1"> Estrutura de dados usando C / Aaron M. Tenenbaum </a> <br>
