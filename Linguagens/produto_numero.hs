-- 5. Escreva uma função que recebe três números em ponto flutuante, calcula e exibe o produto
-- dos números.

module Main (main) where
main :: IO ()
main = do putStrLn "Digite um número: "
n1 <- readLn :: IO Double
putStrLn "Digite outro número: "
n2 <- readLn
putStrLn "Digite outro número: "
n3 <- readLn
putStr "Produto dos números digitados: "
print (n1 * n2 * n3)