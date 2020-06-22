#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;

// 52. Ugly Numbers (투포인트 알고리즘 응용) 

/*
어떤 수를 소인수분해 했을 때 그 소인수가 2 또는 3 또는 5로만 이루어진 수를 Ugly Number라고 부릅니다. 
Ugly Number를 차례대로 적어보면 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......입니다. 
숫자 1은 Ugly Number의 첫 번째 수로 합니다. 
자연수 N이 주어지면 Ugly Number를 차례로 적을 때 N번째 Ugly Number를 구하는 프로그램을 작성하세요.

▣ 입력설명
첫 줄에 자연수 N(3<=N<=1500)이 주어집니다.

▣ 출력설명
첫 줄에 N번째 Ugly Number를 출력하세요.

*/


int a[1501];

int main(int argc, char** argv){
	
	//freopen("input.txt", "rt", stdin);

	int num, i = 0;
	int min = 2147000000;
	int p2, p3, p5; // 인덱스를 가리키는 포인트 변수
	
	scanf("%d", &num);
	
	a[1] = 1;
	p2=p3=p5=1; // 1로 시작  
	
	for(i=2; i<=num; i++){
		
		// p2, p3, p5 중에서 최소값 고른다  
		if(a[p2] * 2 < a[p3] * 3) min = a[p2] * 2;
		else min = a[p3] * 3;
		if(a[p5] * 5 < min) min = a[p5] * 5;
		
		// 최소값이 2개인 경우를 처리한다. (2개이면 2개의 포인트 변수 모두 ++) 
		if(a[p2] * 2 == min) p2++;
		if(a[p3] * 3 == min) p3++;  
		if(a[p5] * 5 == min) p5++; 
		
		a[i] = min;
	}
	
	printf("%d", a[num]);
	
	return 0;
} 
