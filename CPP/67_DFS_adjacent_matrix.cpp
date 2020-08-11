#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


// 67. 최소비용 (DFS: 인접행렬) 

// 가중치 방향그래프 : 정점 자신이 가리키고 있는 정점에 대해서만 인접해 있다고 표현  
 
int vertex; // 정점 개수  
int map[21][21]; // 정점 1<=vertex<=20 
int min_weight = 2147000000; // 1번 정점에서 vertex 정점까지 가는 경로의 최소비용  
int check[21]; // 정점 방문 체크  

void DFS(int v, int w){

	int i = 0;
	
	if(v == vertex){ // 목적지 정점 도달 
		
		if(min_weight > w){ // 최소비용이라면 갱신  
			min_weight = w;
		} 
		
	}else{
		
		//목적지 도착할 때 까지 움직여본다. 
		for(i = 1; i <= vertex; i++){

			if(map[v][i] != 0 && check[i] == 0){ //안 가본 정점이 있다면, 
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
	
	check[1] = 1;  // 1번 정점 방문함  
	DFS(1, 0);
	
	printf("%d", min_weight);
	
	return 0;
}
