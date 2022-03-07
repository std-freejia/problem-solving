/** 캠핑
https://www.acmicpc.net/problem/4796
http://boj.kr/7c7b80ae2c1345d8b07b09355c19e382
*/
#include <bits/stdc++.h>
using namespace std;

int L, P, V;
int case_num = 1;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(1){
    cin >> L >> P >> V;
    if(L == 0 && P == 0 && V == 0) break;

    int answer = V / P * L + min(V % P, L);
    cout << "Case " << case_num << ": " << answer << "\n";
    case_num += 1;
  }
  return 0;
}
