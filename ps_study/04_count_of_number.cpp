#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

// ������ ����  (����) 2020-06-10
// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=706&sca=2030
 

int main(int argc, char** argv){

	int a, b, c = 0;
	int res, i = 0;
	int cnt_arr[10] = {0, }; // 0���� 9���� ������ ����  
		 
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d %d", &a, &b, &c);
	
	res = a * b * c;
	
	while(res > 0){
		cnt_arr[res%10]++;
		res /= 10;
	}
	
	for(i=0; i<10; i++){
		printf("%d\n", cnt_arr[i]);
	}

	return 0;
}

