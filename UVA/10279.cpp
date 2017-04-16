#include <iostream>
#include <vector>

using namespace std;

int main(){
  int tc; cin>>tc;
  while(tc--){
    int n; cin>>n;
    vector<string>v(n); for(int i=0; i<n; i++) cin>>v[i];
    vector<string>t(n); for(int i=0; i<n; i++) cin>>t[i];
    vector<string>ans(n,string(n,'.'));
    bool bomb=0; int dx[]={-1, 0, 1}; int dy[]={-1, 0, 1};
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(t[i][j]=='x'){
          if(v[i][j]=='*') bomb=1;
          else{
            int cnt=0;
            for(int k=0; k<3; k++){
              for(int l=0; l<3; l++){
                int x=i+dx[k];
                int y=j+dy[l];
                if((x==i && y==j) || x<0 || x>=n || y<0 || y>=n) continue;
                if(v[x][y]=='*')cnt++;
              }
            }
            ans[i][j]='0'+cnt;
          }
        }
      }
    }

    if(bomb) for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(v[i][j]=='*') ans[i][j]='*';

    for(auto i:ans)cout<<i<<endl;
    if(tc!=0) cout<<endl;
  }

}