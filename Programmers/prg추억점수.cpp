#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unsigned int name_size = name.size();
    unsigned int photo_size = photo.size();

    map<string, int> name_yarning;
    for (unsigned int i = 0; i < name_size; ++i) {
        name_yarning[name.at(i)] = yearning.at(i);
    }
    for (unsigned int i = 0; i < photo_size; ++i) {
        vector<string> single_photo = photo.at(i);
        unsigned int length = single_photo.size();
        int score = 0;

        for(unsigned int i = 0; i < length; ++i) {
            score += name_yarning[single_photo[i]];
        }
        answer.push_back(score);
    }
    return answer;
}
