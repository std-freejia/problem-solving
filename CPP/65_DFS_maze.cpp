#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 65. 미로탐색 DFS
 
/*
64 번과 유사한 DFS문제. 

방향 탐색 dx, dy  

*/

int map[8][8], ch[8][8];  // 7*7 map 크기고정.  
int dx[4] = {1, -1, 0, 0};  
int dy[4] = {0, 0, 1, -1}; // 47번 봉우리 문제에서 방향 바꾼것 활용. 동서남북 
int cnt;

void DFS(int x, int y){
	
	int i, xx, yy;  // 4개의 방향을 가보기 위한 변수   
	
	if(x == 7 && y == 7) { // 종착점 도착 cnt++ 
		cnt++;
		return;
	}else{
		
		for(i=0; i<4; i++){ 
			xx = x+dx[i]; // 현재좌표 기준에서, 4방향을 가본다.  
			yy = y+dy[i];
			
			if(xx<1 || xx>7 || yy<1 || yy>7) continue; // map을 벗어나면 지나감.
			if(map[xx][yy] == 0 && ch[xx][yy] == 0) { // 0인데, 안가본 곳이라면,  
				ch[xx][yy] = 1; // 가본다.  
				DFS(xx, yy);
				ch[xx][yy] = 0; // 물러난다.  
			} 
			
		}
	}
	
}

int main(void){
	
	//freopen("input.txt", "rt", stdin);
	int i, j = 0;
	
	// map 받기 
	for(i=1; i<=7; i++){
		for(j=1; j<=7; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	ch[1][1] = 1; // 시작점에 들어갔으니까 1로 변경 (가본 곳을 1로 표시) 
	DFS(1, 1);	
	
	printf("%d", cnt);
	
	return 0;
} 
