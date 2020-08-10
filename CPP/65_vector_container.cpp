#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// 65_vector 생성방법  

int main(){

	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	/* STL vector */
	vector<int> a(5); // 크기 5인 벡터a 생성. 
	// 0, 1, 2, 3, 4 인덱스를 가짐 (값은 0으로 초기화) 
	
	a[1] = 5;
	cout << a[1] << endl; // 5 출력  
	a.push_back(6);
	a.push_back(7);
	
	int v_size = 0;
	vector<int> b(v_size); // ()소괄호로 벡터b의 크기를 선언
	 
	// [] 대괄호는 벡터의 개수 
	vector<int> c[3]; // c라는 이름을 가진 벡터 3개 생성  c[0], c[1], c[2]
	c[0].push_back(1);
	c[0].push_back(3);
	c[0].push_back(5); // c[0] 1, 3, 5
	c[1].push_back(2);
	c[1].push_back(4);
	c[1].push_back(6); // c[1] 2 4 6
	
	cout << c[0][0] << endl;  // 1 출력  
	cout << c[1][2] << endl;  // 6 출력 
	
	
	/* STL pair  */ 
	vector<pair<int, int> > g[3];  // 벡터 3개 생성  
	 
	g[0].push_back({3, 5});
	g[0].push_back({4, 6});
	g[1].push_back(make_pair(1, 2));
	g[2].push_back(make_pair(8, 9));
		
	cout << g[0][0].first << " " << g[0][1].second << endl; // 3 6 출력 
	
	cout << g[1][0].second << endl; // 2 출력 
	
	cout << g[2][0].first << " " << g[2][0].second << endl;  // 8 9 출력  
	
	return 0;
}
