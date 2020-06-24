#include <stdio.h>
#include <algorithm>
#include <vector> 
using namespace std;

// 60. 합이 같은 부분집합 (DFS 아마존인터뷰) 


// 선생님 코드 

/* 선생님 코드 설계  
 
하나의 부분집합을 만든 순간, 나머지 애들이 또하나의 부분집합이 된다. 
일단 모든 요소의 합을 total 변수에 저장한다. 
하나의 부분집합을 만들고 합을 구하고, 그 합을 total에서 뺀다.  그 값이 같으면 "YES"  

*/

int n, a[11], total = 0; 
bool flag_end = false;

void DFS(int length, int sum){

	if(length == n+1){
		// 합을 비교해본다. 
		if((total-sum) == sum){ // 부분집합의 합과, 나머지집합의 합을 비교  
			flag_end = true;
		}
		return; 
	
	}else{
	
		DFS(length+1, sum + a[length]); // 현재 인덱스 원소를 집합원소로 사용함. 
		DFS(length+1, sum);  // 현재 인덱스 원소를 집합원소로 사용 안함. (누적 안하고 지나감) 

	}
		
}

int main(void){
	
	//freopen("input.txt", "rt", stdin);
	
	int i = 0;
	
	scanf("%d", &n); // 요소의 개수 
	
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		total += a[i]; // 모든 요소의 합  
	} 
	
	DFS(1, 0); // 첫번째 요소부터 이용한다. 만들 집합에서 요소의 합 누적시킴. 
	
	if(flag_end){
		printf("YES");
	} else{
		printf("NO");
	}
	return 0;
} 


