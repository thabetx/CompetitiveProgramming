#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<pair<string,string>>v;
  string s;
  set<string>st;
  while(cin>>s){
    if(s=="#")break;
    st.insert(s);
  }

  v.push_back({"0000000","0000000"});
  for(auto s:st){
    string sorted=s;
    for(auto &i:sorted)i=tolower(i);
    sort(sorted.begin(),sorted.end());
    v.push_back({sorted,s});
  }
  sort(v.begin(),v.end());
  v.push_back({"0000000","0000000"});

  set<string>ans;
  for(int i=1;i<v.size()-1;i++)
    if(v[i].first!=v[i-1].first && v[i].first!=v[i+1].first)
      ans.insert(v[i].second);
  for(auto i:ans)cout<<i<<'\n';

}
