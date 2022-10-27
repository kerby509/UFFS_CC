#include <bits/stdc++.h>
using namespace std;

void permute(string str, int l, int r, set<string> &lks){
    if(l==r) lks.insert(str);
    else{
        for(int i = l; i<= r; i++){
            swap(str[l], str[i]);
            permute(str, l+1, r , lks);
            swap(str[l], str[i]);

        }
    }
}

int main() {
    string s;
    cin>> s ;
    set <string> lks;
    permute (s, 0, s.length() -1, lks);
    cout<<lks.size ()<<"\n";
}