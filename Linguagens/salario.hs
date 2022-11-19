-- Defina uma função que recebe o salário base de um funcionário e resulta no salário líquido a
-- receber, sabendo-se que o funcionário tem gratificação de 10% sobre o salário base e paga
-- imposto de 7% sobre o salário base. Exemplos:

salario :: Float -> Float
salario salBase = salBase + 0.10*salBase - 0.07*salBase