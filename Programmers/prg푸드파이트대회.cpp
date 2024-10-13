#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int size_of_food = food.size();
    
    for(int i = 1; i < size_of_food; i++ ) {
        if (food[i]/2 < 1) continue;
        else { 
            for(int j = 0; j < food[i]/2; j++ )  {
                answer += to_string(i);
            }
        };
    }

    string reversed_str = answer;
    reverse(reversed_str.begin(), reversed_str.end());
    
    answer += "0";
    answer += reversed_str;
    
    return answer;
}
