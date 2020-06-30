#include <stdio.h>
#include <string>
#include <queue>
#include <utility> // pair
#include <vector>
#include <algorithm>
using namespace std;

// ������ (���α׷��ӽ�) 
 
/*
1. �μ� ������� ���� �տ� �ִ� ����(J)�� ����Ͽ��� �����ϴ�.
2. ������ �μ� ����Ͽ��� J���� �߿䵵�� ���� ������ �� ���� �����ϸ� 
J�� ������� ���� �������� �ֽ��ϴ�.
3. �׷��� ������ J�� �μ��մϴ�.
*/

int solution(vector<int> priorities, int location) {

    int answer = 0; // ��� ����  
	int i = 0;
	
	queue<pair<int,int> > q;
	priority_queue<int, vector<int>, less<int> > pq;
	
	for(i=0; i<priorities.size(); i++){ 
	
		q.push(make_pair(i, priorities[i]));  // ť : �ε����� �켱������ pair�� �ִ´�.  
		pq.push(priorities[i]);  // �켱���� ť : �켱�������� �ִ´�.  
	}
	
	while(!q.empty()){
		
		int idx = q.front().first;
		int top_priority = q.front().second;
	
		q.pop();
		
		if(pq.top() == top_priority) {
			
			if(idx == location){ // Ÿ�� ã��. ����  
				answer++;
				break; 
				 
			}else{ // ��� 
				pq.pop(); 
				answer++;
			} 
			
		}else { // �� �ڷ� �ִ´�  
			q.push(make_pair(idx, top_priority));
		}
		
	} 
    
    return answer;
    
}

