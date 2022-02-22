/** 저항
 * https://www.acmicpc.net/problem/1076
 * http://boj.kr/09334757a8f04d8fae86083c49cb00e4
 * */
#include <bits/stdc++.h>
using namespace std;

long long answer;
string a, b, c;
map<string, int> valuemap;
vector<string> stv{"black", "brown", "red", "orange", "yellow",
                   "green", "blue", "violet", "grey", "white"};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 10; i++){
    valuemap.insert({stv[i], i});
  }
  cin >> a >> b >> c;

  if(valuemap[a] != 0) answer = 10 * valuemap[a];
  answer += valuemap[b];
  answer *= pow(10, valuemap[c]);
  cout << answer;

  return 0;
}