/** 최대 힙
 * https://www.acmicpc.net/problem/11279
 * http://boj.kr/2dc5df561029421ba2985b42534c0f00
 * */
#include <bits/stdc++.h>
using namespace std;

int n;
long long input;
priority_queue<long long> pq;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n--){
    cin >> input;
    if(pq.empty() && input == 0){
      cout << 0 << '\n';
    }else if(input == 0){ // 출력 및 제거
      cout << pq.top() << '\n';
      pq.pop();
    }else{
      pq.push(input);
    }
  }
  return 0;
}