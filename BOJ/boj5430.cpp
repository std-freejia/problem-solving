/** AC
 https://www.acmicpc.net/problem/5430
 http://boj.kr/aa77322992894acbb6861533c6eb4387
 */
#include <bits/stdc++.h>
using namespace std;

int t, n;
string func, arr;

void check(string f, int n, string arr){
  string answer = "";
  bool flag = true;
  bool reverse_flag = false;
  deque<int> dq;

  string st_digit = "";
  for(int i = 0; i < arr.length(); i++){
    if(isdigit(arr[i])){
      st_digit += arr[i];
    }else{
      if(!st_digit.empty()){
        dq.push_back(stoi(st_digit));
        st_digit = "";
      }
    }
  }

  for(auto o : f){
    if(o == 'R') reverse_flag = !reverse_flag;
    else {
      if(dq.empty()) { flag= false; cout << "error\n"; break; }
      if(reverse_flag)  dq.pop_back();
      else dq.pop_front();
    }
  }

  if(flag){
    cout << "[";

    if(reverse_flag){ // 뒤집혀있다면,
      for(auto d = dq.rbegin(); d != dq.rend(); d++){
        if(d == dq.rend()-1) {
          cout << *d;
        }
        else { cout << *d << ","; }
      }
    }else{
      for(auto d = dq.begin(); d != dq.end(); d++){
        if(d == dq.end()-1) {
          cout << *d;
        }
        else { cout << *d << ","; }
      }
    }
    cout << "]\n";
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;
  while(t--){
    cin >> func >> n >> arr;
    check(func, n, arr);
  }
  return 0;
}
