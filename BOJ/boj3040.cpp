/** 백설 공주와 일곱 난쟁이
 * https://www.acmicpc.net/problem/3040
 * http://boj.kr/c355dae653864cd9a0f521cae35cf32c
 * */
#include <bits/stdc++.h>
using namespace std;

int totalsum;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> hat(9);
  vector<int> check(9);
  check[7] = check[8] = 1;

  for(int i = 0; i < 10; i++){
    cin >> hat[i]; totalsum += hat[i];
  }

  do{
    int temp = 0;
    for(int i = 0; i < 9; i++){
      if(check[i])temp += hat[i];
    }
    if((totalsum - temp) == 100){
      for(int i = 0; i < 9; i++){
        if(!check[i]) cout << hat[i] << '\n';
      }
    }
  }while(next_permutation(check.begin(), check.end()));

  return 0;
}