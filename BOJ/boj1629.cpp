/** 곱셈
https://www.acmicpc.net/problem/1629
http://boj.kr/bed7e417bfe84106b749fd06b18513ed
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, c;

ll rec(ll a, ll b){
  if(b == 0) return 1;
  if(b == 1) return a % c;

  long long temp = rec(a, b/2);
  if(b%2 == 0){ // b가 짝수라면,
    return (temp * temp) % c; // b/2승을 제곱하면 된다.
  }
  else{// b가 홀수라면, 1번 더 a를 곱한다. 반드시 c로 나눈 나머지를 저장한다.
    return ((temp * temp) % c) * a % c;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> c;

  cout << rec(a, b);
  return 0;
}