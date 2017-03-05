#include <bits/stdc++.h>
using namespace std;

#define ll long long

long long nck[50][50];

void construct(){
  for(int i=0; i<50; i++)
    for(int j=0; j<50; j++)
      nck[i][j]=1;
  for(int i=0; i<50; i++)
    for(int j=1; j<i; j++)
      nck[i][j]=nck[i-1][j-1]+nck[i-1][j];
}

int all, pack;

bool visited[50];
double dp[50];

double solve(int cur, int depth){
  if(depth>1000)return 0;
  if(cur==all)return 0;
  if(visited[cur])return dp[cur];

  double sol=1;
  int good=all-cur;
  int bad=cur;

  for(int i=0; i<=pack; i++){
    int next=cur+i;
    if(next>all)break;
    double c=((double)nck[good][next-cur]/nck[all][pack])*nck[bad][pack-(next-cur)];
    if(cur==next) sol+=c*solve(next, depth+1);
    else sol+=c*solve(next, 1);
  }
  visited[cur]=1;
  return dp[cur]=sol;
}

int main() {
  int T;cin>>T;
  construct();
  cout<<fixed<<setprecision(6);
  for(int t=0; t<T; t++){
    cin>>all>>pack;
    memset(visited, 0, sizeof visited);
    cout<<"Case #"<<t+1<<": "<<1+solve(pack, 1)<<endl;
  }
}
