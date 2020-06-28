#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 64. [중요] 경로탐색 (DFS) 

 
int map[21][21];   // 방향그래프 인접행렬  
int ch[21]; // 체크배열 (재방문 안하기 위한 배열) 
int cnt = 0; // 경로 개수  
int n, m;

void DFS(int v){
	
	int i = 0;
	
	if(v == n){  // 도착지점에 왔는지  
		cnt++;
		return;
		
	}else{
		
		for(i=1; i<=n; i++){
			
			if(map[v][i] == 1 && ch[i] == 0){ // 정점이 존재하는지. 아직 방문 안했는지. 
				
				ch[i] = 1;
				DFS(i);
				ch[i] = 0;
			}
		}
	}	
}

int main(void){
	
	//freopen("input.txt", "rt", stdin);
	int i, j, a, b = 0;
	
	scanf("%d %d", &n, &m); // 정점 개수, 간선 개수.  
	
	for(i=1; i<=m; i++)	{ // 간선의 개수만큼 입력받는다  
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}
	
	// 1에서 5번 정점까지 가는 모든 경로 완전 탐색  
	ch[1] = 1;
	
	DFS(1);
	
	printf("%d", cnt);
	// 참고 https://lasthere.tistory.com/15 
	return 0;
}
