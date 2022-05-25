#include <bits/stdc++.h>
using namespace std;

bool check(int n){
  int cnt = 0;
  for(int i = 1; i <= n; i++) {
    if(n % i == 0) cnt++;
  }
  return (cnt % 2 == 0)? 1 : 0;
}
int solution(int left, int right) {
  int answer = 0;

  for(int i = left; i <= right; i++){
    if(check(i)) answer += i;
    else answer -= i;
  }
  return answer;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << solution(13, 17);
  return 0;
}