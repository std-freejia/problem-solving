/** 패션왕 신해빈
 https://www.acmicpc.net/problem/9375
 http://boj.kr/82fd0995697943b5a1217b693b627362
*/
#include <bits/stdc++.h>
using namespace std;

int tc, n;
string name, kind;

int check(){

  int answer = 1;
  map<string, int> clothmap; // <종류, 개수>
  cin >> n;

  while(n--){
    cin >> name >> kind;
    if(clothmap.find(kind) == clothmap.end()) clothmap.insert({kind, 1});
    else clothmap[kind]++;
  }

  for(auto i : clothmap) answer *= (i.second + 1); // 종류마다의 (개수 + 1) 을 전부 곱한다
  answer--; // 아무것도 선택 안한 경우인 1을 뺀다.
  return answer;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;
  while(tc--) cout << check() << '\n';
  return 0;
}
