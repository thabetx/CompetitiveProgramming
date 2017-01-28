#include <bits/stdc++.h>
using namespace std;

// https://github.com/gautamkmr/Fenwick/blob/master/fenwick.cpp
// Return sum from 0...i from array
int getSum(int fw[], int i)
{
   int sum = 0;
   // Fenwick's index start from 1
   i++;

   while(i > 0)
   {
      sum += fw[i];
      // i & (-i)  returns the decimal value of last set digit
      // eg: if i = 12 (1100) then  i & (-i) will 4 (100)
      i -= i & (-i);
   }
   return sum;
}

// newVal will be updated to Fenwick and all its ancestor
void updateFW(int fw[], int n, int i, int newVal)
{
   // Fenwick's index start from 1
   i++;
   while (i <= n)
   {
      fw[i] += newVal;
      i += i & (-i);
   }
}

// Build Fenwick's tree
int *constructFenwick(int a[], int n)
{
  int *fw = new int [n+1];
  for (int i = 0; i <= n; i++)
    fw[i] = 0;

  for (int i=0; i<n; i++)
    updateFW(fw, n, i, a[i]);

  return fw;
}

int a[100100];
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<pair<int,int>,int>>v(n);
  for(int i=0,x,y; i<n; i++) {
    scanf("%d %d", &x, &y);
    v[i]={{x,y},i};
  }
  sort(v.begin(),v.end());
  vector<int>ans(n);

  int N=100050;
  int *fw = constructFenwick(a, N);
  auto prev=*(v.begin());
  prev.first.first=-1;
  int prev_ans=0;
  for(auto i:v) {
    if(i.first.first== prev.first.first &&
       i.first.second== prev.first.second) {
      ans[i.second] = prev_ans;
      updateFW(fw, N, i.first.second, 1);
    }
    else {
      prev=i;
      prev_ans = ans[i.second] = getSum(fw, i.first.second);
      updateFW(fw, N, i.first.second, 1);
    }
  }
  for(auto i:ans) printf("%d\n",i);
}
