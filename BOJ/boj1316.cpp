/** 그룹 단어 체커
 https://www.acmicpc.net/problem/1316
 http://boj.kr/00228a1087564fada398eedcd8abcedb
 */
#include <bits/stdc++.h>
using namespace std;

int n, cnt;

bool check(string &s){
  map<char, int> smap;
  int slen = s.size();

  for(int i = 0; i < slen; i++){
    char ch = s[i];
    if(smap[ch] == 0) smap[ch]++;
    else if(s[i] != s[i-1]) return false;
  }
  return true;
}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<string> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];

  for(auto i : v) {
    if(check(i)){
      cnt++;
    }
  }
  cout << cnt;

  return 0;
}