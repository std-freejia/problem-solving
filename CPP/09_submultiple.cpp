#include <stdio.h> 

// 9. ����� ��� (���ѽð� 1��) submultiple
/*
�ڿ��� N�� �ԷµǸ� 1���� N������ �� ���ڵ��� ����� ������ ����ϴ� ���α׷��� �ۼ���
����.
���� N�� 8�� �Էµȴٸ� 1(1��), 2(2��), 3(2��), 4(3��), 5(2��), 6(4��), 7(2��), 8(4
��) �� ���� �� ������ ����� ������ �������ϴ�. 
*/

int cnt[50001];

int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	int input=0, i=0, j=0;
	
	scanf("%d", &input);
	
	for(i=1; i<=input; i++){
		
		// i�� ������� +1 ó�����ش�. 
		// i�� ����� ���� ���ڵ��� ã�� ���̴�.  
		for(j=i; j<=input; j=j+i){
			cnt[j]++;
		}
	}
	
	for(i=1; i<=input; i++){
		printf("%d ", cnt[i]);
	} 

	return 0;
}


