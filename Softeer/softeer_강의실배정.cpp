#include <bits/stdc++.h>
using namespace std;

int n, s, f, cnt;
vector<pair<int,int>> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s >> f;
    v.push_back({f, s}); // 종료가 빠른 수업 먼저.
  }

  sort(v.begin(), v.end());
  int cur = v[0].first; // 첫 종료지점
  cnt = 1;

  for(int i = 1 ; i < n; i++){
    if(cur <= v[i].second){
      cur = v[i].first;
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}