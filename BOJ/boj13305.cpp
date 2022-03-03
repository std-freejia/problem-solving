/** 주유소
 https://www.acmicpc.net/problem/13305
 http://boj.kr/f008994e739b4337b28d1002e118e18a
 * */
#include <bits/stdc++.h>
using namespace std;

int cost[100002];
int dist[100002];
int N;
long long min_cost, answer;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i = 0; i < N-1; i++) cin >> dist[i];
  for(int i = 0; i < N; i++) cin >> cost[i];

  min_cost = cost[0];
  answer = min_cost * dist[0]; // 첫 번째 무조건 가야할 거리. 필수로 필요한 비용 먼저 더한다

  for(int i = 1; i < N; i++){
    if(cost[i] < min_cost) min_cost = cost[i]; // 지금까지 중에 가장 작은 연료비용
    answer += (min_cost * dist[i]);
  }
  cout << answer;
  return 0;
}
