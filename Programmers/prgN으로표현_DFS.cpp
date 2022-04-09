#include <bits/stdc++.h>
using namespace std;

int global_N, target_number;
int max_cnt = 8;
int min_cnt = 1 + max_cnt;

void dfs(int cur_num, int cnt){ // (현재 숫자, N을 사용한 개수)
  if(cnt > max_cnt) return;
  else if(cur_num == target_number){
    min_cnt = min(cnt, min_cnt);
    return;
  }

  int n = 0;  // 계산할 숫자 n -> N, NN, NNN
  for(int i = 1; i <= 6; i++){ // N을 1개~6개 사용가능

    n = n*10 + global_N;
    dfs(cur_num + n, cnt + i);
    dfs(cur_num - n, cnt + i);
    if(cur_num != 0 || cnt > 8){
      dfs(cur_num * n, cnt + i);
      dfs(cur_num / n, cnt + i);
    }
  }
}

int solution(int N, int number) {
  global_N = N;
  target_number = number;
  dfs(0, 0);
  return (min_cnt == 9) ? -1 : min_cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 5;
  int number = 12;
  cout << solution(n, number);
  return 0;
}