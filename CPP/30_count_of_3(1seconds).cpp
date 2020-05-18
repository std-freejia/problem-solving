#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 30. 3의 개수는? (제한시간 1초)  

/*
- N의 크기가 크다. 제한시간 1초.  

자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자 중 3의 개수가 몇 개 있는지 구하려고 합니다.
예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로 3의 개수는 2개입니다.
자연수 N이 입력되면 1부터 N까지 숫자를 적을 때, 3의 개수가 몇 개인지 구하여 출력하는 프로그램을 작성하세요.

첫 줄에 자연수의 개수 N(3<=N<=1,000,000,000)이 주어집니다.


입력 input.txt
15

출력 
2 
*/


int main(int argc, char** argv) {
	
	
	int num = 0, left_num = 1, right_num = 0, k = 1, current = 0, res = 0; 
	 
	freopen("input.txt", "rt", stdin);	

	scanf("%d", &num);

	// num = 12345 라면, 
	 
	while(left_num != 0){

		left_num = num / (k*10);
		right_num = num % k;
		
		current = (num/k)%10; // 현재 3으로 고정시킬 숫자를 특정한다.  5 -> 4 -> 3으로 변한다.  
		
		if(current > 3) res = res + (left_num + 1) * k;
		else if(current == 3) 
			res = res + (left_num * k)  + (right_num + 1);
		else res = res + (left_num * k);
		
		k *= 10;
	}

	printf("%d", res);
	return 0;
}

/*
어려운 문제. 
시간 제한이 1초인데 N의 최대값이 커서 막막했다. 

N = 12345 인 경우, 

일의 자리를 3으로 고정하고 나머지 자리수의 자리에 어떤 수들이 올 수 있는지 생각해본다. 
십이 자리를 3으로 고정하고, 나머지 1 2 3 그리고 5 자리에 어떤 수들이 올 수 있나 따져본다. 


*/

