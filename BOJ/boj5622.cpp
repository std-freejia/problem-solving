/** 다이얼
 * https://www.acmicpc.net/problem/5622
 * http://boj.kr/5a32d06ae467403ea31f20bde855a898
 * */
#include <bits/stdc++.h>
using namespace std;

string input;
string numst = "22233344455566677778889999"; // 다이얼 숫자 그대로 사용

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;

  int sum = 0;
  int len = input.size();

  for(int i = 0; i < len; i++){
    int numidx = input[i] - 'A';
    sum += (numst[numidx] - '0' + 1); // 다이얼 숫자보다 +1초 더 걸림.
  }
  cout << sum;

  return 0;
}