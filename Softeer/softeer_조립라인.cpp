#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll D[10];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  D[0] = 2, D[1] = 3;
  ll addnum = 1;
  for(int i =2; i <= n; i++){
    addnum *= 2;
    D[i] = D[i-1] + addnum;
  }
  cout << D[n] * D[n];
  return 0;
}