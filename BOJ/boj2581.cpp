/** 소수
https://www.acmicpc.net/problem/2581
http://boj.kr/786c66268eaf4c5690fe90078a43fef4
*/
#include <bits/stdc++.h>
using namespace std;

long long m, n, total_sum;
int arr[10002];
vector<int> prime_v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;

  for(int i = 2; i <= n; i++){
    if(arr[i] == 1) continue;
    for(int j = i * 2; j <= n; j+= i){
      arr[j] = 1;
    }
  }

  for(int i = 2; i <= n; i++){
    if(arr[i] == 0 && i >= m) {
      prime_v.push_back(i); total_sum += i;
    }
  }
  (total_sum == 0) ? cout << -1 : cout << total_sum << '\n' << prime_v[0];
  return 0;
}
