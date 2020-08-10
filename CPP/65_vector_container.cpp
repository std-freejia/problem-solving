#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// 65_vector �������  

int main(){

	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	/* STL vector */
	vector<int> a(5); // ũ�� 5�� ����a ����. 
	// 0, 1, 2, 3, 4 �ε����� ���� (���� 0���� �ʱ�ȭ) 
	
	a[1] = 5;
	cout << a[1] << endl; // 5 ���  
	a.push_back(6);
	a.push_back(7);
	
	int v_size = 0;
	vector<int> b(v_size); // ()�Ұ�ȣ�� ����b�� ũ�⸦ ����
	 
	// [] ���ȣ�� ������ ���� 
	vector<int> c[3]; // c��� �̸��� ���� ���� 3�� ����  c[0], c[1], c[2]
	c[0].push_back(1);
	c[0].push_back(3);
	c[0].push_back(5); // c[0] 1, 3, 5
	c[1].push_back(2);
	c[1].push_back(4);
	c[1].push_back(6); // c[1] 2 4 6
	
	cout << c[0][0] << endl;  // 1 ���  
	cout << c[1][2] << endl;  // 6 ��� 
	
	
	/* STL pair  */ 
	vector<pair<int, int> > g[3];  // ���� 3�� ����  
	 
	g[0].push_back({3, 5});
	g[0].push_back({4, 6});
	g[1].push_back(make_pair(1, 2));
	g[2].push_back(make_pair(8, 9));
		
	cout << g[0][0].first << " " << g[0][1].second << endl; // 3 6 ��� 
	
	cout << g[1][0].second << endl; // 2 ��� 
	
	cout << g[2][0].first << " " << g[2][0].second << endl;  // 8 9 ���  
	
	return 0;
}
