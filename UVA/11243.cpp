#include <bits/stdc++.h>
using namespace std;

typedef complex<double> point;
#define X real()
#define Y imag()
#define rotate(p,ang)          ((p)*exp(point(0,ang)))
const double PI  = acos(-1.0);

template<class T>
istream& operator>> (istream& is, complex<T>& p) {
  T value;
  is >> value;
  p.real(value);
  is >> value;
  p.imag(value);
  return is;
}

vector<point>v;

double side(double angle){
  double mnx=1e15,mxx=-1e15;
  double mny=1e15,mxy=-1e15;
  for(auto i:v){
    point p=rotate(i,angle);
    mxx=max(mxx,p.X), mnx=min(mnx,p.X);
    mxy=max(mxy,p.Y), mny=min(mny,p.Y);
  }
  return max(mxx-mnx , mxy-mny);
}

double ts(double l, double r) {
  for(int i=0; i<30; i++){
    double g = l+(r-l)/3, h = l+2*(r-l)/3;
    if(side(g) < side(h)) r = h;
    else l = g;
  }
  return side((l+r)/2);
}

int main() {
  cout<<fixed<<setprecision(2);
  int t; cin>>t;
  while(t--){
    int n;cin>>n;
    v.resize(n);
    double ans=1e20;
    for(int i=0; i<n; i++)cin>>v[i];
		for (double x = 0; x < PI/2; x += 0.001)
      ans=min(ans,ts(x,x+.001));
    cout<<ans*ans<<'\n';
  }
}
