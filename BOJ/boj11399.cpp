/** ATM
 * https://www.acmicpc.net/problem/11399
 * http://boj.kr/63bf619a5f2a48fdb25cead7567742f8
 * */
#include <bits/stdc++.h>
using namespace std;

int n, input;
long long accum, answer;
map<int, int> bmap;
vector<int> acc_vec; // 누적합을 저장

bool comp(pair<int,int> &left, pair<int,int> &right){
  if(left.second < right.second) return true;
  else return false;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 1; i <= n; i++){
    cin >> input;
    bmap.insert({i, input});
  }

  vector<pair<int,int>> v(bmap.begin(), bmap.end()); // map -> vector
  sort(v.begin(), v.end(), comp);  // value 기준으로 오름차순 정렬

  for(auto i : v){
    accum += i.second;
    acc_vec.push_back(accum);
  }
  answer = accumulate(acc_vec.begin(), acc_vec.end(), 0); // 마지막 인자는 합의 초기값
  cout << answer;
  return 0;
}