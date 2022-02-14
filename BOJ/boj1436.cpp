/** 영화감독 숌
 https://www.acmicpc.net/problem/1436
 http://boj.kr/fd7d5adb668943abb02c08925097a8c2
*/
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  string target = "666";
  int num = 665;
  int count = 0;

  while(++num){
    s = to_string(num); // int to string
    if(s.find(target) != string::npos) ++count; // 타겟이 존재한다면 카운팅한다.
    if(count == n) break;
  }
  cout << num;
  return 0;
}