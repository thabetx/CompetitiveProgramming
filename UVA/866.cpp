#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define x first
#define y second
#define f first
#define s second

const double epsilon=1e-9;

bool intersect(pair<pii,pii>a, pair<pii,pii>b){
  double xi,yi; // intersection points
  if(a.f.x==a.s.x && b.f.x==b.s.x)return false; // both vertical
  bool vertical=0;
  if(a.f.x==a.s.x)vertical=1;
  if(b.f.x==b.s.x)vertical=1, swap(a,b); // now a is the vertical

  if(vertical){
    xi=a.f.x;
    double m=1.0*(b.f.y-b.s.y)/(b.f.x-b.s.x);
    double c=b.f.y-m*b.f.x;
    yi=m*xi+c;
  }else{
    double m1=1.0*(a.f.y-a.s.y)/(a.f.x-a.s.x);
    double c1=a.f.y-m1*a.f.x;

    double m2=1.0*(b.f.y-b.s.y)/(b.f.x-b.s.x);
    double c2=b.f.y-m2*b.f.x;

    if(abs(m1-m2)<epsilon)return false; // parallel
    xi=(c1-c2)/(m2-m1);
    yi=m1*xi+c1;
  }

  // check that the point is inside the segments
  return xi>=min(a.f.x,a.s.x) && xi>=min(b.f.x,b.s.x) &&
         xi<=max(a.f.x,a.s.x) && xi<=max(b.f.x,b.s.x) &&
         yi>=min(a.f.y,a.s.y) && yi>=min(b.f.y,b.s.y) &&
         yi<=max(a.f.y,a.s.y) && yi<=max(b.f.y,b.s.y);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d",&n);
    vector<pair<pii,pii>>v(n);
    for(int i=0; i<n; i++) scanf("%d %d %d %d", &v[i].f.x, &v[i].f.y, &v[i].s.x, &v[i].s.y);
    int ans=n;
    for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if(intersect(v[i],v[j]))ans+=2;
    printf("%d\n", ans);
    if(t>0)printf("\n");
  }
}
