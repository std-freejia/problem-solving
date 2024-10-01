#include <string>
#include <vector>
#include <bitset>
using namespace std;

int solution(int n) {
    int target_count = bitset<20>(n).count();
    // 익명 객체로 bitset 을 선언한다 
    while(bitset<20>(++n).count() != target_count);
    return n;
}
