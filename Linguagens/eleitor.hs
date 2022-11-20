-- 10. Crie uma função que receba a idade de uma pessoa e informe a sua classe eleitoral:
-- a. “não eleitor” abaixo de 16 anos;
-- b. “eleitor obrigatório” entre 18 (inclusive) e 65 anos;
-- c. “eleitor facultativo” de 16 até 18 anos e acima de 65 anos (inclusive).

module Main (main) where
import System.IO (stdout, hSetBuffering, BufferMode(NoBuffering))
classeEleitoral idade
| idade < 16 = "não eleitor"
| idade >= 18 && idade < 65 = "eleitor obrigatório"
| otherwise = "eleitor facultativo"
main =
do hSetBuffering stdout NoBuffering
putStrLn "Classe eleitoral"
putStrLn "-------------------------------------------"
putStr "Digite a idade da pessoa: "
idade <- readLn
putStrLn (classeEleitoral idade)