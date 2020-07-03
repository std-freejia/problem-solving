#include "priorityQueue.h"

// 우선순위 큐 생성 
PriorityQueue* PQ_Create(int initialSize) {
	
	PriorityQueue* PQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	PQ->nodes = (PQNode*)malloc(sizeof(PQNode) * initialSize);
	PQ->capacity = initialSize;
	PQ->usedSize = 0;

	return PQ;
}

void PQ_Destory(PriorityQueue* PQ) {

	free(PQ->nodes);
	free(PQ);

	return;
}

// 삽입 
void PQ_Enqueue(PriorityQueue* PQ, PQNode newNode) {

	int currentPosition = PQ->usedSize;
	int parentPosition = PQ_GetParent(currentPosition);

	// 1. 용량 확인 
	if (PQ->usedSize == PQ->capacity) {

		if (PQ->capacity == 0) {
			PQ->capacity = 1;
		}

		PQ->capacity *= 2; // 용량 2배 증가
		PQ->nodes = (PQNode*)realloc(PQ->nodes, sizeof(PQNode) * PQ->capacity);
	}

	// 2. 삽입
	PQ->nodes[currentPosition] = newNode;

	// 3. '힙 순서 속성' 만족시킬 때 까지 후속처리
	while (currentPosition != 0 &&
		PQ->nodes[currentPosition].priority < PQ->nodes[parentPosition].priority) {

		PQ_SwapNodes(PQ, currentPosition, parentPosition); // 자신과 부모 위치 교환 

		currentPosition = parentPosition; // 인덱스 갱신 
		parentPosition = PQ_GetParent(currentPosition);
	}

	PQ->usedSize++;

	return;
}


// 최소값 삭제 
void PQ_Dequeue(PriorityQueue* PQ, PQNode* root) {

	int parentPosition = 0; // 루트노드 자리에서 시작한다. 
	int leftPosition = 0;
	int rightPosition = 0;

	// 1. 루트노드의 값을 root에 저장해둔다. 
	memcpy(root, &PQ->nodes[0], sizeof(PQNode));
	memset(&PQ->nodes[0], 0, sizeof(PQNode)); // 0으로 초기화 

	// 2. 최고 깊이 최우측 노드를 root 자리에 옮긴다. 
	PQ->usedSize--;
	PQ_SwapNodes(PQ, 0, PQ->usedSize);

	leftPosition = PQ_GetLeftChild(0); // 루트의 왼쪽 자식
	rightPosition = leftPosition + 1;  // 루튼의 오른쪽 자식

	// 3. 자신과 자신의 양쪽 자식을 비교 
	while (1) {
		
		int targetPosition = 0;

		// 비교할 자식을 고름 
		if (leftPosition >= PQ->usedSize) { // 자식 없음
			break;
		}
		else if (rightPosition >= PQ->usedSize) { // 왼쪽 자식만 존재 
			targetPosition = leftPosition;
		}
		else {
			// 양쪽 자식 존재 

			if (PQ->nodes[leftPosition].priority < PQ->nodes[rightPosition].priority) {
				targetPosition = leftPosition;
			}
			else {
				targetPosition = rightPosition;
			}

		}

		// 자신과 자식의 값 비교해서 교환 필요 여부 확인 
		if (PQ->nodes[targetPosition].priority < PQ->nodes[parentPosition].priority) {
			PQ_SwapNodes(PQ, targetPosition, parentPosition);
		}
		else {
			break; // 탈출 
		}

		// 인덱스 갱신 
		leftPosition = PQ_GetLeftChild(parentPosition);
		rightPosition = leftPosition + 1;
	}

	// 4. 힙 용량 관리

	if (PQ->usedSize < PQ->capacity / 2) {
		// 용량 감소 

		PQ->capacity /= 2; 
		PQ->nodes = (PQNode*)realloc(PQ->nodes, sizeof(PQNode) * PQ->capacity);
	}

	return;
}

// 노드 교환 
void PQ_SwapNodes(PriorityQueue* PQ, int index1, int index2) {

	int NodeSize = sizeof(PQNode);
	PQNode* tempNode = (PQNode*)malloc(NodeSize);

	memcpy(tempNode, &PQ->nodes[index1], NodeSize);
	memcpy(&PQ->nodes[index1], &PQ->nodes[index2], NodeSize);
	memcpy(&PQ->nodes[index2], tempNode, NodeSize);

	free(tempNode);
	return;
}

int PQ_GetParent(int index) { // 부모 노드 인덱스 반환 
	return (int)((index - 1) / 2);
}
int PQ_GetLeftChild(int index) { //왼쪽 자식 인덱스 반환 
	return (index * 2) + 1;
}

int PQ_IsEmpty(PriorityQueue* PQ) { // 비어서 사용량이 0인지 반환 
	return (0 == PQ->usedSize);
}
