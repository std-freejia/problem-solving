#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


// 67. �ּҺ�� (DFS: �������) 

// ����ġ ����׷��� : ���� �ڽ��� ����Ű�� �ִ� ������ ���ؼ��� ������ �ִٰ� ǥ��  
 
int vertex; // ���� ����  
int map[21][21]; // ���� 1<=vertex<=20 
int min_weight = 2147000000; // 1�� �������� vertex �������� ���� ����� �ּҺ��  
int check[21]; // ���� �湮 üũ  

void DFS(int v, int w){

	int i = 0;
	
	if(v == vertex){ // ������ ���� ���� 
		
		if(min_weight > w){ // �ּҺ���̶�� ����  
			min_weight = w;
		} 
		
	}else{
		
		//������ ������ �� ���� ����������. 
		for(i = 1; i <= vertex; i++){

			if(map[v][i] != 0 && check[i] == 0){ //�� ���� ������ �ִٸ�, 
				check[i] = 1; 
				DFS(i, w + map[v][i]);
				check[i] = 0;
			}
		}
	}
	
}

int main(void){

	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);

	int edge = 0;
	int i = 0, start = 0, end = 0, weight = 0;
	
	scanf("%d %d", &vertex, &edge);
	
	for(i = 1; i <= edge; i++){
		scanf("%d %d %d", &start, &end, &weight);
		map[start][end] = weight;
	}
	
	check[1] = 1;  // 1�� ���� �湮��  
	DFS(1, 0);
	
	printf("%d", min_weight);
	
	return 0;
}
