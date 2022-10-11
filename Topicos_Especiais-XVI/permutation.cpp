#include <iostream>

using namespace std;
 
int main(){
	int n; cin>>n;
	if(n==1) cout<<1<<"\n";
	else if(n==2 || n==3) cout<<"NO SOLUTION"<<"\n";
	else if(n==4) cout<<3<<" "<<1<<" "<<4<<" "<<2<<"\n";
	else{
		for(int i=n;i>0;i-=2) cout<<i<<" ";
		for(int i=n-1;i>0;i-=2) cout<<i<<" ";
	}
	return 0;
}



// como 1 não tem adjacente, quer dizer q nao faz parte dos numeros que tem uma boa permutação, então cada vez que digita 1, vai retorna 1

// caso n=2, ou n= 3 ou seja <4 o programa vai printar no solução , para ter uma boa permutação o numero 2 deveria pelo menos proximo do numero 3, más as vezes as adjacentes sempre tem diferença

// descrecenta aq cada vez pq a diferença sempre 2 de todos os elemtos adjacentes, que um elemento tem nesses segmentos