#include <stdio.h> 

// 14. ������ �Ҽ�  reversed prime

/*
N���� �ڿ����� �ԷµǸ� �� �ڿ����� ������ �� �� ������ ���� �Ҽ��̸� �� ���� ����ϴ�
���α׷��� �ۼ��ϼ���. 
 
���� ���, 32�� �������� 23�̰�, 23�� �Ҽ��̴�. �׷��� 23�� ����Ѵ�. 
*/

/* input.txt
5
32 55 62 3700 250
*/

bool isPrime(int x){ // �Ҽ����� �Ǻ�
	int i = 0;
	
	// 1�� �Ҽ��� �ƴϹǷ� ����!  
	if(x == 1) return false; 
	
	for(i=2; i<x; i++){
		if(x%i == 0){
			return false;
		}
	}
	
	return true;
}

int reverse(int x){ // �ڿ��� ������ 
	int res=0, temp=0;
	
	while(x>0){
		temp = x%10;
		res = res*10 + temp;
		x = x/10;
	}

	return res;
}

int main(int argc, char** argv) {
	
	int cnt=0, i=0, num=0;
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &cnt);
	
	for(i=0; i<cnt; i++){
		scanf("%d", &num);
		num = reverse(num);
		
		if(isPrime(num)){
			printf("%d ", num);
		}
	}
	
	return 0;
}


