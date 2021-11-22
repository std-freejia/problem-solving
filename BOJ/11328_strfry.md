### 문제

[strfry  백준 11328 c++](https://www.acmicpc.net/problem/11328)



### "맞았습니다."코드 

```c++
#include <bits/stdc++.h>
using namespace std;

int T;

void func(string a, string b){

    int cntA[35] = {};
    int cntB[35] = {};

    for(int i = 0; i < a.length(); i++){
        cntA[a[i]-97]++;
    }
    for(int i = 0; i < b.length(); i++){
        cntB[b[i]-97]++;
    }

    string answer = "Possible\n";
    for(int i = 0; i < 79-61+1; i++){
        if(cntA[i] != cntB[i]){
            answer = "Impossible\n";
            break;
        }
    }

    cout << answer;
}

void input(){
    cin >> T;
    string a, b;
    for(int i = 0; i < T; i++){
        cin >> a >> b;
        func(a, b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    return 0;
}
```

![image-20211121232454126](/Users/jiaryu/Library/Application Support/typora-user-images/image-20211121232454126.png)



------

### 리뷰

소문자 알파벳 개수가 동일한지 비교하면 된다. 

소문자 알파벳과 ascii 코드를 매칭하기 위해 문자열에서 97을 뺐다. 

소문자 a에서 97을 빼면 0이 나온다. 소문자 a부터 소문자 z까지 아스키코드는 연속적이니까 이렇게 인덱스로 매칭 할 수 있다. 

단어에서 a의 개수를 배열의 0인덱스의 값에 저장했다. b의 개수는 배열의 1인덱스 값에 저장했다.   