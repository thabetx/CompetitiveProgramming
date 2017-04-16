#include <iostream>
#include <vector>

using namespace std;

#define f first
#define s second.first
#define t second.second

int main(){
  vector<pair<int, pair<int,int>>>v(16);
  for(int i=0; i<16; i++) cin>>v[i].f>>v[i].s>>v[i].t;
  int x,y,z;
  while(cin>>x>>y>>z){
    if(x==-1)break;
    pair<int, pair<int,int>>ans;
    int mn=1000000000;
    for(auto i:v){
      double d = (i.f-x)*(i.f-x) + (i.s-y)*(i.s-y) + (i.t-z)*(i.t-z);
      if(d<mn) mn=d, ans=i;
    }

    printf("(%d,%d,%d) maps to (%d,%d,%d)\n", x, y, z, ans.f, ans.s, ans.t);


  }

}