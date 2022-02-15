/** 숫자 카드
 https://www.acmicpc.net/problem/10815
 http://boj.kr/31445611a2554e39bd4c3ea913ca6042
 * */
#include <bits/stdc++.h>
using namespace std;

int n, m, num;
map<int, int> nmap;

int change(int &minus){
  minus *= (-1); // 양수로 변환
  minus += 10000001; // 인덱스 안겹치게 더해준다
  return minus;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n--){
    cin >> num;
    if(num < 0) num = change(num);
    nmap[num]++; // num은 겹치지 않으니까, 숫자가 있으면 1로 표시.
  }
  cin >> m;
  while(m--){
    cin >> num;
    if(num < 0) num = change(num);
    cout << nmap[num] << ' ';
  }
  return 0;
}