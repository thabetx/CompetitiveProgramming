#include <bits/stdc++.h>
using namespace std;

vector<string> decompose(string s){
  vector<string>v;
  int cnt=0;
  string buf="";
  for(auto i:s){
    buf+=i;
    if(i=='0')cnt++;
    else cnt--;
    if(cnt==0)v.push_back(buf.substr(1,buf.size()-2)),buf="";
  }
  return v;
}

bool match(string a, string b){
  if(a==b)return true;
  if(a.size()!=b.size())return false;

  vector<string>da=decompose(a), db=decompose(b);
  if(da.size()!=db.size())return false;

  vector<bool>done(db.size());
  for(auto i:da){
    bool ok=0;
    for(int j=0; j<db.size(); j++){
      if(!done[j] && match(i,db[j])){
        done[j]=1, ok=1;
        break;
      }
    }
    if(!ok)return false;
  }
  return true;
}

int main() {
  int t;cin>>t;
  while(t--){
    string a,b;
    cin>>a>>b;
    if(match(a,b))cout<<"same\n";
    else cout<<"different\n";
  }
}
