#include <bits/stdc++.h>
using namespace std;

int n, m, k; // 레일 개수, 바구니 무게, 일의 개수
int answer = 2e9;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  vector<int> rail(n, 0);

  for(int i = 0; i < n; i++)  cin >> rail[i];
  sort(rail.begin(), rail.end());

  do{
    int cnt = 0, sum = 0, temp = 0, idx = 0;

    while(cnt < k){
      temp = 0;
      while(temp + rail[idx] <= m){
        temp += rail[idx];
        sum += rail[idx];
        idx = (idx + 1) % n;
      }
      cnt++;
    }
    answer = min(sum, answer);
  }while(next_permutation(rail.begin(), rail.end()));

  cout << answer;
  return 0;
}