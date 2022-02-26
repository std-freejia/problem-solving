/** 케빈 베이컨의 6단계 법칙
https://www.acmicpc.net/problem/1389
http://boj.kr/d73a0cfe78614ba886bd1e47d7630877
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int user[102][102];

void floyd(){
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(i == j) continue;
        else if(user[i][k] > 0 && user[k][j] > 0){
          if(user[i][j] == 0){
            user[i][j] = user[i][k] + user[k][j];
          }else{
            user[i][j] = min(user[i][k] + user[k][j], user[i][j]);
          }
        }
      }
    }
  }
}
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < m; i++){ // 관계마다 인접리스트
    cin >> a >> b; user[a][b] = user[b][a] = 1;
  }

  floyd();

  int answer = 1e9;
  int usernum = 0;
  for(int i = 1; i <= n; i++){
    int tempsum = 0;
    for(int j = 1; j <= n; j++){
      tempsum += user[i][j];
    }
    if(tempsum < answer) {
      answer = tempsum; // 최소 베이컨수라면 갱신
      usernum = i;
    }
  }

  cout << usernum;

  return 0;
}
