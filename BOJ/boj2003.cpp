#include <bits/stdc++.h>
#define ll long long
using namespace std;
//http://boj.kr/4bec6ec603df4408b01a28b00cf8a188

ll a, b, sum, n, m, answer;
int arr[10005];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++ ) cin >> arr[i];

  sum = arr[a];
  while(b < n && a <= b){
    if(sum <= m){
      if(sum == m) answer++;
      sum += arr[++b];
    }else { // sum > m
      sum -= arr[a++];
      if(a > b){
        b = a;
        sum = arr[a];
      }
    }
  }
  cout << answer;
  return 0;
}