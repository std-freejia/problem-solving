#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
  int answer = 1;
  int start = n/2;

  for(int i = start; i > 0; i--){ // start 부터 1 까지.
    int sum = i, j = i+1; // 합을 저장할 sum, 더해줄 숫자 j
    while(sum <= n){
      sum += (j++);
      if(sum == n) {answer++; }
    }
  }
  return answer;
}