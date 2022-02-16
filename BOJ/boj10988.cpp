/** 팰린드롬인지 확인하기
 https://www.acmicpc.net/problem/10988
 http://boj.kr/3041b8825fed4088ac927e8ab219b600
 */
#include <bits/stdc++.h>
using namespace std;

string input;
bool answer = true;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;
  int len = input.size();
  for(int i = 0; i < (len/2); i++){
    if(input[i] != input[len-i-1]) answer = false;
  }
  cout << answer;
  return 0;
}