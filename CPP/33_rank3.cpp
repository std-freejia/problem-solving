#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 33. 3등의 성적은? (정렬 응용) 

/*
N명의 수학성적이 주어지면 그 중 3등을 한 수학성적을 출력하는 프로그램을 작성하세요. 
만약 학생의 점수가 100점이 3명, 99점이 2명, 98점이 5명, 97점이 3명 이런식으로 점수가 분포되면 1등은 3명이며, 2등은 2명이며  
3등은 5명이 되어 98점이 3등을 한 점수가 됩니다.

첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에 N개의 수학성적 점수가 공백을 사이에 두고 입력됩니다. 수학성적 점수는 100점
만점 기준으로 입력됩니다.

*/

int main(int argc, char** argv) {

	int num=0, arr[101], i=0, j=0, idx=0, tmp=0, rank=0, res=0; 
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &num);
	
	// 숫자들 읽기 
	for(i=0; i<num; i++){
		scanf("%d", &arr[i]);
	} 

	for(i=0; i<num-1; i++){ // 선택정렬  
		
		idx = i; // i를 기준으로.  
		
		for(j = i+1; j<num; j++){
			
			if(arr[j] > arr[idx]) idx = j;  // 작은 값의 '인덱스'를 기억해둔다  
			
		}
		
		tmp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = tmp;
	}
	
	for(i=1; i<num; i++){ // 3등 찾기  
		
		if(arr[i-1] > arr[i]){
			rank++;
		}
				
		if(rank == 2){
			printf("%d", arr[i]);
			break; 
		}
	}
		 
	return 0;
	
}

/*

입력 
7
80 96 75 82 96 92 100

출력
92

*/

