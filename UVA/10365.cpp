#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n;cin>>n;
  while(n--){
    int x;
    cin>>x;
    int mn=2+4*x;
    int s=sqrt(x)+3;
    for(int i=1; i<=s; i++){
      if(x%i==0){
        int rem=x/i;
        int s2=sqrt(rem)+3;
        for(int j=1; j<=s2; j++){
          if(rem%j==0){
            int k=rem/j;
            mn=min(mn, 2*(i*j + j*k + i*k));
          }
        }
      }
    }
    cout<<mn<<endl;
  }
}