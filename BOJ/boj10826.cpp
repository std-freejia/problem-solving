/** 피보나치 수 4
https://www.acmicpc.net/problem/10826
**/
#include <bits/stdc++.h>
using namespace std;

int n, sum;
string a, b, tmp, fibo[10002];
vector<int> ans, num1, num2;

string big_num_sum(string s1, string s2){

  string s = "";

  // 더 긴 수를 s1에 저장한다.
  if(s1.size() < s2.size()) swap(s1, s2);

  // num1, num2 배열을 만든다.
  num1.push_back(0);
  num2.push_back(0);

  // s1이 더 긴 수니까. 그대로 num1 벡터를 채운다.
  for(int i = 0; i < s1.size(); i++)
    num1.push_back(s1[i] - '0');

  // s2가 비교적 짧은 수니까. s1, s2 길이 차이만큼 0을 num2 벡터에 채운다.
  for(int i = 0; i < s1.size() - s2.size(); i++)
    num2.push_back(0);

  for(int i = 0; i < s2.size(); i++)
    num2.push_back(s2[i] - '0');

  // num1, num2 벡터 맨 뒤부터 앞쪽으로 덧셈을 하면서 ans 벡터에 저장
  for(int i = s1.size(); i > 0; i--){
    sum = num1[i] + num2[i];
    if(sum > 9){
      num1[i-1] += 1; // 올림 수 발생했으니까 1을 더해준다.
      sum -= 10;
    }
    ans.push_back(sum);
  }

  // 맨 앞자리수에 올림수가 넘어왔다면,
  if(num1.front() != 0) s.push_back('1');

  // ans 벡터 원소 순서를 거꾸로.
  reverse(ans.begin(), ans.end());
  // ans 벡터의 숫자를 순차 출력하여 문자열 s에 이어붙인다.
  for(auto n : ans){
    s.push_back(n+48); // 문자로 저장해야 하니까 48을 더해준다.
  }
  num1.clear(); num2.clear(); ans.clear();
  return s;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  fibo[0] = "0";
  fibo[1] = "1";

  for(int i = 2; i <= n; i++){
    fibo[i] = big_num_sum(fibo[i-1], fibo[i-2]);
  }
  cout << fibo[n];

  return 0;
}