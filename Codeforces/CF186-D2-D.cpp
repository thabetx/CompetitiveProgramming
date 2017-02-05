#include <bits/stdc++.h>
using namespace std;

const double epsilon=1e-12;
double all,x,y,z,a,b,c;
double mx=-1e15;

double fn(double ch1, double ch2){
  double h=a*log(ch1);
  if(a<epsilon)h=0;
  double i=b*log(ch2);
  if(b<epsilon)i=0;
  double j=c*log(all-ch1-ch2);
  if(c<epsilon)j=0;
  double res = h+i+j;
  if(res>mx)mx=res,x=ch1,y=ch2,z=all-ch1-ch2;
  return res;
}

double ts2(double ch1){
  double left = 0, right = all-ch1;
  while(right-left > epsilon) {
    double g = left+(right-left)/3, h = left+2*(right-left)/3;
    if(fn(ch1, g) > fn(ch1, h)) right = h;
    else left = g;
  }
  return fn(ch1,left);
}

void ts1(){
  double left = 0, right = all;
  while(right-left > epsilon) {
    double g = left+(right-left)/3.0, h = left+2*(right-left)/3.0;
    if(ts2(g) > ts2(h)) right = h;
    else left = g;
  }
}

int main() {
  cout<<fixed<<setprecision(15);
  cin>>all>>a>>b>>c;
  ts1();
  cout<<x<<" "<<y<<" "<<z;
}
