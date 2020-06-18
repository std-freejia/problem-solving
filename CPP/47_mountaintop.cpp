#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 47. 봉우리  mountaintop

/*
지도 정보가 N*N 격자판에 주어집니다. 
각 격자에는 그 지역의 높이가 쓰여있습니다. 각 격자판의 숫자 중 자신의 상하좌우 숫자보다 큰 숫자는 봉우리 지역입니다. 봉우리 지역이 몇 개
있는 지 알아내는 프로그램을 작성하세요.
격자의 가장자리는 0으로 초기화 되었다고 가정한다.

▣ 입력설명
첫 줄에 자연수 N이 주어진다.(1<=N<=50)
두 번째 줄부터 N줄에 걸쳐 각 줄에 N개의 자연수가 주어진다. 각 자연수는 100을 넘지 않는다.

▣ 출력설명
봉우리의 개수를 출력하세요.

*/

bool Check_top(vector<vector<int> > &map, int i, int j);

int main(int argc, char** argv){
	
	int map_size = 0, i = 0, j = 0, top_cnt = 0, target = 0;

	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &map_size); // 입력 받기 시작  
	
	vector<vector<int> > map(map_size+2, vector<int>(map_size+2, 0)); // 2d vector  
	
	for(i=1; i<=map_size; i++){ // map 초기화  
		
		for(j=1; j<=map_size; j++){
			scanf("%d", &map[i][j]);
		}
	} // 입력 받기 끝. 
	
	// 봉우리 탐색 시작 
	for(i=1; i<=map_size; i++){  
		
		for(j=1; j<=map_size; j++){

			if(Check_top(map, i, j)){
				top_cnt++;
			}
			
		}
		
	}  
	
	printf("\n%d", top_cnt);

	return 0;
}


bool Check_top(vector<vector<int> > &map, int i, int j){
	
	int target = map[i][j];
	bool flag = true; 
		
	if(target <= map[i-1][j]){
		flag = false;
	}
	
	if(target <= map[i+1][j]){
		flag = false;
	}
	
	if(target <= map[i][j-1]){
		flag = false;
	}
	
	if(target <= map[i][j+1]){
		flag = false;
	}
	
	return flag;
}

