// 피보나치 수 3
// https://www.acmicpc.net/problem/2749
// http://boj.kr/f8bdd5e090974050bac1b7e052d31c11
#include <bits/stdc++.h>
using namespace std;

long long n, cnt;
vector<int> v;

void pisano(int m){
  v.push_back(0); // 0번째 피보나치 수
  v.push_back(1); // 1번째 피보나치 수
  v.push_back(1); // 2번째 피보나치 수

  cnt = 2; // 3번째 피보나치 수를 구하기 위해 2번째와 1을 연산해야 한다.

  while(1){
    v.push_back((v[cnt] + v[cnt-1]) % m);
    cnt++;
    if(v[cnt] == 0 && v[cnt-1] == 1) break; // 주기를 구한 순간.
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  pisano(1000000);
  cout << v[n % cnt];

  return 0;
}