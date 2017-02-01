#include <bits/stdc++.h>
using namespace std;

#define point pair<ld, ld>
#define ld long double
#define x first
#define y second

const ld epsilon=1e-15;
const ld pi=acos(-1);

ld cp(point a, point b){
  ld ans =  hypot(a.x,a.y)*hypot(b.x,b.y)*sin(atan2(a.y,a.x)-(atan2(b.y,b.x)));
  if(abs(ans)<epsilon)ans=0;
  return ans;
}

// minimize this function using ternary search
// to get closest point on the segment to the center
ld fn(ld dist, point normalized,point start){
  return hypot(start.x+dist*normalized.x,start.y+dist*normalized.y);
}

ld closest(point a, point b){
  ld dist=hypot(a.x-b.x,a.y-b.y);
  if(abs(a.x-b.x)<epsilon && abs(a.y-b.y)<epsilon)return hypot(a.x,a.y);
  point vec={b.x-a.x,b.y-a.y};
  // normalize
  vec.x/=dist, vec.y/=dist;

  ld leftR = 0, rightR = dist;
  while(rightR-leftR > epsilon) {
    ld g = leftR+(rightR-leftR)/3, h = leftR+2*(rightR-leftR)/3;
    if(fn(g,vec,a) < fn(h,vec,a)) rightR = h;
    else leftR = g;
  }
  return fn((leftR+rightR)/2,vec,a);
}

point tangent(point a, ld r, bool f){
  ld h=hypot(a.x, a.y);
  ld angle=acos(r/h);
  if(f)angle=atan2(a.y,a.x)-angle;
  else angle=atan2(a.y,a.x)+angle;
  point ans = {cos(angle)*r, sin(angle)*r};
  if(abs(ans.x)<epsilon)ans.x=0;
  if(abs(ans.y)<epsilon)ans.y=0;
  return ans;
}

ld calcAngle(point a, point b){
  ld dot = a.x*b.x + a.y*b.y;
  ld det = a.x*b.y - a.y*b.x;
  ld angle = atan2(det, dot);
  if(angle<0)angle+=2*pi;
  if(angle>pi)angle=2*pi-angle;
  return angle;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--){
    point a,b;
    ld r;
		scanf("%Lf %Lf %Lf %Lf %Lf",&a.x,&a.y,&b.x,&b.y,&r);
    point o={0,0};

    ld c=closest(a,b);
    if(c>=r){
			ld ans= hypot(a.x-b.x,a.y-b.y);
			printf("%.3Lf\n",ans);
      continue;
    }

    point ta1=tangent(a, r, 0);
    point ta2=tangent(a, r, 1);
    point tb1=tangent(b, r, 0);
    point tb2=tangent(b, r, 1);

    ld l1=hypot(a.x-ta1.x,a.y-ta1.y);
    ld l2=hypot(b.x-tb1.x,b.y-tb1.y);

    ld angle= min ( min( calcAngle(ta1,tb1), calcAngle(ta1, tb2)),
                    min( calcAngle(ta2,tb1), calcAngle(ta2, tb2)));
    ld sec=r*angle;
    ld ans=l1+sec+l2;
		printf("%.3Lf\n",ans);
  }
}
