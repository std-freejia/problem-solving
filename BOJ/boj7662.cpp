/** 이중 우선순위 큐
https://www.acmicpc.net/problem/7662
http://boj.kr/1e9eac47b8da4762a6fac0cbc63f854b
 */
#include <bits/stdc++.h>
using namespace std;

int T, k, n;
char ch;

void solve(){

  multiset<int> ms;
  cin >> k;

  while(k--){
    cin >> ch >> n;
    if(ch == 'I') ms.insert(n);
    else if(ms.size() > 0){
      if(n > 0){ // 최댓값 삭제
        auto iter = ms.end();
        ms.erase(--iter);
      }else ms.erase(ms.begin());
    }
  }

  if(ms.size() == 0) cout << "EMPTY\n";
  else {
    auto iter = ms.end();  --iter;
    cout << *iter << ' ' << *ms.begin() << '\n';
  }
  return;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while(T--){
    solve();
  }
  return 0;
}