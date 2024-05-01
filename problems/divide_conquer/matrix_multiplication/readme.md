**Definição**
Se você já viu matrizes antes, provavelmente sabe como multiplicá-las. (Caso contrário, deve ler a Seção D.1 no
Apêndice D.) Se A = (a_{ij}) e B = (b_{ij}) são matrizes quadradas n × n, então no produto C = A × B, definimos a entrada
c_{ij}, para i, j = 1, 2, … , n.

Temos de calcular n² entradas de matrizes, e cada uma é a soma de n valores. O procedimento descrito a seguir
toma as matrizes n × n, A e B e as multiplica, retornando seu produto C. 

**Um algoritmo simples de divisão e conquista**
To keep things simple, when we use a divide-and-conquer algorithm to compute
the matrix product C = A * B, we assume that n is an exact power of 2 in each of
the n x n matrices. We make this assumption because in each divide step, we will
divide n 	 n matrices into four n/2 x n/2 matrices, and by assuming that n is an
exact power of 2, we are guaranteed that as long as n >= 2, the dimension n/2 is an
integer.