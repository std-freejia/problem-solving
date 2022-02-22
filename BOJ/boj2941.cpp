#include <bits/stdc++.h>
using namespace std;

string s;
int start_idx;
vector<string> croa = {"lj", "dz=", "nj", "c=", "c-", "d-", "s=", "z="};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;

  for(int i = 0; i < croa.size(); i++){ // 모든 단어를 찾는다
    while(1){
      start_idx = s.find(croa[i]);
      if(string::npos == start_idx) break; // 없으면 다른 단어 찾기
      s.replace(start_idx, croa[i].length(), "@"); // 찾으면 한덩이를 @ 로 변환
    }
  }

  cout << s.length();
  return 0;
}