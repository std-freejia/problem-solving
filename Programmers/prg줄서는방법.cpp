#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll factorial(int n){
  if(n == 1) return 1;
  else return n * factorial(n-1);
}
vector<int> solution(int n, long long k) {
  vector<int> answer;

  long long idx, target_num;
  vector<int> num_v;
  for(int i = 1; i <= n; i++) num_v.push_back(i);

  while(0 < n){
    idx = factorial(n) / n;
    target_num = int((k-1) / idx); // answer에 넣을 숫자
    answer.push_back(num_v[target_num]);
    num_v.erase(num_v.begin() + target_num);
    n--;
    k %= idx;
    if(k == 0) k = idx;
  }

  return answer;
}