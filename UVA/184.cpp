#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int gcd(int a, int b) {return (b == 0) ? a : gcd(b, a % b); }

pii slope(pii a, pii b) {
  int x = a.first - b.first;
  int y = a.second - b.second;
  int g = gcd(abs(x),abs(y));
  if(x==0)return {0,1};
  if(y==0)return {1,0};
  if(x<0) x=-x, y=-y;
  return {x/g,y/g};
}

int main() {
  bool prev_zero=0;
  int x,y;
  vector<pii>v;

  while(scanf("%d %d", &x, &y) == 2){
    if(x==0 && y==0 && prev_zero)break;
    if(x==0 && y==0){
      prev_zero=1;
      sort(v.begin(),v.end());
      map<pair<pii,pii>,bool>taken;

      bool first=1;
      for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
          pii a=v[i], b=v[j];
          pii s = slope(a, b);
          if(taken[{a,s}]) continue;
          vector<pii>col;
          col.push_back(a);
          col.push_back(b);
          for(auto k:v) {
            if(k==a || k==b) continue;
            if(slope(a,k)==s)col.push_back(k);
          }

          if(col.size()>2){
            if(first) printf("The following lines were found:\n"), first=0;
            for(auto k:col) printf ("(%*d,%*d)", 4, k.first, 4,k.second); printf("\n");
            for(auto k:col)taken[{k,s}]=1;
          }
        }
      }
      if(first) printf("No lines were found\n");
      v.clear();
      continue;
    }
    prev_zero=0;
    v.push_back({x,y});
  }
}
