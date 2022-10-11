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