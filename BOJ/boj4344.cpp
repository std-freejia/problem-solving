/** 평균은 넘겠지
 https://www.acmicpc.net/problem/4344
 http://boj.kr/0bc4723f23bc49838f60dbf049a262c8
 */
#include <bits/stdc++.h>
using namespace std;

int c, n, sum, avg, cnt;
double answer;
int arr[1002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> c;
  while(c--){
    cin >> n;

    sum = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
      cin >> arr[i]; sum += arr[i];
    }
    avg = sum / n;
    for(int i = 0; i < n; i++) {
      if(arr[i] > avg) cnt++;
    }
    answer = (double)cnt / n * 100;
    cout << fixed;
    cout.precision(3);
    cout << answer << "%\n";
  }
  return 0;
}
