-- Faça uma função que receba três notas de um aluno, e calcule e retorne a média aritmética
-- das notas e a situação do aluno, dada pela tabela a seguir.

prompt :: Read a => String -> IO a
prompt msg = do putStr msg
readLn
main :: IO ()
main = do hSetBuffering stdout NoBuffering
n1 <- prompt "Nota 1: "
n2 <- prompt "Nota 2: "
n3 <- prompt "Nota 3: "
let media = (n1 + n2 + n3)/3
putStrLn ("Média: " ++ mostra media)
putStr "Situação: "
if media < 3
then putStrLn "reprovado"
else if media < 7
then putStrLn "exame especial"
else putStrLn "aprovado"