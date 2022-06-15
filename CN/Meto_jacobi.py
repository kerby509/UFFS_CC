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
    
     if (sol):
        print("Iteração 0")
        print("x = ",x)
        xk = x.copy()
   # maxiter = 10
    #eps     = 0.01
        iter    = 0
        while (iter < maxiter):
            iter = iter + 1
            for i in list(range(1,n+1,1)):
                 s = 0
                 for j in list(range(1,n+1,1)):
                     if ((i-1) != (j-1)):
                         s = s + A[i-1][j-1]*x[j-1]

                         xk[i-1] = (1/A[i-1][i-1])*(b[i-1]-s)
                         
                         print("Iteração: ",iter)
                         print("xk = ",xk)
                         if comparar(x,xk,eps):
                             x = xk.copy()
                             break    
                         x = xk.copy()
     
   
            return x
        #10,2,1,1,5,1,2,3,10,,7,-8,6
A = [[10, 2,  1],
     [1, 5,  1],
     [ 2,3, 10]]
#aqui colocamos a igualdade da eq
b = [7, -8, 6]

x = gaussJacobi(A,b,1,2)
print("x = ",x)
