/** * Hashing
 https://www.acmicpc.net/problem/15829
 http://boj.kr/677de92c173044cabad8b562205cfc49

 모듈러 연산
 (a * b ) mod n == (a mod n) * (b mod n)
 */
#include <bits/stdc++.h>
using namespace std;

long long MOD = 1234567891;
long long MUL = 31;
int L;
string input;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> L >> input;

  long long answer = 0; // 합 누적
  long long R = 1; // 제곱근 처음에 1로 시작

  for(int i = 0; i < L; i++){
    // input[i] - 'a' + 1 : 문자의 인덱스. a는 1이 나오도록.
    long long idx = input[i] - 'a' + 1;
    answer = (answer + (idx * R)) % MOD;
    R = (R * MUL) % MOD; // 곱할 숫자
  }
  // 마지막에 항상 % MOD를 해서 숫자가 커지는 것을 방지한다
  cout << answer;

  return 0;
}