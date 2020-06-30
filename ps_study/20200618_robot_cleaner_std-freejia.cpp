#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
�κ� û�ұ� ���� 14503
by std-freejia
*/

int Search(void); 
int Back_check(void);
 
int cnt_clean, direction, r, c, cnt_check; 
int map[51][51];
 
int main(int argc, char** argv){

	int i, j = 0;
	int height, width = 0;
	int stop_flag = 1;

	// �Է� �ޱ� ����
	scanf("%d %d %d %d %d", &height, &width, &r, &c, &direction);   

	for(i=0; i<height; i++){
		
		for(j=0; j<width; j++){
			scanf("%d", &map[i][j]);
		}
		
	}// �Է� �ޱ� ��  
		
	while(stop_flag){
		stop_flag = Search();
	}
	
	printf("%d", cnt_clean);
	
	return 0;
}

int Back_check(void){ // ������ �����ϸ� 1, �Ұ��ϸ� 0 ����  

	int direc_flag = (direction + 2) % 4;
	
	if(0 == direc_flag){ // �������� ���� ���� ���� Ȯ��  
	
		if(1 != map[r-1][c]){
			r = r-1;
			return 1;
		}else{
			return 0;
		}
		
	}else if(1 == direc_flag){ // �������� ���� ���� ���� Ȯ��  
		
		if(1 != map[r][c+1]){
			c = c+1;
			return 1;
		}else{
			return 0;
		}
	}else if(2 == direc_flag){ //  �������� ���� ����? 
		
		if(1 != map[r+1][c]){
			r = r+1;
			return 1;
		}else{
			return 0;
		}
	}else { // �������� ���� ����?  
		
		if(1 != map[r][c-1]){
			c = c-1;
			return 1;
		}else{
			return 0;
		}	
	}
}

int Search(void){

	int temp_d = direction + 3; // ���� ������ ����. 
		
	if(map[r][c] == 0){ // ���� ��ġ�� û�� 

		cnt_clean++;
		map[r][c] = 2;
	}
	
	if(0 == temp_d % 4 ) { // ����  
	
		direction+=3; // ȸ���Ѵ�
	
		if(0 == map[r-1][c]) { // û�� ���� �����̶��  
			r = r-1; // �������� �����Ѵ�
			cnt_clean++; 
			map[r][c] = 2; // û���ߴٴ� ǥ�� 2   
			cnt_check = 0; 
			
		}else{ // û�Ұ� �Ǿ� �ְų� ���̴�. 
			cnt_check++; // ������ Ȯ�������� ����.  
		}	
		
	}else if(1 == temp_d % 4){ // ����  
	
		direction+=3; // ȸ���Ѵ�
		
		if(0 == map[r][c+1]) { // û�� ���� �����̶��  
			c = c + 1; // �������� �����Ѵ�
			cnt_clean++; 
			map[r][c] = 2; 
			cnt_check = 0; 
			
		}else{ 
			cnt_check++;
		}	
		
	}else if(2 == temp_d % 4){ // ����   
		
		direction+=3; // ȸ���Ѵ�	
		
		if(0 == map[r+1][c]) { // û�� ���� �����̶��  
			r = r+1; // �������� ����
			cnt_clean++; 
			map[r][c] = 2; 
			cnt_check = 0; 
		}else{ 
			cnt_check++;
		}	
	}else{ //����  
	
		direction+=3; // ȸ���Ѵ�	
			
		if(0 == map[r][c-1]) { 
			c = c-1; // �������� �����Ѵ�
			cnt_clean++; 
			map[r][c] = 2; // û���ߴٴ� ǥ��
			cnt_check = 0; 
			
		}else{ 
			cnt_check++;
		}	
	}

	if(cnt_check == 4){  // 4���� ��� Ȯ�� ��, ���� ���� ���� Ȯ��  
		
		if(Back_check()){ // ���� ����  
			cnt_check = 0;
			return 1; 
			
		}else{ // ���� �Ұ�  
			return 0; // �۵� ����  
		}
		
	}else{ // �ٸ� ������ Ȯ���غ���  
		return 1;
	}
}

