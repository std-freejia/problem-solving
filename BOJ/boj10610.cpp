/** 30
https://www.acmicpc.net/problem/10610
http://boj.kr/97d34aa0ffa64d7ebb6ef588f7b42d17
*/
#include <bits/stdc++.h>
using namespace std;

long long sum;
string num_st;

int main(void) { // 30의 배수의 조건 : 각 자리 수 합이 3의 배수. 0으로 끝나기.
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num_st;
  int len = num_st.length();
  for(auto n : num_st) sum += (n - '0'); // 각 자리수 합
  sort(num_st.begin(), num_st.end(), greater<>()); // 내림차순정렬

  if(num_st[len-1] == '0' && sum % 3 == 0) cout << num_st;
  else cout << -1;

  return 0;
}
