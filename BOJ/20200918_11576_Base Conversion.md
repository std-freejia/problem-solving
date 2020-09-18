### 문제

[Base Conversion  백준 11576번](https://www.acmicpc.net/problem/11576)

</br>

### 리뷰

A진법 수를 입력받아서 B진법으로 변환하여 출력하는 문제.

</br>

A진수 -> 10진수 -> B진수 로 변환하여 풀었다. 

스택을 이용했다.  A진수를 스택에 전부 넣고, top 부터 꺼낸다. 

A의 0승 (==1) , A의 1승 (== A^1), A의 2승(==A^2) 순서로 숫자를 곱하면 10진수를 얻을 수 있다. 

```c++
while(m--){  //  m개 입력받기  
    int input = 0;
    cin >> input;
    an.push(input);
}
	
int n = 0; // n승 

// A-> 10 
while(!an.empty()){
    decimal += ( pow(A, n) * an.top());
    n++; 
    an.pop();
}
```

</br>

10진수를 B진수로 변환 하려면 계속 B로 나눈 나머지를 스택에 push 한다. 

이것을 거꾸로 꺼내면 B진수를 출력할 수 있다. 

```c++
	// 10 -> B
	while(decimal > 0){
		bn.push(decimal % B);
		decimal /= B;
	}
	
	while(!bn.empty()){
		cout << bn.top() << ' ';
		bn.pop();
	}
```



</br>

### 맞은 코드 

```c++
#include <iostream>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;

int A, B, m;
int decimal;
stack<int> an, bn;

int main(){

	cin >> A >> B >> m;
		
	while(m--){  //  m개 입력받기  
		int input = 0;
		cin >> input;
		an.push(input);
	}
	
	int n = 0;  // n승 
	
	// A-> 10 
	while(!an.empty()){
		decimal += ( pow(A, n) * an.top());
		n++; 
		an.pop();
	}
	
	// 10 -> B
	while(decimal > 0){
		bn.push(decimal % B);
		decimal /= B;
	}
	
	// print 
	while(!bn.empty()){
		cout << bn.top() << ' ';
		bn.pop();
	}
	
	return 0;
}
```

</br>