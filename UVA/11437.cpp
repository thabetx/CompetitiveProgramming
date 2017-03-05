#include <bits/stdc++.h>
using namespace std;

#define sz(v)      ((int)((v).size()))
#define rep(i, v)      for(int i=0;i<(sz(v));++i)
typedef complex<double> point;
#define cp(a,b)                 ( (conj(a)*(b)).imag() )

typedef long long ll;
const double PI  = acos(-1.0);
const double EPS = (1e-8);

int dcmp(double a, double b) {	return fabs(a-b) <= EPS ? 0 : a < b ? -1 : 1;	}

bool intersectSegments(point a, point b, point c, point d, point & intersect) {
	double d1 = cp(a-b, d-c), d2 = cp(a-c, d-c), d3 = cp(a-b, a-c);
	if(fabs(d1) < EPS) return false; // Parllel || identical
	double t1 = d2/d1, t2 = d3/d1;
	intersect = a+(b-a)*t1;
	if( t1 < -EPS ||  t2 < -EPS || t2 > 1+EPS)
		return false; //e.g ab is ray, cd is segment
  return true;
}

double polygonArea(vector<point>& points) {
    long double a = 0;
    rep(i, points)  a += cp(points[i], points[ (i+1) % sz(points) ]);
    return fabs(a/2.0);  // If area > 0 then points ordered ccw
}

int main() {
  int t;cin>>t;
  while(t--){
    double ax,ay,bx,by,cx,cy; cin>>ax>>ay>>bx>>by>>cx>>cy;

    double ab=hypot(ax-bx,ay-by);
    double vabx=(bx-ax)/ab;
    double vaby=(by-ay)/ab;
    double fx=ax+(ab/3) * vabx;
    double fy=ay+(ab/3) * vaby;

    double bc=hypot(bx-cx,by-cy);
    double vbcx=(cx-bx)/bc;
    double vbcy=(cy-by)/bc;
    double dx=bx+(bc/3)*vbcx;
    double dy=by+(bc/3)*vbcy;

    double ca=hypot(cx-ax,cy-ay);
    double vcax=(ax-cx)/ca;
    double vcay=(ay-cy)/ca;
    double ex=cx+(ca/3)*vcax;
    double ey=cy+(ca/3)*vcay;

    point r,p,q;
    intersectSegments({ax,ay},{dx,dy},{cx,cy},{fx,fy},r);
    intersectSegments({ax,ay},{dx,dy},{bx,by},{ex,ey},p);
    intersectSegments({bx,by},{ex,ey},{cx,cy},{fx,fy},q);
    vector<point>v={r,p,q};
    double area=polygonArea(v);
    int ans=round(area);
    cout<<ans<<'\n';
  }
}
