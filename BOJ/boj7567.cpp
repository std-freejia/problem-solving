/** 그릇
https://www.acmicpc.net/problem/7567
http://boj.kr/2b75dfbdc9bd409e87394797e56c4e80
*/
#include <bits/stdc++.h>
using namespace std;

int answer = 10;
string input;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;

  for(int i = 1; i < input.length(); i++){
    if(input[i-1] == input[i]) answer += 5;
    else answer += 10;
  }
  cout << answer;
  return 0;
}
