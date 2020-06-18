#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 47. ���츮  mountaintop

/*
���� ������ N*N �����ǿ� �־����ϴ�. 
�� ���ڿ��� �� ������ ���̰� �����ֽ��ϴ�. �� �������� ���� �� �ڽ��� �����¿� ���ں��� ū ���ڴ� ���츮 �����Դϴ�. ���츮 ������ �� ��
�ִ� �� �˾Ƴ��� ���α׷��� �ۼ��ϼ���.
������ �����ڸ��� 0���� �ʱ�ȭ �Ǿ��ٰ� �����Ѵ�.

�� �Է¼���
ù �ٿ� �ڿ��� N�� �־�����.(1<=N<=50)
�� ��° �ٺ��� N�ٿ� ���� �� �ٿ� N���� �ڿ����� �־�����. �� �ڿ����� 100�� ���� �ʴ´�.

�� ��¼���
���츮�� ������ ����ϼ���.

*/

bool Check_top(vector<vector<int> > &map, int i, int j);

int main(int argc, char** argv){
	
	int map_size = 0, i = 0, j = 0, top_cnt = 0, target = 0;

	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &map_size); // �Է� �ޱ� ����  
	
	vector<vector<int> > map(map_size+2, vector<int>(map_size+2, 0)); // 2d vector  
	
	for(i=1; i<=map_size; i++){ // map �ʱ�ȭ  
		
		for(j=1; j<=map_size; j++){
			scanf("%d", &map[i][j]);
		}
	} // �Է� �ޱ� ��. 
	
	// ���츮 Ž�� ���� 
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

