#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 28. N!에서 0의 개수    the_number_of_zero

/*
자연수 N이 입력되면 N! 값에서 일의 자리부터 연속적으로 ‘0’이 몇 개 있는지 구하는 프로그램을 작성하세요.
만약 5! = 5 X 4 X 3 X 2 X 1 = 120 으로 일의자리부터 연속적된 ‘0’의 개수는 1입니다.
만약 12! = 479001600으로 일의자리부터 연속적된 ‘0’의 개수는 2입니다.

첫 줄에 자연수 N(10<=N<=1,000)이 입력된다.

일의 자리부터 연속된 0의 개수를 출력합니다.

입력 input.txt
12

출력 
2 
*/


int main(int argc, char** argv) {

	// cnt1 은 2의 개수를 센다. cnt2는 5의 개수를 센다.  
	int num = 0, i=0, j=0, temp = 0, cnt1=0, cnt2=0;
	 
	//freopen("input.txt", "rt", stdin);	
	
	scanf("%d", &num);

	for(i=2; i<=num; i++){
		temp = i; // 소인수 분해 할 수 temp 에 저장 
		
		j=2; // 인수
		
		while(1){
			
			if(temp % j == 0){ // j로 나누어 떨어진다면,  
				if(j==2) cnt1++; 
				else if (j==5) cnt2++;
				temp = temp/j;
			}else{
				j++; // 기존 인수에 +1 해서 다시 나눠본다.  
			}
			
			if(temp == 1) break;
		} 
	}
	
	if(cnt1 < cnt2){
		printf("%d", cnt1);
	}else{
		printf("%d", cnt2);
	}
	 
	return 0;
}

/* 

감이 오지 않았던 문제. 

10진수에 대한 이해가 필요한데, 소인수분해를 하면 문제를 풀 수 있다.  

5! = 5 X 4 X 3 X 2 X 1 = 120

여기서 곱하는 숫자들을(1, 2, 3, 4, 5) 전부 소인수 본 해하는 것이 중요하다. 

즉, X 10이 몇번 일어나는지가 중요하다.  ( == 2와 5가 몇개인지가 중요하다. ) 

예를 들어, 소인수분해를 한 결과가 2의 10승, 5의 6승이라면, 10의 6승이 곱해진 수가 된다.  


*/
