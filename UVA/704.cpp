#include <bits/stdc++.h>
#include <functional>
using namespace std;

string ll(string s){rotate(s.begin(),s.begin()+2,s.begin()+12);return s;}
string lr(string s){rotate(s.begin(),s.begin()+10,s.begin()+12);return s;}
string rl(string s){rotate(s.begin()+9,s.begin()+11,s.end());return s;}
string rr(string s){rotate(s.begin()+9,s.begin()+19,s.end());return s;}

string sol;
map<long long, string>mp;
const string goal="034305650121078709:90";

void construct(){
  queue<pair<string,string>>q;
  q.push({goal,""});
  mp[hash<string>()(goal)]="";
  string next;
  long long h;
  while(!q.empty()){
    pair<string,string> x = q.front(); q.pop();
    string state=x.first, steps=x.second;
    if(steps.size()==9)return;
    next=ll(state); h=hash<string>()(next); if(mp.find(h)==mp.end()){mp[h]=steps+char(1+'0'); q.push({next,steps+char(1+'0')});}
    next=rr(state); h=hash<string>()(next); if(mp.find(h)==mp.end()){mp[h]=steps+char(2+'0'); q.push({next,steps+char(2+'0')});}
    next=lr(state); h=hash<string>()(next); if(mp.find(h)==mp.end()){mp[h]=steps+char(3+'0'); q.push({next,steps+char(3+'0')});}
    next=rl(state); h=hash<string>()(next); if(mp.find(h)==mp.end()){mp[h]=steps+char(4+'0'); q.push({next,steps+char(4+'0')});}
  }
}

map<long long, bool>vis;

void go(string start){
  queue<pair<string, string>>q;
  q.push({start,""});
  vis[hash<string>()(start)]=1;
  string next;
  long long  h;
  while(!q.empty()){
    pair<string,string> x = q.front(); q.pop();
    string state=x.first, steps=x.second;
    h=hash<string>()(state);
    if(mp.find(h)!=mp.end()){ string b=mp[h]; reverse(b.begin(),b.end()); sol=steps+b; break; }
    if(steps.size()==9)return;
    next=lr(state); h=hash<string>()(next); if(!vis[h]){vis[h]=1; q.push({next,steps+char(1+'0')});}
    next=rl(state); h=hash<string>()(next); if(!vis[h]){vis[h]=1; q.push({next,steps+char(2+'0')});}
    next=ll(state); h=hash<string>()(next); if(!vis[h]){vis[h]=1; q.push({next,steps+char(3+'0')});}
    next=rr(state); h=hash<string>()(next); if(!vis[h]){vis[h]=1; q.push({next,steps+char(4+'0')});}
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;cin>>t;
  hash<string>()(goal);
  construct();
  while(t--){
    string start="";
    for(int i=0,x; i<21; i++) cin>>x, start.push_back(x+'0'); int x; cin>>x>>x>>x;
    if(start==goal){cout<<"PUZZLE ALREADY SOLVED\n"; continue; }
    vis.clear();
    sol=string(20,'z');
    go(start);
    if(sol.size()>16)cout<<"NO SOLUTION WAS FOUND IN 16 STEPS\n";
    else cout<<sol<<'\n';
  }
}
