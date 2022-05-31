#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;

int D[60001];
int solution(int n) {

  D[1] = 1, D[2] = 2;

  for (int i = 3; i <= n; i++) {
    D[i] = (D[i - 1] + D[i - 2]) % MOD;
  }
  return D[n];
}