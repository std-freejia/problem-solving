#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

// 43. 뮤직비디오   
/*
DVD에는 총 N개의 곡이 들어가는데, DVD에 녹화할 때에는 라이브에서의 순서가 그대로 유지 되어야 한다. 
즉, 1번 노래와 5번 노래를 같은 DVD에 녹화하기 위해서는 1번과 5번 사이의 모든 노래도 같은 DVD에 녹화해야한다.
지니레코드 입장에서는 이 DVD가 팔릴 것인지 확신할 수 없기 때문에 이 사업에 낭비되는 DVD를 가급적 줄이려고 한다. 
고민 끝에 지니레코드는 M개의 DVD에 모든 동영상을 녹화하기 로 하였다. 
이 때 DVD의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 
그리고 M개의 DVD는 모두 같은 크기여야 제조원가가 적게 들기 때문에 꼭 같은 크기로 해야 한다.


▣ 입력설명
첫째 줄에 자연수 N(1≤N≤1,000), M(1≤M≤N)이 주어진다. 

다음 줄에는 조영필이 라이브에서 부른 순서대로 부른 곡의 길이가 분 단위로(자연수) 주어진다. 
부른 곡의 길이는 10,000분을 넘지 않는다고 가정하자.

▣ 출력설명
첫 번째 줄부터 DVD의 최소 용량 크기를 출력하세요.


결정 알고리즘 
답을 미리 정해놓고 맞는지를 확인하는 루틴.  
맞는지 찾아가는 과정을 이분탐색으로 구현한다. 어떤 범위에 속하는지 확인하면서 한다.  

*/

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

