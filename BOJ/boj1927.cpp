/** 최소 힙
 * https://www.acmicpc.net/problem/1927
 * http://boj.kr/6a2d6f0b3b554b5bad4d36bb0319bfa5
 * */
#include <bits/stdc++.h>
using namespace std;

int n, input;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n--){
    cin >> input;
    if(pq.empty() && input == 0){
      cout << 0 << '\n';
    }else if(input == 0){
      cout << pq.top() << '\n';
      pq.pop();
    }else{
      pq.push(input);
    }
  }

  return 0;
}