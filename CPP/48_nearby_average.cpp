#include <stdio.h>
#include <stdlib.h> // abs()
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 48. �� ���� ��հ� ���� ����� ��  nearby_average  

/*
9 �� 9 �����ǿ� ������ 81���� �ڿ����� �־��� ��, �� ���� ����� ���ϰ�,
�� ��հ� ���� ����� ���� ����ϴ� ���α׷��� �ۼ��ϼ���. 
����� �Ҽ��� ù ° �ڸ����� �ݿø��մϴ�. ��հ� ����� ���� �� ���̸� �� �� ū ���� ����ϼ���.

�� �Է¼���
ù ° �ٺ��� ��ȩ ��° �ٱ��� �� �ٿ� ��ȩ ���� �ڿ����� �־�����. 
�־����� �ڿ����� 100���� �۴�.

�� ��¼���
ù° �ٿ� ù ��° �ٺ��� �� �ٿ� ������ ��հ� �� �࿡�� ��հ� ���� ����� ���� ����Ѵ�.
*/
int Get_average(vector<vector<int> > &map, int i);


int main(int argc, char** argv){
	
	int i = 0, j = 0, avg = 0, diff = 0, temp_diff_near = 0, temp_value = 0;

	//freopen("input.txt", "rt", stdin);
	
	vector<vector<int> > map(9, vector<int>(9, 0)); // 2d vector  [����9][����9]
	
	for(i=0; i<9; i++){ // map �ʱ�ȭ  
		
		for(j=0; j<9; j++){
			scanf("%d", &map[i][j]);
		}
	} // �Է� �ޱ� ��. 
	
	// ��� ���, ��հ� ���� ����� �� ���  
	for(i=0; i<9; i++){  
		
		avg = Get_average(map, i);
		temp_diff_near = avg;
		temp_value = 0;
		
		printf("%d ", avg);
		
		for(j=0; j<9; j++){
					
			diff = map[i][j] - avg; // ���ڿ� ����� ����  
			
			if(abs(diff) < temp_diff_near){ // ���̰� �� �۴ٸ� ����  
				temp_diff_near = abs(diff); // ���� ����   
				temp_value = map[i][j]; // ���� ����  
				
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
	 
	return round(sum/9);  // �ݿø� round()  #include <cmath>
	
}	

