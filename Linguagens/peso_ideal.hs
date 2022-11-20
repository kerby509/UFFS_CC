--  Escrever uma função que recebe a altura (h) e o sexo (s) de uma pessoa e calcula e mostra o
-- seu peso ideal, utilizando as fórmulas constantes na tabela a seguir.

module Main (main) where
import System.IO (stdout, hSetBuffering, BufferMode(NoBuffering))
import Data.Char (toUpper)
main :: IO ()
main = do hSetBuffering stdout NoBuffering
putStr "Altura: "
h <- readLn
putStr "Sexo (f/m): "
s <- getLine
case toUpper (head s) of
’F’ -> putStrLn ("Peso ideal: " ++ show (62.1 * h - 44.7))
’M’ -> putStrLn ("Peso ideal: " ++ show (72.7 * h - 58))
