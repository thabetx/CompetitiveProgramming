#include <bits/stdc++.h>
using namespace std;

int M,N; // problems, category nodes
bool bpGraph[1007][107];
bool bpm(int u, bool seen[], int matchR[]) {
  for (int v = 0; v < N; v++) {
    if (bpGraph[u][v] && !seen[v]) {
      seen[v] = true;
      if (matchR[v] < 0 || bpm(matchR[v], seen, matchR)) {
        matchR[v] = u;
        return true;
      }
    }
  }
  return false;
}

int matchR[107];
int maxBPM() {
  memset(matchR, -1, sizeof(matchR));
  int result = 0;
  for (int u = 0; u < M; u++) {
    bool seen[N];
    memset(seen, 0, sizeof(seen));
    if (bpm(u, seen, matchR)) result++;
  }
  return result;
}

int main() {
  int cat,p;
  while(cin>>cat>>p) {
    if(cat==0 && p==0)break;
    memset(bpGraph, 0, sizeof bpGraph);
    vector<pair<int,int>>v;
    int start=0;
    for(int i=0,x; i<cat; i++) {
      cin>>x;
      v.push_back({start, start+x-1});
      start+=x;
    }

    M=p, N=start;
    for(int i=0,x,y; i<p; i++) {
      cin>>x;
      while(x--){
        cin>>y;
        y--;
        for(int j=v[y].first; j<=v[y].second; j++) bpGraph[i][j]=1;
      }
    }

    int res=maxBPM();
    if(res == start){
      cout<<1<<'\n';
      for(int i=0; i<v.size(); i++)
        for(int j=v[i].first; j<=v[i].second; j++)
          cout<<matchR[j]+1<<" \n"[j==v[i].second];
    } else cout<<0<<'\n';
  }
  return 0;
}
