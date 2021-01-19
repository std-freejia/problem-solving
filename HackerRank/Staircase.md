## Staircase

HackerRank Algorithm Warmup

-----

계단처럼 '#'을 찍는 문제다. 별찍기 문제랑 비슷하다. 

line 0 :  ' ' space 3개 + '#'  1개 

line 1 :  ' ' space 2개 + '#'  2개 

line 2 :  ' ' space 1개 + '#'  3개 

내코드는 for문을 3개 써서 풀었는데. 다른 분 코드가 인상깊어서 덧붙인다. 

</br>

### 내 코드 

```c++

void staircase(int n) {

    int len = n;

    for (int i = len-1; i >=0; i--) {

        for (int j = 0; j < i; j++) {
            cout << ' ';
        }

        for (int k = 0; k < len - i; k++) {
            cout << '#';
        }
        cout << '\n';
    }

}
```

</br>

### 다른 분 코드

```c++
void staircase(int n) {
    for(int i = 1 ; i <= n ; i++){
        string h(i, '#');
        string s(n-i, ' ');
        cout << s << h <<'\n';
 }
```

</br>

 