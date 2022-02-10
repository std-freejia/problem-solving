/** 시리얼 번호
https://www.acmicpc.net/problem/1431
 */
#include <bits/stdc++.h>
using namespace std;

int n; // 기타 개수
string st;
vector<string> v;

int digit_sum(string &a){
  int sum = 0;
  for(auto num : a) {
    if(isdigit(num) == true) sum += (num - '0');
  }
  return sum;
}

bool check(string &a, string &b){

  int alen = a.size(), blen = b.size();
  int asum = digit_sum(a), bsum = digit_sum(b);

  // 길이가 다르면 길이끼리 비교
  if(alen < blen) return alen < blen;

  // 합이 다르면 합끼리 비교
  if(asum != bsum) return asum < bsum;
  // 사전순
  return a < b;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  while(n--){
    cin >> st;
    v.push_back(st);
  }
  sort(v.begin(), v.end(), check);
  for(auto s : v) cout << s << '\n';

  return 0;
}