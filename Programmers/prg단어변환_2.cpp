#include <bits/stdc++.h>
using namespace std;

string tg; // 목표
int answer = 50;  // 최소 횟수 저장
bool checked[52]; // 단어 확인 여부

bool diff_one(string cur, string w){// 현재 단어와 1글자만 다른지 확인
  int diff_cnt = 0;
  for(int i = 0; i < w.size(); i++){
    if(cur[i] != w[i]) diff_cnt++;
  }
  return (diff_cnt == 1); // 1글자만 다른 단어
}
void dfs(string s, vector<string> words, int cnt){

  if(answer <= cnt) return; // 백트레킹
  if(s == tg) { // 타겟 찾았다면 종료
    answer = min(cnt, answer); // 최소 횟수를 갱신
    return;
  }

  int w_len = words.size();
  for(int i = 0; i < w_len; i++){
    if(diff_one(s, words[i]) && !checked[i]){
      checked[i] = true;
      dfs(words[i], words, cnt + 1);
      checked[i] = false;
    }
  }
}

int solution(string begin, string target, vector<string> words) {

  tg = target; // 시작단어와 타겟단어 전역변수
  dfs(begin, words, 0);
  if(answer == 50) answer = 0; // 타겟 못찾음
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string begin = "hit";
  string target = "cog";
  vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
  cout << solution(begin, target, words);
  return 0;
}
