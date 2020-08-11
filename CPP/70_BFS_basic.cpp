#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 70. �׷��� �ִܰŸ� (BFS) 

int vertex, edge; // ���� ��, ���� ��  
int dis[21]; // 1�� �������� n�� ���������� �ּ� ���� ��  
int check[21]; // ���� �湮 ���� 


int main(void){

	//freopen("input.txt", "rt", stdin);
	int start, end = 0;
	int i, num = 0;
	vector<int> map[21];
	queue<int> Q;
	
	scanf("%d %d", &vertex, &edge);
	
	for(i=1; i <= edge; i++){
		scanf("%d %d", &start, &end);
		map[start].push_back(end); // ���� ��������Ʈ 
	}
	
	Q.push(1); // 1�� �湮�ߴ�.  
	check[1] = 1;
	
	while(!Q.empty()){
	
		num = Q.front(); // ������ ������ ���� ��ȯ 
		Q.pop(); 		 // ���ܿ��� front �����͸� ����  
		
		for(i=0; i<map[num].size(); i++){ // num�� ���� ��� ��ȸ  
			
			int adj_node = map[num][i]; // ���� ���  
			
			if(check[adj_node] == 0){ // ���� �湮 ���ߴٸ�, 
			 
				check[adj_node] = 1;  // �湮�ߴٰ� üũ
				Q.push(adj_node);  	 // ť�� �ֱ� 
				
				dis[adj_node] = dis[num] + 1; // ���� ��忡�� ���� �ϳ� ��.  
			} 
		} 
	}
	
	// 2�� �������� n�� ���������� �ּ� �̵� ���� �� ���  
	for(i=2; i <= vertex; i++){
		printf("%d : %d\n", i, dis[i]);
	}
	
	return 0;
}


