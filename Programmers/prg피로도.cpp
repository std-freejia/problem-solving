#include <bits/stdc++.h>
#define ll long long
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
  int answer = -1;
  int dungeons_cnt = dungeons.size();
  vector<int> permu_v;

  // 던전개수만큼 순열을 돌릴 i를 넣는다.
  for(int i = 0; i < dungeons_cnt; i++) permu_v.push_back(i);

  do{
    int temp_k = k, cnt = 0;

    for(int i = 0; i < dungeons_cnt ; i++){
      int turn = permu_v[i]; // 던전의 인덱스
      if(temp_k < dungeons[turn][0]) { // 이동 불가
        break;
      }else{ // 이동가능. 방문 횟수 증가.
        temp_k -= dungeons[turn][1];
        cnt++;
      }
    }
    answer = max(answer, cnt);
  }while(next_permutation(permu_v.begin(), permu_v.end()));

  return answer;
}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k = 80;
  vector<vector<int>> dungeons{{80, 20}, {50, 40}, {30, 10}};

  cout << solution(k, dungeons);

  return 0;
}