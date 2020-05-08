#include <stdio.h> 

// 17. 선생님 퀴즈 sum_quiz  
/*
선생님은 각 학생들에게 숫자가 적힌 카드를 줬습니다. 
각 학생들은 1부터 자기 카드에 적힌 숫자까지의 합을 구하는 퀴즈입니다. 

첫 줄에 반 학생수인 자연수 N(1<=N<=10)이 주어집니다.
각 학생들은 1부터 N까지 번호가 부여되어 있다고 가정합니다.
두 번째 줄부터 1번 학생부터의 카드에 적힌 수와 학생이 구한 정답이 공백을 사이에 두고 입력된다. 
카드에 적힌 수는 1000을 넘지 않는다.

첫 줄부터 1번 학생이 정답을 맞추면 “YES", 틀리면 ”NO"를 출력하세요.

input.txt
3
10 55
20 350
100 5050
*/

int main(int argc, char** argv) {

	int repeat = 0, i=0, j=0, sum=0, num=0, answer=0;	
	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &repeat);
	
	for(i=0; i<repeat; i++){
		
		scanf("%d %d", &num, &answer);
		
		sum = 0;

		for(j=1; j<=num; j++){
			sum += j;	
		}
		
		if(answer == sum) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}


