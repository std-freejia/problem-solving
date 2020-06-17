#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 46. 멀티태스킹 (카카오 먹방문제 변형) multitasking 

int main(int argc, char** argv){
	
	// 총 개수, 정전 나는 시각, 포지션, 총 작업 시간  
	int n, k, i, p=0, time=0, total = 0;
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &n); // 입력 받기 시작  
	
	vector<int> job(n+1); //인덱스 1부터 이용. 
	
	for(i=1; i<=n; i++){
		scanf("%d", &job[i]);
		total += job[i]; // 총 작업량 합을 세둔다.  
	}
	
	scanf("%d", &k); // 정전 나는 시각.  // 입력 받기 끝. 
	
	if(k >= total){ // 작업들이 전부 끝나고 정전 발생. 
		printf("-1");
		return 0; 
	}
	
	while(1){
		p++; 
		
		if(p>n){
			p = 1;
		}
		
		if(job[p] != 0){ // 작업 한다.  
			job[p]--;
			time++; // 작업도 하고 시간도 지난다. 
			
			if(time == k){ // 정전 발생 시, 탈출. 
				break; 
			} 
			
		}else{
			continue; // 시간이 지난게 아니다.   
		}
	}
	
	while(1){
		
		p++;
		if(p>n){
			p = 1;
		}	 
		
		if(job[p] != 0){
			break;
		} 
	} 
	
	printf("%d", p);
	
	return 0;
}


/*

카카오 기술블로그 '먹방'문제를 변형한 것. 45번 공주구하기 문제와 비슷한 시뮬레이션 문제. 

*/

