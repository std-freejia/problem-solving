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

// 내가 짠 코드. 
 
int main(int argc, char** argv){
		
	int job_size, cache_size, newjob, i, j, m, flag = 0;
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &cache_size, &job_size);

	vector<int> cache(cache_size);

	for(i=0; i<job_size; i++){ // cache에 넣는다. 
		
		scanf("%d", &newjob);

		flag = 0;
		
		for(j=0; j<cache_size; j++){ 
			
			if(newjob == cache[j]){ //  cache hit 
				flag = 1;
				break;	
			}
		} 
		
		if(flag){ // cache hit

			for(m=j; m>=1; m--){ //하나씩 오른쪽으로 민다. 
				cache[m] = cache[m-1];
			}

		}else{ // cache miss

			for(m=cache_size-1; m>=1; m--){ //하나씩 오른쪽으로 민다. 
				cache[m] = cache[m-1];
			}
			
		}
		
		cache[0] = newjob;
		
	}
	
	for(i=0; i<cache_size; i++){ // 출력 
	
		printf("%d ", cache[i]);
	} 
	 
	return 0;
}

/*

캐시 hit, miss 를 처리하는 부분이 선생님과 달라서 그동안 틀렸었다. 
 
48 라인부터 60라인 까지 내가 이전에 짰던 코드는 다음과 같다. 

		if(flag){ // cache hit
			if(j == 0) break;
			
			for(m=j-1; m>=0; m--){ //하나씩 오른쪽으로 민다. 
				cache[m+1] = cache[m];
			}

		}else{ // cache miss
			
			for(m=cache_size-1; m>=0; m--){ //하나씩 오른쪽으로 민다. 
				cache[m+1] = cache[m];
			}
			
		} 

숫자를 하나씩 미는 for문의 인덱스가 틀렸었다.  

*/ 

