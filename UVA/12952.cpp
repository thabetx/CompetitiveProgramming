#include <iostream>

using namespace std;

int main(){
  int x,y;
  while(cin>>x>>y){
    if(x==y)cout<<x<<endl;
    else cout<<max(x,y)<<endl;
  }
}