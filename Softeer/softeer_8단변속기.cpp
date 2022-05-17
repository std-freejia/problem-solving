#include <bits/stdc++.h>
using namespace std;

bool check_flag = true;
string answer = "mixed";
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> v(8);
  cin >> v[0];
  for(int i = 1; i < 8; i++){
    cin >> v[i];
    if(abs(v[i-1] - v[i]) != 1){ check_flag = false; break; }
  }

  if(check_flag){
    answer = (v[0] == 8) ? "descending" : "ascending";
  }

  cout << answer;
  return 0;
}