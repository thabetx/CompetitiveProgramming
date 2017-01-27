#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007, n;
vector<pair<int,int>>v;
long long dp[307][307];

long long solve(int pos, int last) {
  if(pos==n) return 1;
  if(dp[pos][last]!=-1) return dp[pos][last];
  bool f=0;
  for(auto i:v) if(i.second==pos && i.first>last) f=1;
  if(f) return dp[pos][last]=solve(pos+1,pos)%mod;
  else return dp[pos][last]=(solve(pos+1,pos)%mod+solve(pos+1,last)%mod)%mod;
}

class WolfInZooDivTwo
{
public:
  int count(int N, vector <string> L, vector <string> R)
  {
    string a, b;
    n=N+1;
    for(auto i:L) a+=i;
    for(auto i:R) b+=i;
    stringstream ss1,ss2;
    ss1 << a;
    ss2 << b;
    int x;
    vector<int>l,r;
    while(ss1 >> x) l.push_back(x);
    while(ss2 >> x) r.push_back(x);
    for(int i=0;i<l.size();i++)v.push_back({l[i]+1,r[i]+1});
    memset(dp, -1, sizeof dp);
    return solve(1, 0) %mod;
  }
};
