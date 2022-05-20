#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll p, n, total_cnt, num;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> p >> n;
  while(n--){
    cin >> num; // 바이러스 개수 입력받기
    total_cnt = (total_cnt * p + num) % MOD;
  }
  cout << total_cnt;
  return 0;
}