/** 통계학
 https://www.acmicpc.net/problem/2108
 http://boj.kr/281809b158c14b9b8160a66990c5abba
 */
#include <bits/stdc++.h>
using namespace std;

int n, num;  // 홀수 n
vector<int> v;
map<int, int> m; //(숫자, 개수)

bool comp(pair<int,int> &a, pair<int,int> &b){ // <숫자, 빈도수>
  if(a.second == b.second) return a.first < b.first; // 빈도수가 같으면 숫자로 비교
  else return a.second > b.second;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  double sum = 0;

  for(int i = 0; i < n; i++){
    cin >> num;
    v.push_back(num);
    if(m.count(num) == 0){ // 처음 나온 숫자면 map에 <숫자, 개수 1>로 삽입
      m.insert({num, 1});
    }else{ // 이미 있는 숫자면 value 값 개수만 증가
      m[num]++;
    }
    sum += num; // 누적 합
  }

  sort(v.begin(), v.end()); // 오름차순 정렬

  // 산술 평균
  cout << round(sum/n) << '\n';

  // 중앙값
  cout << v[n/2] << '\n';

  // 최빈값
  vector<pair<int,int>> mapv(m.begin(), m.end()); // map -> vector

  sort(mapv.begin(), mapv.end(), comp); // value 값 기준으로 정렬
  if(mapv[0].second == mapv[1].second) cout << mapv[1].first << '\n';
  else cout << mapv[0].first << '\n';

  // 범위
  cout << v.back()-v.front();
  return 0;
}