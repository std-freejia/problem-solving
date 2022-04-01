#include <bits/stdc++.h>
using namespace std;

// https://programmers.co.kr/learn/courses/30/lessons/43163

bool check[51]; // 해당 word를 탐색하는데 필요한 최소 횟수

int solution(string begin, string target, vector<string> words) {
  int min_cnt = 1e9;
  int vector_size = words.size();
  int word_size = begin.size();

  queue<pair<int,string>> qu;
  qu.push({0, begin});

  while(!qu.empty()){
    int cnt = qu.front().first;
    string current_s = qu.front().second; // 비교 문자열
    qu.pop();

    for(int i = 0; i < vector_size; i++){
      // 이미 확인한 문자 지나감
      if(check[i]) continue;

      // 현재 문자열과 i번째 문자열이 1개만 다른지 확인
      int diff_cnt = 0;
      for(int d = 0; d < word_size; d++){
        if(words[i][d] != current_s[d]) diff_cnt++;
      }

      if(diff_cnt == 1){
        if(words[i] == target) { min_cnt = cnt + 1; break; } // 찾음
        qu.push({cnt+1, words[i]}); // 1개만 다르니까 여기로 이동
        check[i] = true; // 이동했으니까 표시
      }
    }
  }
  if(min_cnt == 1e9) min_cnt = 0;
  return min_cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string begin = "hit";
  string target = "cog";
  vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
  cout << solution(begin, target, words) << '\n';

  vector<string> ws = {"hot", "dot", "dog", "lot", "log"};
  cout << solution(begin, target, ws);

  return 0;
}
