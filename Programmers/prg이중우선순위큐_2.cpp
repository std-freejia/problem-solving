#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> op) {
  vector<int> answer = {0,0};
  vector<int> v;

  for(auto s : op){
    string order = s.substr(0, 1); // 명령
    int num = stoi(s.substr(2)); // 숫자

    if(order == "I") {
      v.push_back(num);
      sort(v.begin(), v.end(), greater<>()); // 푸시하고 바로 정렬.
    }
    else {
      if(v.size() == 0) continue;

      (num == -1) ? v.erase(v.end()-1) : v.erase(v.begin());
    }
  }

  if(!v.empty()) {
    answer.clear();
    answer = {v[0], v[v.size()-1]};
  }
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> input = {"I 7","I 5","I -5","D -1"};
  //vector<string> input = {"I 16", "D 1"};
  vector<int> v = solution(input);

  cout << v[0] << ' ' << v[1];
  return 0;
}