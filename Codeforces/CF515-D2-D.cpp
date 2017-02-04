#include <bits/stdc++.h>
using namespace std;

int di[]={0,0,-1,1};
int dj[]={1,-1,0,0};

vector<string>g;

int n,m;

bool valid(int i, int j){ return i>=0 && i<n && j>=0 && j<m && g[i][j]=='.'; }
int deg(int i,int j){
  int res=0;
  for(int k=0; k<4; k++) if(valid(i+di[k],j+dj[k]))res++;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin>>n>>m;
  g.resize(n);
  for(int i=0; i<n; i++)cin>>g[i];

  queue<pair<int,int>>q;
  int used=0,target=0;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(g[i][j]=='.')target++;
      if(deg(i,j)==1) q.push({i,j});
    }
  }

  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    if(!valid(x,y))continue;
    used+=2;
    int a,b;
    if(valid(x,y+1)) g[x][y]='<', g[x][y+1]='>', a=x, b=y+1;//right
    if(valid(x,y-1)) g[x][y]='>', g[x][y-1]='<', a=x, b=y-1;//left
    if(valid(x+1,y)) g[x][y]='^', g[x+1][y]='v', a=x+1, b=y;//down
    if(valid(x-1,y)) g[x][y]='v', g[x-1][y]='^', a=x-1, b=y;//up

    for(int k=0; k<4; k++) if(valid(x+di[k],y+dj[k]) && deg(x+di[k],y+dj[k])==1) q.push({x+di[k],y+dj[k]});
    for(int k=0; k<4; k++) if(valid(a+di[k],b+dj[k]) && deg(a+di[k],b+dj[k])==1) q.push({a+di[k],b+dj[k]});
  }

  if(used==target) for(int i=0; i<n; i++) cout<<g[i]<<"\n";
  else cout<<"Not unique";
}
