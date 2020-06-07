#include <stdio.h> 
#include <string.h>
#include <vector> 
#include <algorithm>
using namespace std;

// 40. ������   intersection

/*

�� ���� A, B�� �־����� �� ������ �������� ����ϴ� ���α׷��� �ۼ��ϼ���.

�� �Է¼���
ù ��° �ٿ� ���� A�� ũ�� N(1<=N<=30,000)�� �־����ϴ�.
�� ��° �ٿ� N���� ���Ұ� �־����ϴ�. ���Ұ� �ߺ��Ǿ� �־����� �ʽ��ϴ�.
�� ��° �ٿ� ���� B�� ũ�� M(1<=M<=30,000)�� �־����ϴ�.
�� ��° �ٿ� M���� ���Ұ� �־����ϴ�. ���Ұ� �ߺ��Ǿ� �־����� �ʽ��ϴ�.
�� ������ ���Ҵ� int�� ������ ũ�⸦ ���� �ʽ��ϴ�.

�� ��¼���
�� ������ �������� �������� �����Ͽ� ����մϴ�

*/

int main(int argc, char** argv){
	
	int a_size, b_size, ap=0, bp=0, resp=0, i = 0; 
	
	freopen("input.txt", "rt", stdin);
	
	// �Է¹ޱ� ����  (���� 3�� ����� a�� b �Է¹ޱ�) 
	scanf("%d", &a_size);
	vector<int> a(a_size);
	
	for(i=0; i<a_size; i++){
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &b_size);
	vector<int> b(b_size);
	vector<int> res(a_size+b_size);
	
	for(i=0; i<b_size; i++){
		scanf("%d", &b[i]);
	} // �Է� �ޱ� ��  
	
	sort(a.begin(), a.end()); // sort() �Լ��� algorithm ����� ����  
	sort(b.begin(), b.end()); 

	while(ap < a_size && bp < b_size){
		
		if(a[ap] == b[bp]){ // ������ �߰� 
			res[resp++] = a[ap++];
			bp++; 
		}else if(a[ap] < b[bp]){
			ap++;
		}else{ // a[ap] > b[bp] 
			bp++; 
		}
	}

	for(i=0; i<resp; i++){
		printf("%d ", res[i]);
	}

	return 0;
}

