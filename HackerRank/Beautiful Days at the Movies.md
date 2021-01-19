## Beautiful Days at the Movies

HackerRank  Algorithm 

-----



숫자를 뒤집는 것이 핵심이다. 

```c++
// 123 -> 321 
```

이렇게 뒤집을 때 int 를 string 으로 형변환 해서 reverse() 함수를 썼다. 

```c++
// int to string
int a = 123;
string st = to_string(a);
reverse(st.begin(), st.end());
```

문자열을 정수로 다시 바꿀 때는 stoi() 를 쓴다.

```c++
int temp = stoi(st);
```

</br>

문제에서 요구하는 'Beautiful day ' 기준은 아래와 같다. 

k = 6 인 경우, 

```c++
// Beautiful 
20 을 뒤집은 02 를 뺄셈해서 절대값을 구하면, 20 - 2 == 18    // abs()로 절대값을 구한다. 
18을 k로 나눈 나머지가 0 이면 Beautiful 이다. 
    
// Not Beautiful 
23 을 뒤집은 32 를 뺄셈해서 절대값을 구하면, 23 - 32  == 9
9를 k로 나눈 나머지가 0 이 아니므로 Not Beautiful
```

</br>

--------------------------



</br>

### 내 코드 

```c++

int beautifulDays(int i, int j, int k) {
    int answer = 0;

    for (int a = i; a <= j; a++) {

        string st = to_string(a); // int to string 
        reverse(st.begin(), st.end()); // reverse string 

        if (abs(a - stoi(st)) % k == 0) { // string to int  && abs() 
            answer++;
        }
    }
    
    return answer;
}
```

</br>