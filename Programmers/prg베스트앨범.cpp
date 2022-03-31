#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){ // 재생횟수 내림차순
  return (a.first > b.first);
}

bool cmp_play(pair<string,int> &a, pair<string,int> &b){
  return (a.second > b.second);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
  vector<int> answer;
  unordered_map<string, int> playcnt; // 장르, 재생시간
  unordered_map<string, vector<pair<int,int>>> genre_playlist; // 장르, vector<재생횟수, 고유번호>
  vector<pair<string, int>> genre_play_cnt_v; // genre_playlist 를 재생횟수로 정렬하기 위함.

  for(int i = 0; i <genres.size(); i++){
    genre_playlist[genres[i]].push_back({plays[i], i}); // {재생시간, 고유번호}
    playcnt[genres[i]] += plays[i]; // 장르별 재생횟수 카운팅
  }

  for(auto &p : genre_playlist){ // p: 장르별 벡터
    sort(p.second.begin(), p.second.end(), cmp); // 벡터 정렬 : 재생횟수 내림차순
  }

  // map<string,int> -> vector<pair<string,int>>
  genre_play_cnt_v.assign(playcnt.begin(), playcnt.end());
  sort(genre_play_cnt_v.begin(), genre_play_cnt_v.end(), cmp_play); // 장르별 재생횟수 내림차순

  for(int i = 0; i < genre_play_cnt_v.size(); i++){
    string genre_name = genre_play_cnt_v[i].first;
    for(int j = 0; j < genre_playlist[genre_name].size() && j < 2; j++){
      answer.push_back(genre_playlist[genre_name][j].second);
    }
  }

  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
  vector<int> plays = {500, 600, 150, 800, 2500};

  vector<int> answer = solution(genres, plays);

  for(auto a : answer) cout << a << ' ' ;
  return 0;
}
