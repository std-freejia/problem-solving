/** N번째 큰 수
 * https://www.acmicpc.net/problem/2693
 * http://boj.kr/e5b487ac75bc458ca9e33db6b500c230
 * */
#include <bits/stdc++.h>
using namespace std;

int tc;
void check(){
  vector<int> v(11);
  for(int i = 0; i < 10; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end(), greater<int>());
  v.erase(unique(v.begin(), v.end()), v.end());
  cout << v[2] << '\n';
  v.clear();
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;
  while(tc--){
    check();
  }

  return 0;
}