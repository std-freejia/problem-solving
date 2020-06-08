#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

// 41. 연속된 자연수의 합  successive_sum

/*
입력으로 양의 정수 N이 입력되면 2개 이상의 연속된 자연수의 합으로 정수 N을 표현하는 방법의 가짓수를 출력하는 프로그램을 작성하세요.

N=15이면, 
7+8=15
4+5+6=15
1+2+3+4+5=15
와 같이 총 3가지의 경우가 존재한다.

▣ 입력설명
첫 번째 줄에 양의 정수 N(7<=N<1000)이 주어진다.

▣ 출력설명
첫줄부터 각각의 경우의 수를 출력한다.
맨 마지막 줄에 총 개수를 출력한다.


*/ 

int main(int argc, char** argv){
	
	//freopen("input.txt", "rt", stdin);
	int input, b = 1, cnt=0, temp, i=0;
	
	scanf("%d", &input);
	temp = input;
	input--;
	
	while(input > 0){
		b++;  // b개의 합으로 나타낼 수 있는지.  
		input = input - b;
		
		if(input % b == 0){ 
			
			for(i=1; i<b; i++){ // 분배할 숫자를 b 개를 써준다  
				printf("%d + ", (input/b)+i);
			}
			// 마지막 더하는 수와 원래숫자 출력  
			printf("%d = %d\n", (input/b)+i, temp);
			
			cnt++;
		}
	}
	
	printf("%d", cnt);
	return 0;
	
}

/*

* 15가 2개의 수의 합으로 표현되는지 본다.  

15에서 1과 2를 빼고 1과 2를 적어둔다.  
그 결과로 나온 12가 2로 나누어 떨어지는지 확인한다. 된다.  
12를 2개의 숫자에 나눠줘야 하니까.  
2로 나눈 결과 6을 1과 2에 각각 더해준다.  
1 2 
1+6, 2+6 => 7, 8이 된다. 

* 3개의 수의 합으로 표현되는지 본다. 

15에서 1, 2, 3을 빼고 1, 2, 3을 적어둔다. 
15-1-2-3 = 9 
9가 3으로 나누어 떨어지는지 본다. 된다. 몫이 3이다.  
1 2 3 
1+3, 2+3, 3+3 => 4, 5, 6이 된다. 

*/
