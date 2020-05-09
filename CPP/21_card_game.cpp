#include <stdio.h> 

// 21. 카드게임 card_game 

/*
두 사람 A와 B가 게임을 한다. A와 B에게는 각각 0에서 9까지의 숫자가 하나씩 표시된 10장의 카드뭉치가 주어진다. 
두 사람은 카드를 임의의 순서로 섞은 후 숫자가 보이지 않게 일렬로 늘어놓고 게임을 시작한다. 
단, 게임 도중 카드의 순서를 바꿀 수는 없다.

A와 B 각각이 늘어놓은 카드를 뒤집어서 표시된 숫자를 확인하는 것을 한 라운드라고 한
다. 
각 라운드에서는 공개된 숫자가 더 큰 사람이 승자가 된다. 
승자에게는 승점 3점이 주어지고 패자에게는 승점이 주어지지 않는다. 만약 공개된 두 숫자가 같아서 비기게 되면, A, B 모두에게 승점 1
점이 주어진다.

10번의 라운드가 모두 진행된 후, 총 승점이 큰 사람이 게임의 승자가 된다. 
만약, A와 B의 총 승점이 같은 경우에는, 제일 마지막에 이긴 사람을 게임의 승자로 정한다. 
그래도 승부가 나지 않는 경우는 모든 라운드에서 비기는 경우뿐이고 이 경우에 두 사람은 비겼다고 한
다.


input.txt
4 5 6 7 0 1 2 3 9 8
1 2 3 4 5 6 7 8 9 0
*/


int main(int argc, char** argv) {

	int repeat = 10, i=0, a_score=0, b_score=0, lastwin=-1, count=0;	
	int a[10]={0,}, b[10]={0, };
	 
	//freopen("input.txt", "rt", stdin);	

	// -1 비김 / 0 A승  / 1 B승  
	
	for(i=0; i<repeat; i++){
		scanf("%d", &a[i]);
	}
	
	for(i=0; i<repeat; i++){
		scanf("%d", &b[i]);
	}

	for(i=0; i<repeat; i++){
		
		if(a[i]>b[i]){ // A승 
			a_score += 3;
			lastwin = 0;
		}else if(b[i]>a[i]){ // B승 
			b_score += 3;
			lastwin = 1;
		}else{
			a_score += 1;
			b_score += 1;
		}
		
	}
	
	printf("%d %d\n", a_score, b_score);
	
	if(lastwin == -1){
		printf("D");
	}else if(lastwin == 0){
		printf("A");
	}else{
		printf("B");
	}

	return 0;
}


