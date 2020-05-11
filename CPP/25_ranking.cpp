#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;

// 25. ���� ���ϱ�   ranking

/*
N���� �л��� ���������� �ԷµǸ� �� �л��� ������ �Էµ� ������� ����ϴ� ���α׷��� �ۼ��ϼ���.

ù �ٿ� N(1<=N<=100)�� �Էµǰ�, �� ��° �ٿ� ���������� �ǹ��ϴ� N���� ������ �Էµȴ�. 
���� ������ �Էµ� ��� ���� ������ ���� ó���Ѵ�. 
�� ���� ���� ������ 92���ε� 92���� 3�� �����ϸ� 1���� 3���̰� �� ���� �л��� 4���� �ȴ�. 
������ 100�� �����̴�.


input.txt
5
90 85 92 95 90

*/


int main(int argc, char** argv) {

	int total=0, i=0, j=0, temp=0, a=0;
	
	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &total);
	
	vector<int> num(total);
	
	vector<int> rank(total, 1);
	
	for(i=0; i<total; i++){ // ���� �ֱ�  
		scanf("%d", &num[i]);
	}
	
	for(i=0; i<total; i++){
		
		for(j=0; j<total; j++){
			if(num[i] < num[j]){
				rank[i]++;
			}
		}

	}
	
	for(i=0; i<total; i++){ // ���� �ֱ�  
		printf("%d ", rank[i]);
	}
	
	return 0;
}


/*
ó�� Ǯ���� ��, �׽�Ʈ���̽� 5�� �߿� 2���� �ð� �ʰ� ����. 

���� �ϳ��� ��������(90), ��� ���ڿ� ���ϸ鼭 ����� ���Ѵ�. 
�� ���� ���ڸ� ��������(85) ��� ���ڿ� ���ϸ鼭 ����� ���Ѵ�. 

 
*/
