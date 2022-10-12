#include <iostream>

using namespace std;
using ll = long long;

int main(){
	ll n; cin>>n;
	for(int i=1;i<=n;i++){
		//Total number of cell in chessboard
    //Número total de células no tabuleiro
		ll t=i*i;
        //Total number of combination of two places
    //Número total de combinação de dois lugares
		ll k=t*(t-1)/2;
		//Número total de possibilidades que 2 cavaleiros podem atacar um ao outro
		if(i>2) k-=4*(i-1)*(i-2);
		//total de lugares será k
		cout<<k<<"\n";
	}
 
	return 0;
}
 