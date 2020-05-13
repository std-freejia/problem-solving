#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 27. N!의 표현법  factorial_expression

/*
임의의 N에 대하여 N!은 1부터 N까지의 곱을 의미한다. 
이러한 큰 수를 표현하는 방법으로 소수들의 곱으로 표현하는 방법이 있다. 

예를 들면 825는 (0 1 2 0 1)로 표현이 가능한데, 
이는 2는 없고 3은 1번, 5는 2번, 7은 없고, 11은 1번의 곱이라는 의미이다. 
101보다 작은 임의의 N에 대하여 N 팩토리얼을 이와 같은 표기법으로 변환하는 프로그램을 작성해보자. 

첫 줄에 자연수 N(3<=N<=1000)이 입력된다.


입력예제1 
input.txt
5

출력예제1 
5! = 3 1 1

*/


int main(int argc, char** argv) {

	int num = 0, i=0, j=0, temp = 0;
	 
	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &num);
	vector<int> prime(num+1); // 소수의 범위가 num에 의해 결정된다.  
		
	for(i=2; i<=num; i++){
		// 소수가 나올 때 마다 prime 배열의 '소수인덱스'에 ++ 해준다. 
		temp = i;
		// 소수인가? 를 검사한다.  
		j = 2;  
		
		while(temp != 1){
			if(temp%j == 0) {
				temp = temp / j;
				prime[j]++;
			}else{
				j++; // +1 해서 2 말고 3으로, 3 말고 4로 나눠본다! 
			}
		}
	}
	
	printf("%d! = ", num);
	
	// prime 배열에서 0이 아닌 숫자들을 출력.
	for(i=2; i<=num; i++){
		if(prime[i] != 0) printf("%d ", prime[i]);
	}
	 
	return 0;
}

/*
처음에 어떻게 풀어야 되는지 잘 생각이 안났다.  

6을 소인수분해하는  과정을 떠올려보자. 
6을 2로 나눈다. 나눠진다. 
몫이 3이 된다. 이것을 또 2로 나눈다.(항상 2로 먼저 나눠본다!) .  안 나눠진다.  
안나눠지니까 2에 +1해서 3으로 나눠본다. 
몫이 1이 되는 순간 종료한다.

즉, 6의 소인수는 2와 3이 된다.  

*/
