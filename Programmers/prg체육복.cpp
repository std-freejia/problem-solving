#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
  int answer = 0;

  vector<int> v(n+2, 1); // 크기 n+1, 초기값 1

  v[0] = v[n+1] = 0;
  for(auto r : reserve) v[r] = 2;
  for(auto t : lost) v[t]--;

  for(int i = 1 ; i < v.size(); i++){
    if(v[i] >= 1) continue;
    // 체육복이 0이라면 앞뒤를 확인
    if(v[i-1] == 2){
      v[i-1] = 1; v[i] = 1; continue;
    }
    if(v[i+1] == 2){
      v[i+1] = 1; v[i] = 1; continue;
    }
  }

  for(int i = 1; i < v.size()-1; i++){
    // cout << v[i] << ' ' ;
    if(v[i] > 0) answer++;
  }
  //cout << '\n';
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 3;
  vector<int> lost{3};
  vector<int> reserve{1};

  cout << solution(n, lost, reserve);

  return 0;
}
