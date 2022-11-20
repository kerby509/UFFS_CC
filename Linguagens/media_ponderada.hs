-- Faça uma função que recebe as três notas, calcula a média ponderada e exibe o conceito
-- obtido pelo aluno conforme a tabela abaixo.

media2 :: Double -> Double -> Double-> Double-> Double -> Double-> Double
media2 x y z p1 p2 p3 = (x*p1+y*p2+z*p3)/(p1+p2+p3)
