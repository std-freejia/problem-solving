/** 집합
 * https://www.acmicpc.net/problem/11723
 * http://boj.kr/f80ca02a2929452a87b5ba11ad934551
 * */
#include <bits/stdc++.h>
using namespace std;

int m, num, x;
string command;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m;
  while(m--){
    cin >> command;
    if(command == "add"){
      cin >> num;
      x |= (1 << num); // OR 연산 num 번째 자리 수를 1로 채운다
    }
    else if(command=="remove"){
      cin >> num;
      x &= ~(1 << num); // 반전시킨 num을 AND 연산한다.
    }
    else if(command =="check"){
      cin >> num;
      if( x & (1 << num))
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }else if(command =="toggle"){
      cin >> num;
      x ^= (1 << num); // num 번째 자리가 1이면 1^1 = 0,  0이라면 0^1 = 1
    }
    else if(command == "all"){
      x = (1 << 21) -1;
    }else if(command =="empty"){
      x = 0;
    }
  }

  return 0;
}