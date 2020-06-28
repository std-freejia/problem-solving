#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 64. [�߿�] ���Ž�� (DFS) 

 
int map[21][21];   // ����׷��� �������  
int ch[21]; // üũ�迭 (��湮 ���ϱ� ���� �迭) 
int cnt = 0; // ��� ����  
int n, m;

void DFS(int v){
	
	int i = 0;
	
	if(v == n){  // ���������� �Դ���  
		cnt++;
		return;
		
	}else{
		
		for(i=1; i<=n; i++){
			
			if(map[v][i] == 1 && ch[i] == 0){ // ������ �����ϴ���. ���� �湮 ���ߴ���. 
				
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
	
	scanf("%d %d", &n, &m); // ���� ����, ���� ����.  
	
	for(i=1; i<=m; i++)	{ // ������ ������ŭ �Է¹޴´�  
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}
	
	// 1���� 5�� �������� ���� ��� ��� ���� Ž��  
	ch[1] = 1;
	
	DFS(1);
	
	printf("%d", cnt);
	// ���� https://lasthere.tistory.com/15 
	return 0;
}
