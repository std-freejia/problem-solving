#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 63. ������� (����ġ ����׷���) adjacency_matrix

int map[51][51];

int main(void){

	freopen("input.txt", "rt", stdin);
	
	int n, m, i, j = 0;
	int a, b, c = 0; // ������, ������, ����ġ  
	
	scanf("%d %d", &n, &m); // ��������, ��������  
	
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = c; // ����ġ ����׷���  
		
		//������ �׷����� ���, 
		/*
		map[a][b] = 1;
		map[b][a] = 1;
		*/ 
	}
	
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	
	return 0;
} 


