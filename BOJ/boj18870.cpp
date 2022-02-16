/** 좌표 압축
 https://www.acmicpc.net/problem/18870
 http://boj.kr/5dbc3bb2652446409f7d8ffd908ce473
 */
#include <bits/stdc++.h>
using namespace std;

int n, num;
vector<int> v;
vector<int> temp;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i <n; i++) {
    cin >> num;
    v.push_back(num); temp.push_back(num);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end()); // [-10, -9, 2, 4]

  for(auto x : temp){
    cout << find(v.begin(), v.end(), x) - v.begin() << ' ';
  }

  return 0;
}