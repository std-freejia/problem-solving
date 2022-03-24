#include <bits/stdc++.h>
using namespace std;

map<string, int> runner;
map<string, int>::iterator it;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";

  for(auto i : participant) runner[i]++;
  for(auto i : completion) --runner[i];

  for(it = runner.begin(); it != runner.end(); it++){
    if(it->second > 0) answer = it->first;
  }
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> participant{"marina", "josipa", "nikola", "vinko", "filipa"};
  vector<string> completion{"josipa", "filipa", "marina", "nikola"};

  cout << solution(participant, completion);

  return 0;
}
