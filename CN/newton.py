import math
import numpy as np


def f(x):
    # colocamos aq a funcao
    f = x**3 - 9*x +3
    return f
    # return pow(x,2)-math.exp(x)

def daf(x):
    # derivada da funcao
    daf=3*x**2 - 9
    return daf
    # return 2*x-math.exp(x)

def dnf(x):
    h=1e-8
    dnf=(f(x+h)- f(x))/h
    return dnf

# o x aq é o valor inicial
x=0.5
k=0
# aqui colocamos a derivada da função
tol=1e-3
# tol =2*x- math.exp(x)

while abs(f(x))>tol:
    print(x,f(x))
    x= x- f(x)/dnf(x)
    k+=1
    
print(k,x,f(x))
print("o resultado é",x)

