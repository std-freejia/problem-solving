/** 피보나치 수 5
https://www.acmicpc.net/problem/10870
**/
#include <bits/stdc++.h>
using namespace std;

long long D[22];
int n;

long long fibo(int num){
  if (num == 0) return 0;
  if (num == 1) return 1;
  return fibo(num-1) + fibo(num-2);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cout << fibo(n);
  return 0;
}

/* 2번째 풀이
#include <bits/stdc++.h>
using namespace std;

long long D[22];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  D[1] = D[2] = 1;
  for(int i = 3; i <= n; i++){
    D[i] = D[i-1] + D[i-2];
  }

  cout << D[n];
  return 0;
}
*/