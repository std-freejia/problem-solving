#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


// 66. ���Ž�� (DFS:��������Ʈ ���)  vector ���  

int check[21]; 
int cnt; // ��� ���� �� ����. 
int vertex; // ����  
vector<int> map[21]; // ����  1<=����<=20  ���Ͱ� 21�� ����°�.(ũ��21�ƴ�) 


void DFS(int v){

	if(v == vertex) { // ������ ���� ���� ��, ���� ����.  
		cnt++;
	} else{
		
		// �� �� ���� �� ���� ������.  
		for(int i = 0; i < map[v].size(); i++){
		
			int togo = map[v][i]; // �� �� �ִ� ���� 
			 
			if(check[togo] == 0){ // ���� �� ���ôٸ�,  
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
	
	int edge = 0; // ����
	int i, j, a, b = 0;
	
	scanf("%d %d", &vertex, &edge);
	
	for(i=1; i<=edge; i++){
		scanf("%d %d", &a, &b); // ��������,  ��������  
		map[a].push_back(b);
	}
	
	// map[3].size() : ���� 3���� �� �� �ִ� ���� ���� 
	
	check[1] = 1; // 1�� ������ �湮����. 
	 
	DFS(1);
	 
	// 1������ vertex�������� ���� ��� ����� ���� �� ���. 
	printf("%d", cnt); 
	
	return 0;
}
