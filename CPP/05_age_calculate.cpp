#include <stdio.h> 
using namespace std;

// 5. ���� ���(���ڿ� ��Ʈ��) age_calculate
// �ֹε������ ��ȣ�� �־����� �ֹε���� ������ ���̿� ������ �Ǵ��ϼ���. (2019�����) 
// �ֹι�ȣ�� char �迭�� �ְ�, ���� ���, ���� �Ǻ��� �Ѵ�.  

/* input.txt
780316-2376152 
*/
int main(int argc, char** argv) {
	
	//freopen("input.txt", "rt", stdin);
	// cin, cout ���ٴ� scanf, printf �� ������. 
	char num_arr[20];
	int year, age;
	
	scanf("%s", &num_arr);
	
	if('1' == num_arr[7] || '2' == num_arr[7]){ // 1900���� 
		// ���� 0�� �������� 48�̴�. (ASCII �ڵ� ����)  
		// 'A' 65 'Z' 90 'a' 97 '0' 48 '9' 57
		year = 1900+((num_arr[0]-48)*10 + (num_arr[1]-48));
	}else{ // 2000 ��� ��  
		year = 2000+((num_arr[0]-48)*10 + (num_arr[1]-48));
	} 		
	age = 2019-year+1;
	printf("%d ", age);
	
	if('1' == num_arr[7] || '3' == num_arr[7]){
		printf("M\n");
	}else{
		printf("W\n");
	}
	
	return 0;
}


