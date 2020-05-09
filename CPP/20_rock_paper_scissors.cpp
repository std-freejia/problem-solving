#include <stdio.h> 

// 20. 가위 바위 보  rock_paper_scissors

/*
A와 B 두 사람이 가위바위보 게임을 합니다. 
총 N번의 게임을 하여 A가 이기면 A를 출력하고, B가 이기면 B를 출력합니다. 비길경우에 D를 출력합니다. 
가위, 바위, 보의 정보는 1:가위, 2:바위, 3:보로 정하겠습니다.

두 사람의 각 회의 가위, 바위, 보 정보가 주어지면 각 회를 누가 이겼는지 출력하는 프로그램
을 작성하세요

첫 번째 줄에 게임 횟수인 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에는 A가 낸 가위, 바위, 보 정보가 N개 주어집니다.
세 번째 줄에는 B가 낸 가위, 바위, 보 정보가 N개 주어집니다.

input.txt
5
2 3 3 1 3
1 1 2 2 3
*/
int a[101], b[101];

int main(int argc, char** argv) {

	int repeat = 0, i=0, count=0;	
	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &repeat);
		
	for(i=0; i<repeat; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<repeat; i++){
		scanf("%d", &b[i]);
	}
	
	for(i=0; i<repeat; i++){
		if(a[i] == b[i]){
			printf("D\n");
		}else if(b[i]-a[i] == 1 || a[i]-b[i] == 2){
			printf("B\n");
		}else{ // a[i]-b[i] == 1 || b[i]-a[i] == 2
			printf("A\n");
		}
	}
	
	return 0;
}

