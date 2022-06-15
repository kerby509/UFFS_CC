import math

def comparar(x,xk,eps):
  soma = 0
  zip_object = zip(x, xk)
  for list1_i, list2_i in zip_object:
    soma = soma + math.fabs(list1_i-list2_i)