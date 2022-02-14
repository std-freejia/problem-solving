/** 카드
 https://www.acmicpc.net/problem/11652
 http://boj.kr/55d741447092483ebc27d58c9560e652
 */
#include <bits/stdc++.h>
using namespace std;

int n, maxnum;
long long num, answer;
map<long long, int> card_map; //<숫자, 개수>

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n--){
    cin >> num;
    card_map[num]++;
  }

  for(auto n : card_map){
    if(n.second > maxnum) {
      maxnum = n.second;
      answer = n.first;
    }
  }
  cout << answer;

  return 0;
}