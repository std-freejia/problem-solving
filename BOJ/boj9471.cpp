// 피사노 주기
// https://www.acmicpc.net/problem/9471
// http://boj.kr/09ebee989d924044a80ffcfe55bc54b5
#include <bits/stdc++.h>
#define endp '\n';
using namespace std;

int p, n, m;

int pisano(int mod){

  int cnt = 0; // cnt번째 피보나치 수 (0번째 부터 확인)
  int m1 = 0, m2 = 1; // 0과 1이 순서대로 나오면, 주기 발견.
  int tempsum = 0;

  while(1){
    tempsum = m1 + m2;
    m1 = m2;
    m2 = tempsum % mod;
    cnt++;
    if(m1 == 0 && m2 == 1) break;
  }

  return cnt;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> p;

  for(int i = 1; i <= p; i++){
    cin >> n >> m;
    cout << n << ' ' << pisano(m) << endp;
  }

  return 0;
}

