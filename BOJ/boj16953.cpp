/** A->B
 https://www.acmicpc.net/problem/16953
 http://boj.kr/701cb5ca35464d5eb777e480f4a75bea
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll A, B;
queue<pair<ll, ll>> qu;

int bfs(int a, int cnt){
  int answer = -1;
  qu.push({a, cnt});

  while(!qu.empty()){
    pair<ll,ll> p = qu.front();
    qu.pop();

    if(p.first == B) {answer = p.second; break;}
    if(p.first * 2 <= B)  qu.push({p.first * 2, p.second + 1});
    if(p.first * 10 + 1 <= B) qu.push({p.first * 10 + 1, p.second+1});
  }
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B;
  cout << bfs(A, 1) ;
  return 0;
}
