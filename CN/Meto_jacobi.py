import math

def comparar(x,xk,eps):
  soma = 0
  zip_object = zip(x, xk)
  for list1_i, list2_i in zip_object:
    soma = soma + math.fabs(list1_i-list2_i)
    
  if (soma < eps):
        return True
  else:
     return False  
 
 
def gaussJacobi(A,b,maxiter,eps):
     n = len(b)
     sol = True
     x = b.copy()
     for i in list(range(1,n+1,1)):
        if (math.fabs(A[i-1][i-1]) > 0.0):
            x[i-1] = b[i-1]/A[i-1][i-1]
        else:
            sol = False
        break