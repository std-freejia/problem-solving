#include <stdio.h>
#include <stdlib.h> // abs()
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 48. 각 행의 평균과 가장 가까운 값  nearby_average  

/*
9 × 9 격자판에 쓰여진 81개의 자연수가 주어질 때, 각 행의 평균을 구하고,
그 평균과 가장 가까운 값을 출력하는 프로그램을 작성하세요. 
평균은 소수점 첫 째 자리에서 반올림합니다. 평균과 가까운 값이 두 개이면 그 중 큰 값을 출력하세요.

▣ 입력설명
첫 째 줄부터 아홉 번째 줄까지 한 줄에 아홉 개씩 자연수가 주어진다. 
주어지는 자연수는 100보다 작다.

▣ 출력설명
첫째 줄에 첫 번째 줄부터 각 줄에 각행의 평균과 그 행에서 평균과 가장 가까운 수를 출력한다.
*/
int Get_average(vector<vector<int> > &map, int i);


int main(int argc, char** argv){
	
	int i = 0, j = 0, avg = 0, diff = 0, temp_diff_near = 0, temp_value = 0;

	//freopen("input.txt", "rt", stdin);
	
	vector<vector<int> > map(9, vector<int>(9, 0)); // 2d vector  [가로9][세로9]
	
	for(i=0; i<9; i++){ // map 초기화  
		
		for(j=0; j<9; j++){
			scanf("%d", &map[i][j]);
		}
	} // 입력 받기 끝. 
	
	// 평균 출력, 평균과 가장 가까운 값 출력  
	for(i=0; i<9; i++){  
		
		avg = Get_average(map, i);
		temp_diff_near = avg;
		temp_value = 0;
		
		printf("%d ", avg);
		
		for(j=0; j<9; j++){
					
			diff = map[i][j] - avg; // 숫자와 평균의 차이  
			
			if(abs(diff) < temp_diff_near){ // 차이가 더 작다면 갱신  
				temp_diff_near = abs(diff); // 차이 저장   
				temp_value = map[i][j]; // 숫자 저장  
				
				if(map[i][j] > temp_value){
					temp_value = map[i][j];
				}
			}
		}
		
		printf("%d\n", temp_value);
		
	}  

	return 0;
}


int Get_average(vector<vector<int> > &map, int line){
	
	int age = 0, j=0;
	double sum = 0;

	for(j=0; j<9; j++){
					
		sum += map[line][j];
			
	}  
	 
	return round(sum/9);  // 반올림 round()  #include <cmath>
	
}	

