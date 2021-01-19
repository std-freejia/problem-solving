## Angry Professor

HackerRank Algorithm

-----

교수님은 최소 k명의 학생이 수업 시작 시간에 도착해야 화가나지 않는다. 

음수 는 일찍온 학생. 0은 제시간에 온 학생. 양수는 지각한 학생이다. 

음수와 0 의 개수가 k명보다 작거나 같은지 판단하는 문제다. 

</br>

### 내 코드 

```c++
string angryProfessor(int k, vector<int> a) {

    sort(a.begin(), a.end());

    int cnt = 0;
    string answer = "NO";

    for (int i = 0; i < a.size() && cnt < k; i++) {
        if (a[i] <= 0) { // 일찍오거나 정시에 온 학생 카운트
            cnt++;
        }
    }

    if (cnt < k) answer = "YES"; // 화남 

    return answer;
}
```

</br>