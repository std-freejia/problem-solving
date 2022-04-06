#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
  return a[1] < b[1]; // 종료 지점 기준으로 정렬
}

int solution(vector<vector<int>> routes) {
  int answer = 0;
  sort(routes.begin(), routes.end(), cmp);
  int end_point = -30001; // 초기값은 가장 작은 수

  for(auto r : routes){ // end_point: 현재 차,  r: 다음 차
    if(end_point < r[0]){
      answer++;
      end_point = r[1];
    }
  }
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<int>> routes{{-20, -15}, {-14, -5}, {-18, -13}, {-5, -3}};

  cout << solution(routes);
  return 0;
}
