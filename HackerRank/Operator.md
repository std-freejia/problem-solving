## Operators

HackerRank Coding Chanllenge Day2

-----

double, int 자료형을 계산하여 실수형이 나오는데. 

가장 가까운 int로 답을 출력하는 문제다. 

 </br>

중요한 건 **반올림 함수 round()** . *가장 가까운* int 로 출력해야 하기 때문이다. 

```c++
#include <cmath>

//  round(12.62)  -> 12 가 반환된다 
double round(double num);
long double round(long double num);
```

</br>

참고]  버림 함수  trunc()   

소수점 아래 수는 정수로 바꾼다.

```c++
#include <cmath>

float trunc(float num);
double trunc(double num);
long double trunc(long double num);

// trunc(3.97)  -> 3

```

 truncate  단어를 줄여서 만들었나보다. 

<br>

-----------------

### 내 코드 

```c++
void solve(double meal_cost, int tip_percent, int tax_percent) {

    double total = meal_cost;
    double tip = (double)tip_percent * meal_cost / 100;
    double tax = (double)tax_percent * meal_cost / 100;

    cout << round(total + tip + tax);

    return;
}
```

</br>