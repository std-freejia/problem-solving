/** 경로 찾기
 https://www.acmicpc.net/problem/11403
 http://boj.kr/7225a54b6b4c48bc941bd36817cef8fe
 * */
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n;
int arr[102][102];

void floyd() {

  for(int k = 0; k < n; k++){ // 거쳐가는 정점
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
      }
    }
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j< n; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 0) arr[i][j] = INF;
    }
  }
  floyd();
  for(int i = 0; i < n; i++){
    for(int j = 0; j< n; j++){
      if(arr[i][j] == INF) cout << 0 << ' ';
      else cout << 1 << ' ';
    }
    cout << '\n';
  }

  return 0;
}