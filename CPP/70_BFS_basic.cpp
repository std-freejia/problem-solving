#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 70. 그래프 최단거리 (BFS) 

int vertex, edge; // 정점 수, 간선 수  
int dis[21]; // 1번 정점에서 n번 정점까지의 최소 간선 수  
int check[21]; // 정점 방문 여부 


int main(void){

	//freopen("input.txt", "rt", stdin);
	int start, end = 0;
	int i, num = 0;
	vector<int> map[21];
	queue<int> Q;
	
	scanf("%d %d", &vertex, &edge);
	
	for(i=1; i <= edge; i++){
		scanf("%d %d", &start, &end);
		map[start].push_back(end); // 방향 인접리스트 
	}
	
	Q.push(1); // 1을 방문했다.  
	check[1] = 1;
	
	while(!Q.empty()){
	
		num = Q.front(); // 전단의 데이터 값을 반환 
		Q.pop(); 		 // 전단에서 front 데이터를 제거  
		
		for(i=0; i<map[num].size(); i++){ // num과 인접 노드 순회  
			
			int adj_node = map[num][i]; // 인접 노드  
			
			if(check[adj_node] == 0){ // 아직 방문 안했다면, 
			 
				check[adj_node] = 1;  // 방문했다고 체크
				Q.push(adj_node);  	 // 큐에 넣기 
				
				dis[adj_node] = dis[num] + 1; // 현재 노드에서 간선 하나 더.  
			} 
		} 
	}
	
	// 2번 정점부터 n번 정점까지의 최소 이동 간선 수 출력  
	for(i=2; i <= vertex; i++){
		printf("%d : %d\n", i, dis[i]);
	}
	
	return 0;
}


