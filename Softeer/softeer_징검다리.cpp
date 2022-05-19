#include <bits/stdc++.h>
using namespace std;

int n, num;
vector<int> v;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cin >> num;
  v.push_back(num);  // 첫 번째 숫자는 비교할 게 없으니까 바로 넣는다.

  for(int i = 1; i < n; i++){
    cin >> num;

    for(int j = v.size()-1; j >= 0; j--){
      if(v[j] < num){
        if(j == v.size()-1) v.push_back(num); // 가장 크니까 push
        else v[j+1] = num; // 값 교체
        break;
      }
      if(j == 0) v[0] = num;
    }
  }
  cout << v.size();
  return 0;
}