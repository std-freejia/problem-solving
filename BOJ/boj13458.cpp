/** 시험 감독
 * https://www.acmicpc.net/problem/13458
 * http://boj.kr/7a5395901e8c451c8eccc9b65a148553
 * */
#include <bits/stdc++.h>
using namespace std;

int n, num, b, c;
long long answer;
vector<int> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> num; v.push_back(num);
  }
  cin >> b >> c;

  answer = n; // 총감독은 모든 시험장에 1명씩 배치

  for(auto i : v){
    i -= b; // 총감독이 감독한 만큼 인원 빼기
    if(i <= 0) continue;

    if(i % c == 0){
      answer += (i / c);
    }else{
      answer += (i / c) + 1;
    }
  }
  cout << answer;

  return 0;
}