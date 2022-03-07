/** 회사에 있는 사람
 https://www.acmicpc.net/problem/7785
 http://boj.kr/99555e561b5b42099a46125af4f8e997
*/
#include <bits/stdc++.h>
using namespace std;

int n;
string name, sign;
map<string,int, greater<>> log_map;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> name >> sign;
    if(sign == "enter") log_map[name] = 1;
    else log_map[name] = 0;
  }

  for(auto it = log_map.begin(); it != log_map.end(); it++){
    if(1 == it->second) cout << it->first << '\n';
  }

  return 0;
}
