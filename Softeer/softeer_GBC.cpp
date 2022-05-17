#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, answer;
vector<int> limit, test;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  while(n--){
    cin >> a >> b;
    for(int i = 0; i < a; i++) limit.push_back(b);
  }
  while(m--){
    cin >> a >> b;
    for(int i = 0; i < a; i++) test.push_back(b);
  }

  for(int i = 0; i < 100; i++){
    answer = max(answer, test[i] - limit[i]);
  }

  cout << answer;
  return 0;
}