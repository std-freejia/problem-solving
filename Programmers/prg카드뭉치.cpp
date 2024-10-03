#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int idxOne = 0; 
    int idxTwo = 0;

    for(int i = 0; i < goal.size(); i++){
        if (cards1[idxOne] == goal[i] && idxOne < cards1.size()) {
            idxOne++;
        }
        else if(cards2[idxTwo] == goal[i] && idxTwo < cards2.size()) {
            idxTwo++;
        } 
        else {
            return "No";
        }
    }

    return "Yes";
}
