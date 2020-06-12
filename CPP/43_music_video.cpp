#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

// 43. 뮤직비디오   

// 곡  
int a[1001],  n;

int Count(int size){ // n
	int i, cnt=1, sum = 0; // 반복문 변수, dvd 개수(최소 1개니까), 분의 합 
	
	for(i=1; i<=n; i++){ // 모든 곡 순회  
		if(sum + a[i] > size){
			cnt++;
			sum = a[i]; // 새 dvd 에 들어감.  dvd의 용량보다는 노래가 작아야함. 
		}else{
			sum += a[i];
		}
	} 
	
	return cnt;
}
 
int main(int argc, char** argv){
	   
	//freopen("input.txt", "rt", stdin); 
	// max_value : 곡들 중에 최대 분.  
	int m, i, lt=1, rt=0, mid, res, max_value = -2147000000;
	
	scanf("%d %d", &n, &m);
	
	for(i=1; i<=n; i++){ // 인덱스 1 부터 이용  
		scanf("%d", &a[i]);
		rt = rt + a[i]; // 곡들이 전체 몇 분인지 저장  
		if(a[i]> max_value) max_value = a[i]; 
	}
	
	// 이분 검색
	while(lt <= rt){
		mid = (lt + rt)/2;  // dvd 1개의 최소 용량 
		
		//mid 값이 가능한 용량인지 확인 
		// mid 값은 모든 노래의 각 용량보다는 커야 한다.  
		if(mid >= max_value && Count(mid) <= m){ // 답이 된다  
			res = mid;
			rt = mid-1;
		}else{
			lt = mid+1;
		}
	} 
	
	printf("%d", res);
	
	return 0;
}

