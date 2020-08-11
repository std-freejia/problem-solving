#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// 69. 이진트리 넓이우선탐색(BFS, 큐 직접구현) 

int Q[10]; 
int front = -1, back = -1;
int check[10];
vector<int> map[10];  // 인접리스트  
 
int main(void){

	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);

	int i, a, b, x = 0;
	
	for(i=1; i<=6; i++){  // 정점 6개, 간선 5개 고정. 
		scanf("%d %d", &a, &b);
		map[a].push_back(b); // 무방향 그래프  
		map[b].push_back(a);
	}
	
	Q[++back] = 1; // 루트노드(1번 정점) 큐에 넣고  
	check[1] = 1;  // 루트노드 방문  

	// 큐에 데이터가 있으면, front가 back 앞에 있다.  
	// front와 back이 같아지면 빈 큐다.  
	
	while(front < back){ 
	
		x = Q[++front]; // dequeue 
		printf("%d ", x);
		
		for(i=0; i<map[x].size(); i++){
		
			if(check[map[x][i]] == 0){ // 처음 방문하는 노드  
				check[map[x][i]] = 1;
				Q[++back] = map[x][i]; // enqueue
			}
		}
		
	}

	return 0;
}
