/**  저작권
* https://www.acmicpc.net/problem/2914
* http://boj.kr/fcd7865516714250b793198455241046
*/
#include <bits/stdc++.h>
using namespace std;

double total_count, avg_value;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> total_count >> avg_value;
  cout << (avg_value - 1) * total_count + 1;

  return 0;
}