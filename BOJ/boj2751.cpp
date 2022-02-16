/** 수 정렬하기 2
 https://www.acmicpc.net/problem/2751
 http://boj.kr/3f2a4868b7274a80b1179c63d9da6242
 */
#include "bits/stdc++.h"
using namespace std;

int n, num;
int arr[2000002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n--){
    cin >> num;
    num += 1000000;
    arr[num]++;
  }
  for(int i = 0; i < 2000002; i++){
    if(arr[i] == 1) {
      cout << i-1000000 << '\n';
    }
  }
  return 0;
}