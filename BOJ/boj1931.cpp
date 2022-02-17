/** 비밀번호 찾기
 * https://www.acmicpc.net/problem/17219
 * http://boj.kr/6193d3d02aee41a1a5b6bc7d78c3583d
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;
string address, password;
map<string, string> smap;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(n--){
    cin >> address >> password;
    smap.insert({address, password});
  }
  while(m--){
    cin >> address;
    cout << smap[address] << '\n';
  }

  return 0;
}