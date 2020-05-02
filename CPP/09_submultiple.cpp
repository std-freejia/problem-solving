#include <stdio.h> 

// 9. 모두의 약수 (제한시간 1초) submultiple
/*
자연수 N이 입력되면 1부터 N까지의 각 숫자들의 약수의 개수를 출력하는 프로그램을 작성하
세요.
만약 N이 8이 입력된다면 1(1개), 2(2개), 3(2개), 4(3개), 5(2개), 6(4개), 7(2개), 8(4
개) 와 같이 각 숫자의 약수의 개수가 구해집니다. 
*/

int cnt[50001];

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	int input=0, i=0, j=0;
	
	scanf("%d", &input);
	
	for(i=1; i<=input; i++){
		
		// i의 배수들을 +1 처리해준다. 
		// i를 약수로 갖는 숫자들을 찾는 것이다.  
		for(j=i; j<=input; j=j+i){
			cnt[j]++;
		}
	}
	
	for(i=1; i<=input; i++){
		printf("%d ", cnt[i]);
	} 

	return 0;
}


