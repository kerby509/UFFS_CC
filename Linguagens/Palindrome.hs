-- Escreva uma função que recebe uma String e testa se ela representa uma palíndromo,
-- retornando um Bool. Dica: para verificar se uma frase é palíndromo basta verificar se ela é
-- igual à sua reversa.

module Main (main) where
main :: IO ()
main = do putStrLn "Digite uma frase:"
frase <- getLine
if frase == reverse frase
then putStrLn "É uma palíndrome."
else putStrLn "Não é uma palíndrome."