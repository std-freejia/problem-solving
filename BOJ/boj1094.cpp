/**  막대기
 * https://www.acmicpc.net/problem/1094
 * https://www.acmicpc.net/source/39190578
*/
#include <bits/stdc++.h>
using namespace std;

int x, cnt;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x;
  while(x >= 1){
    if(x % 2 == 1) cnt++;
    x /= 2;
  }
  cout << cnt;
  return 0;
}