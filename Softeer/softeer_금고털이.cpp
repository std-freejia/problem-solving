//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int w, n, a, b;
int answer;
vector<pair<int,int>> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> w >> n;
  for(int i = 0; i < n; i++){
    cin >> a >> b; // {무게, 가격}
    v.push_back({b, a}); // {가격, 무게}
  }

  sort(v.begin(), v.end(), greater<>());
  for(auto a : v){
    int small_weight = min(w, a.second);
    answer += (small_weight * a.first);
    w -= small_weight;
    if(w == 0) break;
  }
  cout << answer;
  return 0;
}