#include "priorityQueue.h"

void PrintNode(PQNode* node) {
	printf("�۾���: %s (�켱����:%d)\n", (char*)node->data, node->priority);
}

int main(void) {

	// PQ�� ũ�⸦ �Է��Ͽ� �����Ѵ�. 
	PriorityQueue* PQ = PQ_Create(3);

	PQNode Popped;

	PQNode Nodes[7] = {
		{34, (void*)"�ڵ�"},
		{12, (void*)"������"},
		{87, (void*)"ȭ�й��ֱ�"},
		{45, (void*)"�����ۼ�"},
		{35, (void*)"�����"},
		{66, (void*)"�̴۱�"},
	};
	
	// ť�� �ִ´�. 
	PQ_Enqueue(PQ, Nodes[0]);
	PQ_Enqueue(PQ, Nodes[1]);
	PQ_Enqueue(PQ, Nodes[2]);
	PQ_Enqueue(PQ, Nodes[3]);
	PQ_Enqueue(PQ, Nodes[4]);
	PQ_Enqueue(PQ, Nodes[5]);

	printf("ť�� �����ִ� �۾� �� %d\n", PQ->usedSize);

	while (!PQ_IsEmpty(PQ)) {
		PQ_Dequeue(PQ, &Popped);
		PrintNode(&Popped);
	}

	return 0;
}