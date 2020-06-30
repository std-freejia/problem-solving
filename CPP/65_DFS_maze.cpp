#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 65. �̷�Ž�� DFS
 
/*
64 ���� ������ DFS����. 

���� Ž�� dx, dy  

*/

int map[8][8], ch[8][8];  // 7*7 map ũ�����.  
int dx[4] = {1, -1, 0, 0};  
int dy[4] = {0, 0, 1, -1}; // 47�� ���츮 �������� ���� �ٲ۰� Ȱ��. �������� 
int cnt;

void DFS(int x, int y){
	
	int i, xx, yy;  // 4���� ������ ������ ���� ����   
	
	if(x == 7 && y == 7) { // ������ ���� cnt++ 
		cnt++;
		return;
	}else{
		
		for(i=0; i<4; i++){ 
			xx = x+dx[i]; // ������ǥ ���ؿ���, 4������ ������.  
			yy = y+dy[i];
			
			if(xx<1 || xx>7 || yy<1 || yy>7) continue; // map�� ����� ������.
			if(map[xx][yy] == 0 && ch[xx][yy] == 0) { // 0�ε�, �Ȱ��� ���̶��,  
				ch[xx][yy] = 1; // ������.  
				DFS(xx, yy);
				ch[xx][yy] = 0; // ��������.  
			} 
			
		}
	}
	
}

int main(void){
	
	//freopen("input.txt", "rt", stdin);
	int i, j = 0;
	
	// map �ޱ� 
	for(i=1; i<=7; i++){
		for(j=1; j<=7; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	ch[1][1] = 1; // �������� �����ϱ� 1�� ���� (���� ���� 1�� ǥ��) 
	DFS(1, 1);	
	
	printf("%d", cnt);
	
	return 0;
} 
