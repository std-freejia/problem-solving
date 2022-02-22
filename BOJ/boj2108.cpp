/** 통계학
 * https://www.acmicpc.net/problem/2108
 * http://boj.kr/ed9ca0e829c54833beb7aba7ebf9cf7a
 * */
#include <bits/stdc++.h>
using namespace std;

int n, num;
double sum;
map<int,int> num_cnt;
vector<int> v;

bool comp(pair<int,int> &a, pair<int,int> &b){
  if(a.second > b.second) return true;
  return false;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num; // 숫자와 빈도수
    if(num_cnt.count(num) == 0) num_cnt.insert({num, 1});
    else num_cnt[num]++;
    v.push_back(num);
    sum += num; // 총합 구하기
  }

  sort(v.begin(), v.end()); // 오름차순 정렬

  // 평균
  double avg = round(sum / n);
  if(abs(avg) == 0) avg = 0;
  cout << avg << '\n';

  // 중간값
  cout << v[n/2] << '\n';

  // 최빈값
  vector<pair<int,int>> pv(num_cnt.begin(), num_cnt.end()); // map -> vector
  sort(pv.begin(), pv.end(), comp);

  (pv[0].second == pv[1].second) ? cout << pv[1].first << '\n' : cout << pv[0].first << '\n';

  // 범위
  cout << abs(v[n-1] - v[0]) << '\n';

  return 0;
}