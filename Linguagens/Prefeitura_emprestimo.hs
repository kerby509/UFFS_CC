-- A prefeitura de Chapecó abriu uma linha de crédito para os funcionários estatutários. O
-- valor máximo da prestação não poderá ultrapassar 30% do salário bruto. Fazer uma função
-- que permita entrar com o salário bruto e o valor da prestação, e que retorne um booleano
-- indicando se o funcionário pode ou não receber o empréstimo.

module Main (main) where
import System.IO (stdout, hSetBuffering, BufferMode(NoBuffering))
main =
do hSetBuffering stdout NoBuffering
putStrLn "Análise de crédito"
putStrLn "-------------------------------------------"
putStr "Salário bruto: "
salario <- readLn
putStr "Valor da prestação: "
prestação <- readLn
if prestação <= 0.3 * salario
then putStrLn "pode receber o emprestimo"
else putStrLn " não pode receber o emprestimo"