#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll totalSum =0;

// usando a forma recursiva


ll findMin(ll A[], int r, ll currSum){
    // a soma atual é nosso segundo conjunto , é 1 oque
    // esta solução recursiva fez
    // temos uma soma atual para cada estoque de chamadas recursiva 
    //como tu tem uma soma atual e a soma atual for um constante , 
    //então o valor no conjunto séra a soma total- currsum
    if (r==0) // aqui precisamos calcular a diferenca entre conjunto 1 e o conjunto dois
        return abs((totalSum -currSum)- currSum);
// verifica a opção que vai dar o menor valor
    return min(findMin(A,r-1 ,currSum+ A[r-1]), 
    findMin(A,r-1,currSum));
}

void resolve (){
    int n;
    cin >> n;
    ll A[n];

    for (int i=0; i<n; i++){
        cin >> A[i];
        totalSum+= A[i];
    }
    cout<< findMin(A, n, 0)<<"\n";
}

int main (){
    resolve();
}