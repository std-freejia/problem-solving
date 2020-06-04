#include <stdio.h> 
#include <string.h>
#include <vector> 
#include <algorithm>
using namespace std;

// 37. Least Recently Used(카카오 캐시 문제 변형)

/*


* 입력설명 
첫 번째 줄에 캐시의 크기인 S(3<=S<=10)와 작업의 개수 N(5<=N<=1,000)이 입력된다.
두 번째 줄에 N개의 작업번호가 처리순으로 주어진다. 작업번호는 1 ~100 이다

* 출력설명
7 5 3 2 6
마지막 작업 후 캐시메모리의 상태를 가장 최근 사용된 작업부터 차례로 출력합니다

*/

// 선생님코드. 


int cache[11]; // cache 배열  캐시S의 크기제한 (3<=S<=10)

int main(int argc, char** argv){
	
	int cache_size, job_size, newjob, i, j, flag, m, p, pos=0;
		
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &cache_size, &job_size);
	 
	for(i=0; i<job_size; i++){ 
		
		scanf("%d", &newjob); // job을 순차적으로 읽는다.  
		
		pos = -1; // cache miss와 hit 구분 및 인덱스 저장  

		for(j=0; j<cache_size; j++){ 
			
			if(newjob == cache[j]){ //  cache hit 
				pos = j;
				break;	
			}
		} 
		
		if(pos == -1){ // cache miss 
			for(j = cache_size - 1; j >= 1; j--){ // 인덱스 맨 마지막부터 1까지 민다  
				cache[j] = cache[j-1];
			}

		}else{ // cache hit
			for(j = pos; j >= 1; j--){
				cache[j] = cache[j-1];
			}
		}
		
		cache[0] = newjob;
		

	}
	
	for(p=0; p<cache_size; p++){ // 출력 
		printf("%d ", cache[p]);
	} 
	//printf("\n");
		
	return 0;
}


