#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;


// 31. źȭ���� ����  mass_of_hydrocarbon

/*

ź��(C)�� ����(H)�θ� �̷���� ȭ�չ��� źȭ���Ҷ�� �մϴ�.
ź��(C) �� ���� ������ 12g, ����(H) �� ���� ������ 1g�Դϴ�.
��ƿ��(C2H4)�� ������ 12*2+1*4=28g�Դϴ�.
��ź(CH4)�� ������ 12*1+1*4=16g�Դϴ�.
źȭ���ҽ��� �־����� �ش� ȭ�չ��� ������ ���ϴ� ���α׷��� �ۼ��ϼ���.

ù �ٿ� źȭ���ҽ��� �־����ϴ�. ���� ���´� CaHb �����̸� (1<=a, b<=100)�̴�.
�� a �� b �� 1�̸� ���ڰ� �Ŀ� �Էµ��� �ʴ´�. ��) CH4

�Է� input.txt
C2H4

��� 
28

*/


int main(int argc, char** argv) {
	
	// �迭 
	char arr[10];
	// c �� ����, h �� ����, pos : ���ڸ� ���� �迭 �ε���   
	int c = 0, h = 0, i = 0, pos = 0;
	
	//freopen("input.txt", "rt", stdin);
	 
	scanf("%s", &arr);

	if(arr[1] == 'H') {
		c = 1;
		pos = 1; 
	}else{
		
		for(i=1; arr[i] != 'H'; i++){
			c = c*10 + (arr[i]-48);
		}
		pos = i;
	} 
	 
	if(arr[pos+1] == '\0') h=1;
	else{
		for(i=pos+1; arr[i] != '\0'; i++){
			h = h*10 + (arr[i]-48);
		}
	}
	 
	printf("%d", c*12+h); 
	 
	return 0;
	
}

