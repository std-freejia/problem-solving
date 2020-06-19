#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// 50. ����(territory) ���� : (small)

/*
���� �������� ������ �ٽ��� �� �ִ� ������ �ϻ��ϱ�� �ߴ�. ��ü ���� �簢������ ǥ�õȴ�. 
�� �簢���� �� �߿��� ��������� ������ �ٽ��� �� �ִ� ���� ũ��(������ ���̿� ������ ����)�� �����ָ� ��ü �� �߿��� �� ũ���� ���� ��ġ�� ������ ���ϸ� �Ǵ� ���̴�.
��ü ���� �簢���� ����� ���ڷ� �Ǿ� ������, �� �簢�� �� �ȿ��� ���� ������ ������ �ɰ��� �ִ�. 
������ �������� ��ô �����Ͽ� ������ ������ ���� ���� ���ԵǴ� ������ �����ϰ� �;� �Ѵ�. 
������ ���� �� �ִ� ������ ������ ���� �ִ� ������ ����ϴ� ���α׷��� �ۼ��ϼ���. 
������ ���� ���� ������ �־�����, ������ �ϻ���� ũ�Ⱑ, ���� 2, ���� 3�� ũ���̸� ���� ���� ������ ������ �ִ� ������ �� ������ ������ ������ 16�� 3�� 4������ ��
���ϴ� �����̴�.

�� �Է¼���
ù �ٿ� H(���α���)�� W(���α���)�� �Էµȴ�. (5<=H, W<=50) �� ���� H�ٿ� ���� �� ��
���� ������ �������� ���� ����(1~9��) ������ �־�����.
�� ���� ������ ũ���� ���α���(1~H)�� ���α���(1~W)�� ���ʷ� �Էµȴ�.

�� ��¼���
ù �ٿ� ������ ���� �� �ִ� ������ ������ �ִ� ������ ����Ѵ�.

*/

int given_height, given_width;

int Sum_of_tree(int start_i, int start_j, vector<vector<int> > &map);

int main(int argc, char** argv){
	
	int total_height = 0, total_width = 0;
	int i = 0, j = 0, temp_sum = 0, max_tree = 0;

	//freopen("input.txt", "rt", stdin);

	scanf("%d %d", &total_height, &total_width); // �Է¹ޱ� ����  
	
	vector<vector<int> > map(total_height, vector<int>(total_width, 0)); 
	
	for(i=0; i< total_height; i++){ // ����  
		for(j=0; j< total_width; j++){ // ����  
			scanf("%d", &map[i][j]); 
		}
	}
	scanf("%d %d", &given_height, &given_width); // �Է¹ޱ� ����  

	// �Է¹ޱ� �� 
		
	// Ž������  
	for(i=0; i<= total_height - given_height; i++){ // ����  
		
		for(j=0; j<= total_width - given_width; j++){ // ����  
						
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


