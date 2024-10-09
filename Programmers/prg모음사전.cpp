#include <string>
#include <vector>

using namespace std;

int cnt = -1;
int answer = 0;
string aeiou = "AEIOU";
string target = "";

void dfs(string word) {
    cnt++;
    
    if (word == target) {
        answer = cnt;
        return;
    }
    if (word.length() == 5) {
        return;
    }
    
    for(int i = 0; i < 5; i++) {
        dfs(word + aeiou[i]);
    }
}
int solution(string word) {
    target = word;
    dfs("");
    return answer;
}
