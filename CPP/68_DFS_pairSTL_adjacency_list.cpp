#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


// 68. �ּҺ�� (DFS: ����ġ ����׷��� ��������Ʈ) 

/* 67�� ���� �����ε�,  STL pair �� ����Ͽ� ����ġ ����׷��� ��������Ʈ�� ����  

pair ����Ϸ��� #include <algorithm> 

����ġ ����׷��� : ���� �ڽ��� ����Ű�� �ִ� ������ ���ؼ��� ������ �ִٰ� ǥ��  
 
*/

int vertex; // ���� ����  

// pair<��������, ����ġ>
vector<pair<int,int> > map[21]; // ���� 1 <= vertex <= 20  

int check[21]; // ���� �湮 ���� 
int min_weight = 2147000000; // 1�� �������� vertex �������� ���� ����� �ּҺ��  


void DFS(int v, int w){

	int i = 0;
	
	if(v == vertex){ // ������ ���� ���� 
		
		if(min_weight > w){ // �ּҺ���̶�� ����  
			min_weight = w;
		} 
		
	}else{
		
		//������ ������ �� ���� ����������. 
		for(i = 0; i < map[v].size(); i++){

			pair<int,int> togo = map[v][i]; // ������ ������ ����ġ (first, second)  
			
			if(togo.first != 0 && check[togo.first] == 0){ //�� ���� ������ �ִٸ�, 
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
	pair<int,int> p; // p.front, p.second �� ������ �� �ִ�.  
	p = make_pair(10, 20);
	printf("%d %d", p.first, p.second);
	
	#define x first
	#define y second

	��ó���� ���� p.x, p.y �� ������ �� �ִ�.  
*/
	
	int edge = 0;
	int i = 0, start = 0, end = 0, weight = 0;
	
	scanf("%d %d", &vertex, &edge);
	
	for(i = 1; i <= edge; i++){
		scanf("%d %d %d", &start, &end, &weight);
		map[start].push_back(make_pair(end, weight)); 
	}
	
	check[1] = 1;  // 1�� ���� �湮��  
	DFS(1, 0);
	
	printf("%d", min_weight);
	
	return 0;
}
