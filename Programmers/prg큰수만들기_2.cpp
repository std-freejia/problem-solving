#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
  int length_limit = number.size() - k;

  for(int i = 0; i < length_limit; ++i){
    auto iter = max_element(number.begin() + i, number.begin() + i + k + 1);
    if(iter != number.begin() + i){
      k = k - distance(number.begin() + i, iter);
      number.erase(number.begin() + i, iter);
    }
  }
  number.erase(number.end()-k, number.end());
  return number;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string number = "4177252841";
  int k = 4;

  cout << solution(number, k);

  return 0;
}
