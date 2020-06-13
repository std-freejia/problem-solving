#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 44. 마구간 정하기  distance_of_stable

int Count(int mid, vector<int> stable, int cnt_stable){
	
	// 말 하나는 첫 마구간에 두고 시작한다.  
	int i = 0, cnt = 1, pos = stable[1];
		
	for(i=2; i<= cnt_stable; i++){
		
		if(mid <= stable[i] - pos){ // 두 마구간의 간격이 mid 거리 이상인 경우.  
			cnt++;
			pos = stable[i];
		}
	}
	
	return cnt;
}

int main(int argc, char** argv){
	
	// 마구간 개수, 말의 개수, 반복문 변수  
	int cnt_stable = 0, horse = 0, i = 0;
	int lp = 1, rp = 0, mid = 0, res = 0;
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &cnt_stable, &horse);
	
	vector<int> stable(cnt_stable + 1); // 인덱스 1 부터 사용  
	
	for(i=1; i <= cnt_stable; i++){ // 인덱스 1 부터 사용  
		scanf("%d", &stable[i]);
	}

	// 정렬 
	sort(stable.begin(), stable.end());
	 
	rp = stable[cnt_stable];
	
	while(lp <= rp){ // 이분탐색  
		
		mid = (lp + rp)/2;
		
		if(Count(mid, stable, cnt_stable) >= horse){
			res = mid;
			lp = mid + 1; // 더 멀리 떨어뜨려본다.  
		}else{
			rp = mid - 1;
		}
	}
	
	printf("%d", res);
	
	return 0;
}


/* 이 문제도 결정 알고리즘으로 푼다.  

N개의 마구간이 1차원 수직선상에 있습니다. 
각 마구간은 x1, x2, x3, ......, xN의 좌표를 가
지며, 마구간간에 좌표가 중복되는 일은 없습니다.
현수는 C마리의 말을 가지고 있는데, 이 말들은 서로 가까이 있는 것을 좋아하지 않습니다.
각 마구간에는 한 마리의 말만 넣을 수 있고, 가장 가까운 두 말의 거리가 최대가 되게 말을 마구간에 배치하고 싶습니다.
C마리의 말을 N개의 마구간에 배치했을 때 가장 가까운 두 말의 거리가 최대가 되는 그 최대값을 출력하는 프로그램을 작성하세요.

▣ 입력설명
첫 줄에 자연수 N(3<=N<=200,000)과 C(2<=C<=N)이 공백을 사이에 두고 주어집니다.
둘째 줄부터 N개의 줄에 걸쳐 마구간의 좌표 xi(0<=xi<=1,000,000,000)가 한 줄에 하나씩 주어집니다.

▣ 출력설명
첫 줄에 가장 가까운 두 말의 최대 거리를 출력하세요.

*/
