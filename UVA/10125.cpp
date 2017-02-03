#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while(scanf("%d", &n)==1){
    if(n==0)break;

    vector<int>v(n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);

    vector<pair<int,pair<int,int>>>p;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==j)continue;
        p.push_back({v[i]-v[j],{i,j}});
      }
    }
    sort(p.begin(),p.end());

    int ninf=-1e9;
    int ans=ninf;

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        int sum=v[i]+v[j];
        pair<int,pair<int,int>> x ={sum,{ninf,ninf}};
        auto it=lower_bound(p.begin(),p.end(),x);
        while(it != p.end() && it->first==sum){
          if(!(i==it->second.first || i==it->second.second) && !(j==it->second.first || j==it->second.second)){
            ans=max(ans,sum+v[it->second.second]);
            break;
          }
          it++;
        }
      }
    }
    if(ans!=ninf)printf("%d\n",ans);
    else printf("no solution\n");
  }
}
