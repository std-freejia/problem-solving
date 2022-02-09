/** 큰 수 A+B
https://www.acmicpc.net/problem/10757
http://boj.kr/f69c7e4a781a43c99714497d86fbbdb7
**/
#include <bits/stdc++.h>
using namespace std;

string a, b;
vector<int> a_vec, b_vec, answer;

/** '0'을 더하면 숫자-> 문자로. 빼면 문자->숫자로*/
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;

  if(a.size() < b.size()) swap(a, b);

  int diff_len = a.size() - b.size();

  // a, b 문자열의 문자를 하나씩 int 벡터로 넣는다. (문자-'0' ==정수)
  for(int i = 0; i < a.size() ; i++) a_vec.push_back(a[i]-'0');
  for(int i = 0; i < diff_len; i++) b_vec.push_back(0);
  for(int i = 0; i < b.size(); i++) b_vec.push_back(b[i]-'0');

  int carry = 0; // 올림 수
  int temp_sum = 0;

  for(int i = a_vec.size()-1; i >= 0 ; i--){ // 뒤 부터 앞으로
    temp_sum = a_vec[i] + b_vec[i];

    if(carry == 1){
      temp_sum++;
      carry = 0;
    }
    if(temp_sum > 9){
      temp_sum -= 10;
      carry = 1;
    }
    //cout << temp_sum;
    answer.push_back(temp_sum);
  }
  if(carry == 1) answer.push_back(1);
  reverse(answer.begin(), answer.end());
  for(auto aa : answer) cout << aa;

  return 0;
}