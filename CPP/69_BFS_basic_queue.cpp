#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// 69. ����Ʈ�� ���̿켱Ž��(BFS, ť ��������) 

int Q[10]; 
int front = -1, back = -1;
int check[10];
vector<int> map[10];  // ��������Ʈ  
 
int main(void){

	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);

	int i, a, b, x = 0;
	
	for(i=1; i<=6; i++){  // ���� 6��, ���� 5�� ����. 
		scanf("%d %d", &a, &b);
		map[a].push_back(b); // ������ �׷���  
		map[b].push_back(a);
	}
	
	Q[++back] = 1; // ��Ʈ���(1�� ����) ť�� �ְ�  
	check[1] = 1;  // ��Ʈ��� �湮  

	// ť�� �����Ͱ� ������, front�� back �տ� �ִ�.  
	// front�� back�� �������� �� ť��.  
	
	while(front < back){ 
	
		x = Q[++front]; // dequeue 
		printf("%d ", x);
		
		for(i=0; i<map[x].size(); i++){
		
			if(check[map[x][i]] == 0){ // ó�� �湮�ϴ� ���  
				check[map[x][i]] = 1;
				Q[++back] = map[x][i]; // enqueue
			}
		}
		
	}

	return 0;
}
