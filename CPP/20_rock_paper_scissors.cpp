#include <stdio.h> 

// 20. ���� ���� ��  rock_paper_scissors

/*
A�� B �� ����� ���������� ������ �մϴ�. 
�� N���� ������ �Ͽ� A�� �̱�� A�� ����ϰ�, B�� �̱�� B�� ����մϴ�. ����쿡 D�� ����մϴ�. 
����, ����, ���� ������ 1:����, 2:����, 3:���� ���ϰڽ��ϴ�.

�� ����� �� ȸ�� ����, ����, �� ������ �־����� �� ȸ�� ���� �̰���� ����ϴ� ���α׷�
�� �ۼ��ϼ���

ù ��° �ٿ� ���� Ƚ���� �ڿ��� N(1<=N<=100)�� �־����ϴ�.
�� ��° �ٿ��� A�� �� ����, ����, �� ������ N�� �־����ϴ�.
�� ��° �ٿ��� B�� �� ����, ����, �� ������ N�� �־����ϴ�.

input.txt
5
2 3 3 1 3
1 1 2 2 3
*/
int a[101], b[101];

int main(int argc, char** argv) {

	int repeat = 0, i=0, count=0;	
	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &repeat);
		
	for(i=0; i<repeat; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<repeat; i++){
		scanf("%d", &b[i]);
	}
	
	for(i=0; i<repeat; i++){
		if(a[i] == b[i]){
			printf("D\n");
		}else if(b[i]-a[i] == 1 || a[i]-b[i] == 2){
			printf("B\n");
		}else{ // a[i]-b[i] == 1 || b[i]-a[i] == 2
			printf("A\n");
		}
	}
	
	return 0;
}

