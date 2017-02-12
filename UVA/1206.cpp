#include <bits/stdc++.h>
using namespace std;

#define pld pair<long double,long double>
#define x first
#define y second

long double cross(const pld &O, const pld &A, const pld &B) {
  return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<pld> convex_hull(vector<pld> P) {
  int n = P.size(), k = 0;
  vector<pld> H(2*n);
  sort(P.begin(), P.end());
  for (int i = 0; i < n; ++i) {
    while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }
  for (int i = n-2, t = k+1; i >= 0; i--) {
    while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
    H[k++] = P[i];
  }
  H.resize(k-1);
  return H;
}

int main() {
  string s;
  while(getline(cin,s)){
    long double x,y;
    char c;
    stringstream ss; ss << s;
    vector<pld>v;
    while (ss >> c){
      ss>>x>>c>>y>>c;
      v.push_back({x,y});
    }
    vector<pld>ch=convex_hull(v);
    for(auto i:ch)printf("(%.17Lf,%.17Lf) ",i.x,i.y);
    printf("(%.17Lf,%.17Lf)\n",ch[0].x,ch[0].y);
  }
}
