#include <bits/stdc++.h>
using namespace std;

vector<int>merged,ops,v1,v2;

void solve(){
  int cur=v1[0],i=0,j=0;
  vector<int>val;
  while(i<v1.size() || j<v2.size()){
    while(i!=v1.size() && v1[i]==cur){
      merged.push_back(i+1);
      val.push_back(v1[i]);
      i++;
    }
    while(j!=v2.size() && v2[j]==cur){
      merged.push_back(j+1+v1.size());
      val.push_back(v2[j]);
      j++;
    }
    cur=!cur;
  }
  cur=val[0];
  val.push_back(9999);
  for(i=0; i<val.size()-1; i++)
    if(val[i+1]!=val[i])ops.push_back(i+1);
  if(val[val.size()-2]==0)ops.pop_back();
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int s1;cin>>s1; v1.resize(s1);
  for(int i=0; i<s1; i++)cin>>v1[i];

  int s2;cin>>s2; v2.resize(s2);
  for(int i=0; i<s2; i++)cin>>v2[i];

  solve();
  vector<int>m=merged;
  vector<int>o=ops;

  swap(v1,v2);
  merged.clear();
  ops.clear();
  solve();

  if(ops.size()<o.size()){
    m=merged, o=ops;
    for(auto &i:m){
      if(i<=v1.size())i+=v2.size();
      else i-=v1.size();
    }
  }

  for(auto i:m)cout<<i<<" ";cout<<'\n';
  cout<<o.size()<<'\n';
  for(auto i:o)cout<<i<<" ";
}
