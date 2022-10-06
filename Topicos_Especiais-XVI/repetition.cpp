#include <iostream>
using namespace std;

int main(){
	string N;
  cin>>N; 
  int count=1,ans=1;
	for(int i=0;i<N.length()-1;i++){
		if(N[i]==N[i+1]) count++;
		else count=1;
		ans=max(ans,count);
	}
	cout<<ans<<"\n";
	return 0;
}
 