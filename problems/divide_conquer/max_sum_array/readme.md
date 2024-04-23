**Problema**
Suponha que lhe tenha sido oferecida a oportunidade de investir na Volatile Chemical Corporation. Assim como os
produtos químicos que a empresa produz, o preço da ação da Volatile ChemicalCorporation também é bastante volátil.
Você só pode comprar uma única unidade de ação somente uma vez e então vendê-la em data posterior. Além disso, as
operações de compra e venda só podem ser executadas após o fechamento do pregão do dia. Para compensar essa
restrição, você pode saber qualserá o preço da ação no futuro. Sua meta é maximizar seu lucro. A Figura 4.1 mostra o
preço da ação durante um período de 17 dias. Você pode comprar a ação a qualquer tempo, começando depois do dia
0, quando o preço é $100 por ação. Claro que você gostaria de “comprar na baixa e vender na alta” — comprar ao
preço mais baixo possível e mais tarde vender ao preço mais alto possível — para maximizar seu lucro. Infelizmente,
pode ser que você não consiga comprar ao preço mais baixo e vender ao preço mais alto dentro de um determinado
período. Na Figura 4.1, o preço mais baixo ocorre depois do dia 7, que ocorre após o preço mais alto, depois do dia
1.

Você poderia achar que sempre pode maximizar o lucro comprando ao preço mais baixo ou vendendo ao preço
mais alto. Por exemplo, na Figura 4.1, maximizaríamos o lucro comprando ao preço mais baixo após o dia 7. Se essa
estratégia sempre funcionasse, seria fácil determinar como maximizar o lucro: localizar o preço mais alto de todos e o
preço mais baixo de todos, e então percorrer os dados começando na esquerda a partir do preço mais alto para achar
o preço mais baixo anterior, e examinar os dados começando na direita a partir do preço mais baixo para achar o último
preço mais alto e escolher o par que apresentasse a maior diferença.

**Uma solução de força bruta**
Podemos propor facilmente uma solução de força bruta para esse problema: experimente todo par possível de
datas de compra e venda no qual a data de compra seja anterior à data de venda. Um período de n dias tem (n²) de
tais pares de dados. Visto que (n²) é Θ(n²) e o melhor que podemos esperar é avaliar cada par de dados em tempo
constante, essa abordagem levaria um tempo de Ω(n²).

**Uma transformação**
Para projetar um algoritmo com tempo de execução o(n²), vamos considerar os dados de entrada de um modo
ligeiramente diferente. Queremos determinar uma sequência de dias durante a qual a mudança líquida desde o primeiro
dia até o último é máxima. Em vez de examinar os preços diários, vamos considerar a alteração diária nos preços,
sendo que a mudança no dia i é a diferença entre os preços após o dia i - 1 e após o dia i. A tabela na Figura 4.1
mostra essas mudanças diárias na última linha. Se tratarmos essa linha como um arranjo A, mostrado na Figura 4.3,
vamos querer determinar o subarranjo não vazio contíguo a A cujos valores tenham a maior soma. Denominamos esse
subarranjo contíguo subarranjo máximo. 

***Custo:***  Θ(n lg n).
