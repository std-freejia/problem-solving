#include <stdio.h>

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
답을 미리 정해놓고 맞는지를 확인하는 방식. 
해당 범위에서 특정 답(임의로 중간값)이 답으로 타당한지 찾아가는 과정을 이분탐색으로 구현한다. 
*/


int song[1001], cnt_song;
	
int Count(int size){
	
	int i = 0, cnt_dvd = 1, sum = 0;
	
	for(i=1; i<=cnt_song; i++){ // 모든 곡 순회  
		
		if(sum + song[i] > size){
			cnt_dvd++;
			sum = song[i];
		}else{
			sum += song[i];
		}
	}
	
	return cnt_dvd;
	
}


int main(int argc, char** argv){
	
	int i = 0, cnt_limit_dvd = 0;
	int lp = 1, rp = 0, mid = 0, res = 0;
	int max_value = -2147000000;
		
	//freopen("input.txt", "rt", stdin);

	scanf("%d %d", &cnt_song, &cnt_limit_dvd);
	
	// 곡들이 총 몇분인지 저장  
	for(i=1; i<= cnt_song; i++){ // 인덱스 1 부터 사용
		scanf("%d", &song[i]);
		rp = rp + song[i];
		
		if(song[i] > max_value) max_value = song[i]; // 제일 긴 곡 저장  
	}
	
	// dvd 한 개의 용량이 '제일 긴 곡'의 용량보다는 같거나 커야 한다.  
	
	// 가능한 dvd 의 시간 범위 : 1분 부터 rt에 저장된 분  
	
	//이분검색  
	while(lp <= rp){
		
		mid = (lp + rp) / 2; // dvd 1개의 최소 용량 
		
		if(mid >= max_value && Count(mid) <= cnt_limit_dvd){ // mid 가 답이 된다.  
			res = mid;
			rp = mid - 1;  
		} else {
			lp = mid + 1; 
		}
	}
	
	printf("%d", res);

	return 0;

}
