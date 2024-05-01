Nosso primeiro exemplo usa programação dinâmica para resolver um problema simples que é decidir onde cortar hastes de aço (verificar a implementação utilizando programação dinâmica). A Serling Enterprises compra hastes de aço longas e as corta em hastes mais curtas, para vendê-las.

Cada corte é livre. A gerência da Serling Enterprises quer saber qual é o melhor modo de cortar as hastes.

Suponhamos que conhecemos, para i = 1, 2, ..., n o preço pi em dólares que a Serling Enterprises cobra por uma haste de i polegadas de comprimento. Os comprimentos das hastes são sempre um número inteiro de polegadas. A

O problema do corte de hastes é o seguinte. Dada uma haste de n polegadas de comprimento e uma tabela de
preços pi para i = 1, 2, ..., n, determine a receita máxima rn que se pode obter cortando a haste e vendendo os pedaços. Observe que, se o preço pn para uma haste de comprimento n for suficientemente grande, uma solução ótima pode exigir que ela não seja cortada.
