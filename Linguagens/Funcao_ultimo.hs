-- Defina uma função chamada ultimo que seleciona o último elemento de uma lista não
-- vazia, usando as funções do prelúdio.

ultimo lista = head (reverse lista)
ultimo’ lista = lista !! (length lista - 1)
ultimo’’ lista = head (drop (length lista - 1) lista)