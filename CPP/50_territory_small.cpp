#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 50. 영지(territory) 선택 : (small)

/*
왕은 현수에게 현수가 다스릴 수 있는 영지를 하사하기로 했다. 전체 땅은 사각형으로 표시된다. 
그 사각형의 땅 중에서 세종대왕이 현수가 다스릴 수 있는 땅의 크기(세로의 길이와 가로의 길이)를 정해주면 전체 땅 중에서 그 크기의 땅의 위치를 현수가 정하면 되는 것이다.
전체 땅은 사각형의 모양의 격자로 되어 있으며, 그 사각형 땅 안에는 많은 오렌지 나무가 심겨져 있다. 
현수는 오렌지를 무척 좋아하여 오렌지 나무가 가장 많이 포함되는 지역을 선택하고 싶어 한다. 
현수가 얻을 수 있는 영지의 오렌지 나무 최대 개수를 출력하는 프로그램을 작성하세요. 
다음과 같은 땅의 정보가 주어지고, 현수가 하사받을 크기가, 가로 2, 세로 3의 크기이면 가장 많은 오렌지 나무가 있는 영지는 총 오렌지 나무의 개수가 16인 3행 4열부터 시
작하는 구역이다.

▣ 입력설명
첫 줄에 H(세로길이)와 W(가로길이)가 입력된다. (5<=H, W<=50) 그 다음 H줄에 걸쳐 각 사
각형 지역에 오렌지의 나무 개수(1~9개) 정보가 주어진다.
그 다음 영지의 크기인 세로길이(1~H)와 가로길이(1~W)가 차례로 입력된다.

▣ 출력설명
첫 줄에 현수가 얻을 수 있는 오렌지 나무의 최대 개수를 출력한다.

*/

int given_height, given_width;

int Sum_of_tree(int start_i, int start_j, vector<vector<int> > &map);

int main(int argc, char** argv){
	
	int total_height = 0, total_width = 0;
	int i = 0, j = 0, temp_sum = 0, max_tree = 0;

	//freopen("input.txt", "rt", stdin);

	scanf("%d %d", &total_height, &total_width); // 입력받기 시작  
	
	vector<vector<int> > map(total_height, vector<int>(total_width, 0)); 
	
	for(i=0; i< total_height; i++){ // 세로  
		for(j=0; j< total_width; j++){ // 가로  
			scanf("%d", &map[i][j]); 
		}
	}
	scanf("%d %d", &given_height, &given_width); // 입력받기 시작  

	// 입력받기 끝 
		
	// 탐색시작  
	for(i=0; i<= total_height - given_height; i++){ // 세로  
		
		for(j=0; j<= total_width - given_width; j++){ // 가로  
						
			temp_sum = Sum_of_tree(i, j, map);
			
			if(max_tree < temp_sum){
				max_tree = temp_sum;
			}
		
		}
	}
	
	printf("%d", max_tree);
	
	return 0;
}

int Sum_of_tree(int start_i, int start_j, vector<vector<int> > &map){
	
	int sum = 0, i = 0, j = 0;
	
	for(i=start_i; i<start_i+given_height; i++){
		
		for(j=start_j; j<start_j+given_width; j++){
			
			sum += map[i][j];
		}		
	}
	
	return sum;
}


