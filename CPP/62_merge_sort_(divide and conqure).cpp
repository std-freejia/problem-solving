#include <stdio.h>
using namespace std;

// 62. 병합정렬 (분할정복) 
 
/*

병합정렬의 시간복잡도는 ?   nlogN의 시간복잡도를 가진다.  


d(1,2) , d(3,4), d(5, 6)
2개 데이터 정렬 -> 2번 비교 
2개 데이터 정렬 -> 2번 비교 
...

d(1,4) d(5,8)
4개 데이터 정렬 - > 4번 비교 


d(1,8) 
8개 데이터 정렬 -> 8번 비교  

*/
 
int data[101], temp[101];
 
void divide(int left, int right){
	
	int mid = 0;
	int p1, p2, p3 = 0;  // 인덱스를 가리키는 포인트 변수. (위치변수) 
	int i = 0;
	
	if(left < right){
		
		mid = (left + right) / 2 ;
		
		divide(left, mid);
		divide(mid+1, right);
		
		// left~right 범위 내에서 정렬.
		p1 = left;
		p2 = mid+1;
		p3 = left; // 값을 넣을 포인트  
	
		while(p1 <= mid && p2 <= right){ // 병합  
			
			if(data[p1] < data[p2]) temp[p3++] = data[p1++];
			else temp[p3++] = data[p2++];
			
		}
		
		// 남은 것 처리 
		while(p1 <= mid) temp[p3++] = data[p1++]; 
		while(p2 <= right) temp[p3++] = data[p2++];
		
		// temp -> data 에 복사 
		for(i = left; i<=right; i++){
			data[i] = temp[i];
		} 
		
	}else{
		
		return;
	}
	
} 
 
int main(void){

	//freopen("input.txt", "rt", stdin);
	
	int n, i = 0;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){ // 인덱스는 1부터 사용.  
		scanf("%d", &data[i]);
	} // 입력받기 끝. 
	
	divide(1, n); // 정렬 재귀 함수  
	
	for(i=1; i<=n; i++){ // 정렬 결과 출력  
		printf("%d ", data[i]);
	}
	
	return 0;
} 


