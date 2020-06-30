#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

// blackjack  ���� 2798 (2020-06-19 freejia)

int cnt_cards, sum_limit, max_sum;
int cards[101];
bool choose[101]; 

int Sum_check(void){
	
	int sum = 0, i = 0;
	
	for(i=0; i<cnt_cards; i++){
		if(choose[i]){
			sum += cards[i];
		}
	}
	
	return sum;
} 

void Combination(int idx, int cnt_choose){ 
	
	int temp_sum = 0;
	
	if (cnt_choose == 3){
		// ���� �� ����. 
		temp_sum = Sum_check();
		
		if(temp_sum > max_sum && temp_sum <= sum_limit){ // �ִ��̸鼭 ���Ѱ� �ȳѴ� ��. 
			max_sum = temp_sum;
		}
		//printf("%d\n", temp_sum);
		return;
	}
	
	for(int i = idx; i<cnt_cards; i++){
		
		if(choose[i] == true){ // �̹� ���� ���̸� ��������  
			continue;
		}
		choose[i] = true; // �ϳ� ���� ǥ��. 
		
		Combination(i+1, cnt_choose+1);
		
		choose[i] = false; // �Ȼ̴� ������ �ǵ�����.  
	}
} 

int main(int argc, char** argv){

	int i = 0;
	
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &cnt_cards, &sum_limit); // �Է� �ޱ� ����  

	for(i=0; i<cnt_cards; i++){
		scanf("%d", &cards[i]);
	}// �Է� �ޱ� ��  
	
	Combination(0, 0); 
	
	printf("%d", max_sum);
	
	return 0;
}


