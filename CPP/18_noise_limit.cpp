#include <stdio.h> 

// 18. 층간소음  noise_limit
/*
한 세대의 측정치가 M값을 넘으면 세대호수와 작은 경보음이 관리실 모니터에서 울립니다. 
한 세대의 N초 동안의 실시간 측정치가 주어지면 최대 연속으로 경보음이 울린 시간을 구하세요. 

첫 줄에 자연수 N(10<=N<=100)과 M이 주어집니다.
두 번째 줄에 N개의 측정값(1000이하 자연수)이 초 순서대로 입력된다.

최대 연속 경보음이 울린 시간(초)를 출력하세요.
경보음이 없으면 -1를 출력합니다.

input.txt
10 90
23 17 120 34 112 136 123 23 25 113 
*/

int main(int argc, char** argv) {

	int repeat = 0, i=0, limit = 0, temp = 0, count = 0, max = -2147000000;	
	//freopen("input.txt", "rt", stdin);	

	scanf("%d %d", &repeat, &limit);
	
	for(i=0; i<repeat; i++){
		scanf("%d", &temp);
		
		if(temp>limit){
			count++;
			if(count>max){
				max=count;
			}
		}else{
			count = 0;
		}
	}
	
	if(max==0) printf("-1\n");
	else printf("%d\n", max);
	
	return 0;
}


