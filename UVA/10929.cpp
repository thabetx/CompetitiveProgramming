#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  while(cin>>s){
    if(s=="0")break;
    int mod=0;
    for(auto i:s){
      mod*=10;
      mod+=i-'0';
      while(mod>=11)mod-=11;
    }
    if(mod==0) cout<<s<<" is a multiple of 11.\n";
    else cout<<s<<" is not a multiple of 11.\n";
  }
}
