#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


// 66. 경로탐색 (DFS:인접리스트 방법)  vector 사용  

int check[21]; 
int cnt; // 경로 가지 수 누적. 
int vertex; // 정점  
vector<int> map[21]; // 정점  1<=정점<=20  벡터가 21개 생기는것.(크기21아님) 


void DFS(int v){

	if(v == vertex) { // 목적지 정점 도착 시, 개수 센다.  
		cnt++;
	} else{
		
		// 갈 수 있을 때 까지 가본다.  
		for(int i = 0; i < map[v].size(); i++){
		
			int togo = map[v][i]; // 갈 수 있는 정점 
			 
			if(check[togo] == 0){ // 아직 안 가봤다면,  
				check[togo] = 1; 
				DFS(map[v][i]);
				check[togo] = 0; 
			}
		}
	}

}

int main(){

	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	int edge = 0; // 간선
	int i, j, a, b = 0;
	
	scanf("%d %d", &vertex, &edge);
	
	for(i=1; i<=edge; i++){
		scanf("%d %d", &a, &b); // 시작정점,  도착정점  
		map[a].push_back(b);
	}
	
	// map[3].size() : 정점 3에서 갈 수 있는 정점 개수 
	
	check[1] = 1; // 1번 정점은 방문했음. 
	 
	DFS(1);
	 
	// 1번에서 vertex정점까지 가는 모든 경로의 가지 수 출력. 
	printf("%d", cnt); 
	
	return 0;
}
