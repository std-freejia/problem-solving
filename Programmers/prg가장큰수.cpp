#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
  return a+b > b+a;
}
string solution(vector<int> numbers) {
  string answer = "";

  vector<string> str_num;
  for(auto n : numbers) str_num.push_back(to_string(n));
  sort(str_num.begin(), str_num.end(), cmp);

  if(str_num[0] != "0") for(auto n : str_num) answer += n;
  else answer = "0";

  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> numbers{6, 10, 2};
  cout << solution(numbers);

  return 0;
}
