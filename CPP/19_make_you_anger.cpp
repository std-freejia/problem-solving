#include <stdio.h> 

// 19.�г� ������  make_you_anger
/*
������ �¼��� ��ȭ��ó�� ������� �ƴ϶� ������ �ٴڿ� ���ڸ� ��ġ�ϰ� �л����� �ɽ���
��. 
�׷��� ���� ���ڸ��� ���� Ű�� ū �л��� ������ �� �л����� ����Ű�� ���� ���ڸ� ��
���� ��ũ���� ������ �ʽ��ϴ�. 
�� �ٿ� ����Ű ������ �־����� 
�޻�� ����� �þ߸� ���� ��ȭ ��û�� �Ұ����ϰ� �ϴ� �г������ڰ� 
�� �ٿ� �� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��ϼ���.


input.txt
10
56 46 55 76 65 53 52 53 55 50
*/
int student[101];

int main(int argc, char** argv) {

	int repeat = 0, i=0, max=-2147000000, count=0;	
	//freopen("input.txt", "rt", stdin);	
	 
	scanf("%d", &repeat);
		
	for(i=0; i<repeat; i++){ // �迭�� ���� ����  
		scanf("%d", &student[i]);		
	}
	
	max = student[repeat-1];
	
	for(i=repeat-1; i>0; i--){ 	// �迭 �� �ڿ��� ���� max�� ���ŵǴ� Ƚ���� ���� �ȴ�. 
		if(student[i] < student[i-1] && max < student[i-1]){
			count++;
			max = student[i-1];
		}
	}
	
	printf("%d", count);
	
	return 0;
}


