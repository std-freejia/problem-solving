#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 31. 탄화수소 질량  mass_of_hydrocarbon

/*

탄소(C)와 수소(H)로만 이루어진 화합물을 탄화수소라고 합니다.
탄소(C) 한 개의 질량은 12g, 수소(H) 한 개의 질량은 1g입니다.
에틸렌(C2H4)의 질량은 12*2+1*4=28g입니다.
메탄(CH4)의 질량은 12*1+1*4=16g입니다.
탄화수소식이 주어지면 해당 화합물의 질량을 구하는 프로그램을 작성하세요.

첫 줄에 탄화수소식이 주어집니다. 식의 형태는 CaHb 형태이며 (1<=a, b<=100)이다.
단 a 나 b 가 1이면 숫자가 식에 입력되지 않는다. 예) CH4

입력 input.txt
C2H4

출력 
28

*/


int main(int argc, char** argv) {
	
	// 배열 
	char arr[10];
	// c 의 개수, h 의 개수, pos : 숫자를 읽을 배열 인덱스   
	int c = 0, h = 0, i = 0, pos = 0;
	
	//freopen("input.txt", "rt", stdin);
	 
	scanf("%s", &arr);

	if(arr[1] == 'H') {
		c = 1;
		pos = 1; 
	}else{
		
		for(i=1; arr[i] != 'H'; i++){
			c = c*10 + (arr[i]-48);
		}
		pos = i;
	} 
	 
	if(arr[pos+1] == '\0') h=1;
	else{
		for(i=pos+1; arr[i] != '\0'; i++){
			h = h*10 + (arr[i]-48);
		}
	}
	 
	printf("%d", c*12+h); 
	 
	return 0;
	
}

