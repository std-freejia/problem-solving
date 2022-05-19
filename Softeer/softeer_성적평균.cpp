#include <bits/stdc++.h>
using namespace std;

int n, k, num, a, b;
int score[10000001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  for(int i = 1; i <= n; i++){
    cin >> num;
    score[i] = score[i-1] + num;
  }
  for(int i = 0; i < k; i++){
    cin >> a >> b;
    double cnt = (b-a) + 1;
    double sum = score[b]-score[a-1];
    double res = (double) sum / cnt;
    res = ceil(res * 100) / 100;
    printf("%.2f\n", res);
  }

  return 0;
}