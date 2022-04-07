#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
  int answer = 0;
  bool result = true;

  priority_queue<int, vector<int>, greater<int>> pq;

  for(auto s : scoville){ pq.push(s); }

  while(!pq.empty()){

    if(pq.top() > K) break; // 더 검사하지 않아도 된다
    if(pq.size() == 1 && pq.top() < K) { result = false; break; } // 실패

    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();

    pq.push(first + (second * 2));
    // cout << "first: " << first << " second:" << second << ' ';
    answer++;
  }
  if(!result) answer = -1;
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k = 7;
  vector<int> scofille = {1, 2, 3, 9, 10, 12};
  cout << solution(scofille, k);

  return 0;
}