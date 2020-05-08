#include <stdio.h> 

// 19.분노 유발자  make_you_anger
/*
강당의 좌석은 영화관처럼 계단형이 아니라 평평한 바닥에 의자만 배치하고 학생들이 앉습니
다. 
그런데 만약 앞자리에 앉은 키가 큰 학생이 앉으면 그 학생보다 앉은키가 작은 뒷자리 학
생은 스크린이 보이지 않습니다. 
한 줄에 앉은키 정보가 주어지면 
뒷사람 모두의 시야를 가려 영화 시청이 불가능하게 하는 분노유발자가 
그 줄에 몇 명이 있는지 구하는 프로그램을 작성하세요.


input.txt
10
56 46 55 76 65 53 52 53 55 50
*/
int student[101];

int main(int argc, char** argv) {

	int repeat = 0, i=0, max=-2147000000, count=0;	
	//freopen("input.txt", "rt", stdin);	
	 
	scanf("%d", &repeat);
		
	for(i=0; i<repeat; i++){ // 배열에 전부 저장  
		scanf("%d", &student[i]);		
	}
	
	max = student[repeat-1];
	
	for(i=repeat-1; i>0; i--){ 	// 배열 맨 뒤에서 부터 max가 갱신되는 횟수를 세면 된다. 
		if(student[i] < student[i-1] && max < student[i-1]){
			count++;
			max = student[i-1];
		}
	}
	
	printf("%d", count);
	
	return 0;
}


