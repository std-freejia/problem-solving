/** 잃어버린 괄호
 https://www.acmicpc.net/problem/1541
 http://boj.kr/995d60d62f224a80b487a605afdbead2
 * */
#include <bits/stdc++.h>
using namespace std;

string input, temp_st;
int num;
bool minus_flag;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;
  int len = input.size();

  for(int i = 0; i <= len; i++){
    if(input[i] == '-' || input[i] == '+' || i == len){
      (minus_flag) ? num -= stoi(temp_st) : num += stoi(temp_st);
      temp_st = "";
    }else {
      temp_st += input[i];
    }
    if(input[i] == '-') minus_flag = true; // '-'이 다음에 나오는 숫자는 모두 뺀다
  }

  cout << num;
  return 0;
}
