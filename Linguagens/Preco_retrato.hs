-- 4. O estúdio fotográfico Boa Imagem cobra de seus clientes por retratos antigos baseando-se
-- no número de indivíduos incluídos no retrato. As tarifas constam da tabela seguinte.
-- Retratos antigos tirados aos sábados ou aos domingos custam 20% a mais do que o preço
-- base. Defina uma função precoRetrato do tipo Integer -> String -> Double que recebe como
-- argumentos o número de pessoas no retrato e o dia da semana agendado, e calcula o custo do
-- retrato. Exemplos:

precoRetrato :: Integer -> String -> Float
precoRetrato individuos diaSemana = precoBase + taxaExtra * precoBase
where
precoBase | individuos == 1 = 100
| individuos == 2 = 130
| individuos == 3 = 150
| individuos == 4 = 165
| individuos == 5 = 175
| individuos == 6 = 180
| otherwise = 185
taxaExtra | diaSemana == "sábado" || diaSemana == "domingo" = 0.2
| otherwise = 0