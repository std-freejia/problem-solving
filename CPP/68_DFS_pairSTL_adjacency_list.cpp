#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


// 68. 최소비용 (DFS: 가중치 방향그래프 인접리스트) 

/* 67과 같은 문제인데,  STL pair 를 사용하여 가중치 방향그래프 인접리스트를 구현  

pair 사용하려면 #include <algorithm> 

가중치 방향그래프 : 정점 자신이 가리키고 있는 정점에 대해서만 인접해 있다고 표현  
 
*/

int vertex; // 정점 개수  

// pair<도착정점, 가중치>
vector<pair<int,int> > map[21]; // 정점 1 <= vertex <= 20  

int check[21]; // 정점 방문 여부 
int min_weight = 2147000000; // 1번 정점에서 vertex 정점까지 가는 경로의 최소비용  


void DFS(int v, int w){

	int i = 0;
	
	if(v == vertex){ // 목적지 정점 도달 
		
		if(min_weight > w){ // 최소비용이라면 갱신  
			min_weight = w;
		} 
		
	}else{
		
		//목적지 도착할 때 까지 움직여본다. 
		for(i = 0; i < map[v].size(); i++){

			pair<int,int> togo = map[v][i]; // 도착지 정점과 가중치 (first, second)  
			
			if(togo.first != 0 && check[togo.first] == 0){ //안 가본 정점이 있다면, 
				check[togo.first] = 1; 
				DFS(togo.first, w + togo.second);
				check[togo.first] = 0;
			}
		}
	}
	
}

int main(void){

	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);

/*
	pair<int,int> p; // p.front, p.second 로 접근할 수 있다.  
	p = make_pair(10, 20);
	printf("%d %d", p.first, p.second);
	
	#define x first
	#define y second

	전처리를 통해 p.x, p.y 로 접근할 수 있다.  
*/
	
	int edge = 0;
	int i = 0, start = 0, end = 0, weight = 0;
	
	scanf("%d %d", &vertex, &edge);
	
	for(i = 1; i <= edge; i++){
		scanf("%d %d %d", &start, &end, &weight);
		map[start].push_back(make_pair(end, weight)); 
	}
	
	check[1] = 1;  // 1번 정점 방문함  
	DFS(1, 0);
	
	printf("%d", min_weight);
	
	return 0;
}
