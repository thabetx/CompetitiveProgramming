#include <bits/stdc++.h>
using namespace std;

class RandomSwaps {
  bool done[2][100100];
  double dp[2][100100];
  int goal;
  double x,y;

  double solve(bool right, int moves) {
    if(moves==0)return right;
    if(done[right][moves])return dp[right][moves];
    done[right][moves]=1;
    if(right) return dp[1][moves]=x*solve(1,moves-1)+(1-x)*solve(0,moves-1);
    else return dp[0][moves]=y*(solve(1,moves-1))+(1-y)*solve(0,moves-1);
  }

public:
  double getProbability(int arrayLength, int swapCount, int a, int b) {
    goal=b;
    x=(arrayLength-2.0)/arrayLength;
    y=2.0/(arrayLength*(arrayLength-1));
    return solve(a==b, swapCount);
  }
};
