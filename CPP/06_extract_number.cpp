#include <stdio.h> 
using namespace std;

// 6. ���ڸ� ����  extract_number
// ���ڿ��� ���ڸ� �����Ͽ� �ڿ����� ����մϴ�. 
// �׸��� �ڿ����� ����� ������ ����մϴ�.  

/* input.txt
g0en2Ts8eSoft
*/
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);

	char arr[100];
	int res = 0, cnt = 0, i;
	
	scanf("%s", &arr);
	
	// '\0' ���ڿ��� ���� �ǹ��ϴ� �ι���  
	for(i=0; arr[i]!='\0'; i++){
		if(arr[i] >= 48 && arr[i]<= 57){ // ����0~9�� �ش��ϴ� ASCII  
			res = res*10 + (arr[i]-48);
		}
	}
	printf("%d\n", res);
	
	// ����� ���� ���ϱ� 
	for(i=1; i<=res; i++){
		if(0 == res%i){
			cnt++;
		}
	} 
	
	printf("%d\n", cnt);

	return 0;
}


