-- Defina uma função chamada primeiros que seleciona todos os elementos de uma lista não
-- vazia, exceto o último, usando as funções do prelúdio.

primeiros lista = reverse (tail (reverse lista))