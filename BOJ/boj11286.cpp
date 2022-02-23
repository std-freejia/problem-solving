/**  절댓값 힙
 https://www.acmicpc.net/problem/11286
 http://boj.kr/aa653782f3264498a4142da653b11595
*/
#include <bits/stdc++.h>
using namespace std;

int n, input;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // <절대값, 원본값>
  cin >> n;

  while(n--){
    cin >> input;
    if(input == 0){
      if(pq.empty()) cout << 0 << '\n';
      else {
        cout << pq.top().second << '\n';
        pq.pop();
      }
    }else{
      pq.push({abs(input), input});
    }
  }
  return 0;
}
