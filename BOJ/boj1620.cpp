/** 나는야 포켓몬 마스터 이다솜
 * https://www.acmicpc.net/problem/1620
 * http://boj.kr/9824628bbcca46169a0da242faedb99f
 * */
#include <bits/stdc++.h>
using namespace std;

int n, m; // 포켓몬개수, 문제개수
string name, input;
map<string, int> smap; // 문자 입력 -> 숫자출력
map<int, string> nmap; // 숫자 입력 -> 문자출력

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> name;
    smap.insert({name, i}); // {이름, 인덱스}
    nmap.insert({i, name}); // {인덱스, 이름}
  }

  for(int i = 0; i< m; i++){
    cin >> input;
    if(isdigit(input[0])){ // 숫자라면 0이 아닌 수가 나온다
      cout << nmap[atoi(input.c_str())]<< '\n';
    }else{ // 문자
      cout << smap[input] << '\n';
    }
  }

  return 0;
}