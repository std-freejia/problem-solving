#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// H-index (���α׷��ӽ�) by std-freejia 


int solution(vector<int> citations){
	
	int answer = 0;
	
	// ���� 
	sort(citations.begin(), citations.end(), greater<int>()); 
		
	while(answer < citations.size()){
		
		if(citations[answer] <= answer){ // �ε��� ���� �۾����� ���� ����. 
			break;
		}else{
			answer++;
		}
	}

	return answer;
}
