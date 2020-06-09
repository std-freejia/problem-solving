#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

// 43. 뮤직비디오  

int a[1001], n;

int Count(int size){
	
	// cnt : dvd 개수 (dvd는 1개 이상이니까 1개로 시작) 
	// i : 이미 cnt에서 센 1장의 dvd에 1개의 곡을 포함하고 있음.  
	int i=0, cnt = 1, sum=0;
	
	for(i=1; i<=n; i++){
		if(sum + a[i] > size){ //  i 까지 하면 size초과니까,  a[i]는 새 dvd 에 넣기.  
			cnt++;
			sum = a[i];
		}else{
			sum += a[i];
		}
	}
	
	return cnt;	
}

int main(int argc, char** argv){

	// m: dvd 개수  
	int m=0, i=0, lt=1, rt=0, mid=0, res=0; 
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &n, &m);
	
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		rt = rt + a[i];
	}
	
	while(lt <= rt){
		
		mid = (lt+rt) / 2;
		
		if(Count(mid) <= m ){ // 답으로 가능  
			res = mid;
			rt = mid-1;
		}else{
			lt = mid + 1;  // 더 큰 범위로 생각해본다.  
		}
	}
	
	printf("%d", res);
	
	return 0;
}


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
