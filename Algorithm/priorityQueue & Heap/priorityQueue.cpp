#include "priorityQueue.h"

// �켱���� ť ���� 
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

// ���� 
void PQ_Enqueue(PriorityQueue* PQ, PQNode newNode) {

	int currentPosition = PQ->usedSize;
	int parentPosition = PQ_GetParent(currentPosition);

	// 1. �뷮 Ȯ�� 
	if (PQ->usedSize == PQ->capacity) {

		if (PQ->capacity == 0) {
			PQ->capacity = 1;
		}

		PQ->capacity *= 2; // �뷮 2�� ����
		PQ->nodes = (PQNode*)realloc(PQ->nodes, sizeof(PQNode) * PQ->capacity);
	}

	// 2. ����
	PQ->nodes[currentPosition] = newNode;

	// 3. '�� ���� �Ӽ�' ������ų �� ���� �ļ�ó��
	while (currentPosition != 0 &&
		PQ->nodes[currentPosition].priority < PQ->nodes[parentPosition].priority) {

		PQ_SwapNodes(PQ, currentPosition, parentPosition); // �ڽŰ� �θ� ��ġ ��ȯ 

		currentPosition = parentPosition; // �ε��� ���� 
		parentPosition = PQ_GetParent(currentPosition);
	}

	PQ->usedSize++;

	return;
}


// �ּҰ� ���� 
void PQ_Dequeue(PriorityQueue* PQ, PQNode* root) {

	int parentPosition = 0; // ��Ʈ��� �ڸ����� �����Ѵ�. 
	int leftPosition = 0;
	int rightPosition = 0;

	// 1. ��Ʈ����� ���� root�� �����صд�. 
	memcpy(root, &PQ->nodes[0], sizeof(PQNode));
	memset(&PQ->nodes[0], 0, sizeof(PQNode)); // 0���� �ʱ�ȭ 

	// 2. �ְ� ���� �ֿ��� ��带 root �ڸ��� �ű��. 
	PQ->usedSize--;
	PQ_SwapNodes(PQ, 0, PQ->usedSize);

	leftPosition = PQ_GetLeftChild(0); // ��Ʈ�� ���� �ڽ�
	rightPosition = leftPosition + 1;  // ��ư�� ������ �ڽ�

	// 3. �ڽŰ� �ڽ��� ���� �ڽ��� �� 
	while (1) {
		
		int targetPosition = 0;

		// ���� �ڽ��� �� 
		if (leftPosition >= PQ->usedSize) { // �ڽ� ����
			break;
		}
		else if (rightPosition >= PQ->usedSize) { // ���� �ڽĸ� ���� 
			targetPosition = leftPosition;
		}
		else {
			// ���� �ڽ� ���� 

			if (PQ->nodes[leftPosition].priority < PQ->nodes[rightPosition].priority) {
				targetPosition = leftPosition;
			}
			else {
				targetPosition = rightPosition;
			}

		}

		// �ڽŰ� �ڽ��� �� ���ؼ� ��ȯ �ʿ� ���� Ȯ�� 
		if (PQ->nodes[targetPosition].priority < PQ->nodes[parentPosition].priority) {
			PQ_SwapNodes(PQ, targetPosition, parentPosition);
		}
		else {
			break; // Ż�� 
		}

		// �ε��� ���� 
		leftPosition = PQ_GetLeftChild(parentPosition);
		rightPosition = leftPosition + 1;
	}

	// 4. �� �뷮 ����

	if (PQ->usedSize < PQ->capacity / 2) {
		// �뷮 ���� 

		PQ->capacity /= 2; 
		PQ->nodes = (PQNode*)realloc(PQ->nodes, sizeof(PQNode) * PQ->capacity);
	}

	return;
}

// ��� ��ȯ 
void PQ_SwapNodes(PriorityQueue* PQ, int index1, int index2) {

	int NodeSize = sizeof(PQNode);
	PQNode* tempNode = (PQNode*)malloc(NodeSize);

	memcpy(tempNode, &PQ->nodes[index1], NodeSize);
	memcpy(&PQ->nodes[index1], &PQ->nodes[index2], NodeSize);
	memcpy(&PQ->nodes[index2], tempNode, NodeSize);

	free(tempNode);
	return;
}

int PQ_GetParent(int index) { // �θ� ��� �ε��� ��ȯ 
	return (int)((index - 1) / 2);
}
int PQ_GetLeftChild(int index) { //���� �ڽ� �ε��� ��ȯ 
	return (index * 2) + 1;
}

int PQ_IsEmpty(PriorityQueue* PQ) { // �� ��뷮�� 0���� ��ȯ 
	return (0 == PQ->usedSize);
}
