#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define matrix vector<vector<ll>>
#define rows size()
#define cols begin()->size()

ll mod = 1e9;

matrix multiply(matrix &a, matrix &b) {
  matrix result(a.rows, vector<ll>(b.cols));
  for(int i=0; i<a.rows; ++i)
    for(int j=0; j<b.cols; ++j)
        for(int k=0; k<a.cols; ++k)
          result[i][j] = (result [i][j] + (a[i][k] * b[k][j]) % mod) % mod;
  return result;
}

matrix matrix_power(matrix a, ll n){
  matrix result(a.rows, vector<ll>(a.cols));
  for(int i=0; i<a.rows; i++) result[i][i]=1;
  while(n) {
    if(n&1) result=multiply(result, a);
    a=multiply(a, a);
    n>>=1;
  }
  return result;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, req;
    scanf("%d", &n);
    matrix init(1,vector<ll>(n));
    matrix pro(n,vector<ll>(n));

    for(int i=0; i<n; i++) scanf("%lld", &init[0][i]);
    for(int i=0; i<n; i++) scanf("%lld", &pro[n-i-1][n-1]);
    for(int i=0; i<n-1; i++) pro[i+1][i]=1;

    scanf("%d", &req);

    if(req<=n) printf("%lld\n",init[0][req-1]);
    else {
      pro = matrix_power(pro, req-n);
      init = multiply(init, pro);
      printf("%lld\n", init[0][n-1]);
    }
  }
}
