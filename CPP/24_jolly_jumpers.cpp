#include <stdio.h> 
#include <vector> 
#include <algorithm>
using namespace std;

// 24.  Jolly Jumpers

/*
N개의 정수로 이루어진 수열에 대해 서로 인접해 있는 두 수의 차가 1에서 N-1까지의 값을
모두 가지면 그 수열을 유쾌한 점퍼(jolly jumper)라고 부른다. 

예를 들어 다음과 같은 수열에서 1 4 2 3 앞 뒤에 있는 숫자 차의 절대 값이 각각 3 ,2, 1이므로 
이 수열은 유쾌한 점퍼가 된다. 
어떤 수열이 유쾌한 점퍼인지 판단할 수 있는 프로그램을 작성하라.

첫 번째 줄에 자연수 N(3<=N<=100)이 주어진다.
그 다음 줄에 N개의 정수가 주어진다. 정수의 크기는 int 형 범위안에 있습니다.

유쾌한 점퍼이면 “YES"를 출력하고, 그렇지 않으면 ”NO"를 출력한다

input.txt
5
1 4 2 3 7

*/


int main(int argc, char** argv) {

	int total=0, i=0, pre=0, now=0, minus=0, absnum=0;
	bool flag = true;

	//freopen("input.txt", "rt", stdin);	

	scanf("%d", &total);
	
	vector<int> num(total);

	scanf("%d", &pre);

	for(i=1; i<total; i++){
		
		scanf("%d", &now);
		minus = abs(pre-now);
		
		if(minus > 0 && minus < total && num[minus] == 0){ // 범위 안에 있다면, 중복 체크. 
			num[minus] = 1; 
		}else{ //
			printf("NO\n");
			return 0;
		}
		
		pre = now;
	}
	
	printf("YES\n");

	return 0;
}

