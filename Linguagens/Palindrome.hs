module Main (main) where
main :: IO ()
main = do putStrLn "Digite uma frase:"
frase <- getLine
if frase == reverse frase
then putStrLn "É uma palíndrome."
else putStrLn "Não é uma palíndrome."