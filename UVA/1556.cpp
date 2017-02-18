#include <bits/stdc++.h>
using namespace std;

struct node{
  string s;
  vector<node*>v;
};

bool cmp(node* a, node* b) { return a->s < b->s; }

void print(node *x, int d){
  if(d!=-1) cout<<string(d,' ')<<x->s<<'\n';
  sort(x->v.begin(),x->v.end(),cmp);
  for(auto &i:x->v) print(i,d+1);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  while(cin>>n){
    node *parent=new node();
    for(int i=0; i<n; i++){
      string s;cin>>s;
      s+="\\";
      node *cur=parent;
      while(s.size()>1){
        string token=s.substr(0,s.find('\\'));
        s=s.substr(s.find('\\')+1);
        node *child=new node();
        bool f=0;
        for(auto &j:cur->v){
          if(j->s==token){
            f=1;
            child=j;
            break;
          }
        }
        if(f) cur=child;
        else{
          child->s=token;
          cur->v.push_back(child);
          cur=child;
        }
      }
    }
    print(parent,-1);
    cout<<'\n';
  }
}

